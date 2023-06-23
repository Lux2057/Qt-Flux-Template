#include "NavigationActionProvider.h"


void NavigationActionProvider::setPage(const QString& page) {
	flux_qt::Dispatcher::instance().dispatch(new flux_qt::Action(NavigationStore::UID(), NavigationActionType::SetPage, page));
}

void NavigationActionProvider::closeCurrentPage() {
	flux_qt::Dispatcher::instance().dispatch(new flux_qt::Action(NavigationStore::UID(), NavigationActionType::CloseCurrentPage));
}
