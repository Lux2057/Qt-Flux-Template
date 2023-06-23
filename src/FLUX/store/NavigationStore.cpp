#include "NavigationStore.h"


NavigationStore::NavigationStore() : _store(new NavigationStoreImpl) {}

NavigationStore::~NavigationStore() = default;

void NavigationStore::process(const QSharedPointer<flux_qt::Action>& action) {
	if (action->storeUID() != UID())
		return;

	switch (action->getType<NavigationActionType>()) {
		case NavigationActionType::SetPage:
			_processSetCurrentPageAction(action);
			break;

		case NavigationActionType::CloseCurrentPage:
			_processCloseCurrentPageAction(action);
			break;
	}
}

QVector<QString> NavigationStore::pagesStack() const {
	return _store->pagesStack;
}

QString NavigationStore::currentPage() const {
	return _store->currentPage;
}


void NavigationStore::_processSetCurrentPageAction(const QSharedPointer<flux_qt::Action>& action) {
	const auto currentPage = action->getPayload<QString>();

	if (_store->currentPage == currentPage)
		return;

	_store->currentPage = currentPage;

	auto stackHasChanged = false;

	if (!_store->pagesStack.contains(currentPage)) {
		_store->pagesStack.append(currentPage);
		stackHasChanged = true;
	}
	else {
		const int currentNavigationIndex = _store->pagesStack.indexOf(currentPage);
		const int lastNavigationIndex = _store->pagesStack.length() - 1;

		if (currentNavigationIndex != lastNavigationIndex) {
			const int removeCount = lastNavigationIndex - currentNavigationIndex;

			_store->pagesStack.remove(currentNavigationIndex + 1, removeCount);
			stackHasChanged = true;
		}
	}

	emit currentPageChanged();

	if (!stackHasChanged)
		return;

	emit pagesStackChanged();
}

void NavigationStore::_processCloseCurrentPageAction(const QSharedPointer<flux_qt::Action>& action) {
	const auto currentIndex = _store->pagesStack.indexOf(_store->currentPage);
	const auto lastIndex = _store->pagesStack.length() - 1;
	const auto removeCount = currentIndex == lastIndex ? 1 : lastIndex - currentIndex;

	_store->pagesStack.remove(currentIndex, removeCount);

	_store->currentPage = _store->pagesStack.last();

	emit currentPageChanged();
	emit pagesStackChanged();
}
