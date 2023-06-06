#ifndef QML_MAIN_STORE_H
#define QML_MAIN_STORE_H

#include <QObject>
#include <QScopedPointer>
#include <QSharedPointer>

#include "MainStoreImpl.h"
#include "lib/action.h"
#include "lib/store.h"


class MainStore final : public QObject, public flux_qt::Store
{
	Q_OBJECT	

    Q_PROPERTY(qint16 counter READ getCounter NOTIFY counterChanged)

public:
	static MainStore& instance() {
		static MainStore self;
		return self;
	}

    void process(const QSharedPointer<flux_qt::Action>& action) Q_DECL_OVERRIDE;

    qint16 getCounter() const;

signals:
    void counterChanged();

private:
	MainStore();
	MainStore(const MainStore&) = delete;
	MainStore(MainStore&&) = delete;
	MainStore& operator=(const MainStore&) = delete;
	MainStore& operator=(MainStore&&) = delete;
	~MainStore() override;	

	QScopedPointer<MainStoreImpl> _store;

    void _processSetCounterAction(const QSharedPointer<flux_qt::Action>& action);
};

#endif
