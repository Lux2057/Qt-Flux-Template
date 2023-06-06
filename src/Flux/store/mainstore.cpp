#include "store/mainstore.h"
#include "action/actiontypes.h"
#include "lib/action.h"


MainStore::MainStore() : _store(new MainStoreImpl) {}

MainStore::~MainStore() = default;

void MainStore::_processSetCounterAction(const QSharedPointer<flux_qt::Action>& action){
    const qint16 counter = action->getPayload<qint16>();

    if(_store->counter == counter)
        return;

    _store->counter = counter;

    emit counterChanged();
}

void MainStore::process(const QSharedPointer<flux_qt::Action>& action) {
    switch (action->getType<ActionType>()) {
    case ActionType::SetCounter:
        _processSetCounterAction(action);
        break;
	}
}

qint16 MainStore::getCounter() const{
    return _store->counter;
}
