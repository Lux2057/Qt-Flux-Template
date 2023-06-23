#ifndef MAINSTOREIMPL_H
#define MAINSTOREIMPL_H

#include <QObject>


class MainStoreImpl final
{
public:
	MainStoreImpl();
	MainStoreImpl(const MainStoreImpl&) = delete;
	MainStoreImpl(MainStoreImpl&&) = delete;
	MainStoreImpl& operator=(const MainStoreImpl&) = delete;
	MainStoreImpl& operator=(MainStoreImpl&&) = delete;
	~MainStoreImpl() = default;

	qint16 counter{ 0 };
};

#endif // MAINSTOREIMPL_H
