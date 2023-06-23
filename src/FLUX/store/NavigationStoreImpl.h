#ifndef NAVIGATIONSTOREIMPL_H
#define NAVIGATIONSTOREIMPL_H

#include <QObject>


class NavigationStoreImpl final
{
public:
	NavigationStoreImpl();
	NavigationStoreImpl(const NavigationStoreImpl&) = delete;
	NavigationStoreImpl(NavigationStoreImpl&&) = delete;
	NavigationStoreImpl& operator=(const NavigationStoreImpl&) = delete;
	NavigationStoreImpl& operator=(NavigationStoreImpl&&) = delete;
	~NavigationStoreImpl() = default;

	QString currentPage{ "" };
	QVector<QString> pagesStack{ QVector<QString>() };
};

#endif // NAVIGATIONSTOREIMPL_H
