#ifndef NAVIGATIONACTIONPROVIDER_H
#define NAVIGATIONACTIONPROVIDER_H

#include <QObject>
#include <QString>

#include "NavigationActionTypes.h"
#include "lib/action.h"
#include "lib/dispatcher.h"
#include "store/NavigationStore.h"

class NavigationActionProvider final : public QObject
{
	Q_OBJECT

public:
	static NavigationActionProvider& instance() {
		static NavigationActionProvider self;
		return self;
	}

	Q_INVOKABLE static void setPage(const QString& page);
	Q_INVOKABLE static void closeCurrentPage();

private:
	NavigationActionProvider() = default;
	NavigationActionProvider(const NavigationActionProvider&) = delete;
	NavigationActionProvider(NavigationActionProvider&&) = delete;
	NavigationActionProvider& operator=(const NavigationActionProvider&) = delete;
	NavigationActionProvider& operator=(NavigationActionProvider&&) = delete;
	~NavigationActionProvider() override = default;
};

#endif // NAVIGATIONACTIONPROVIDER_H
