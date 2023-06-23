#ifndef NAVIGATIONSTORE_H
#define NAVIGATIONSTORE_H

#include <QObject>
#include <QScopedPointer>
#include <QSharedPointer>

#include "NavigationStoreImpl.h"
#include "action/NavigationActionTypes.h"
#include "lib/action.h"
#include "lib/store.h"


class NavigationStore final : public QObject, public flux_qt::Store
{
	Q_OBJECT

	Q_PROPERTY(QVector<QString> pagesStack READ pagesStack NOTIFY pagesStackChanged)
	Q_PROPERTY(QString currentPage READ currentPage NOTIFY currentPageChanged)


public:
	static NavigationStore& instance() {
		static NavigationStore self;
		return self;
	}

	static QString UID() { return "NavigationStore"; }

	void process(const QSharedPointer<flux_qt::Action>& action) Q_DECL_OVERRIDE;

	QVector<QString> pagesStack() const;
	QString currentPage() const;

signals:
	void pagesStackChanged();
	void currentPageChanged();

private:
	NavigationStore();
	NavigationStore(const NavigationStore&) = delete;
	NavigationStore(NavigationStore&&) = delete;
	NavigationStore& operator=(const NavigationStore&) = delete;
	NavigationStore& operator=(NavigationStore&&) = delete;
	~NavigationStore() override;

	void _processSetCurrentPageAction(const QSharedPointer<flux_qt::Action>& action);
	void _processCloseCurrentPageAction(const QSharedPointer<flux_qt::Action>& action);

	QScopedPointer<NavigationStoreImpl> _store;
};

#endif // NAVIGATIONSTORE_H
