#include "action/actionprovider.h"

void ActionProvider::setCounter(const qint16& counter){
    flux_qt::Dispatcher::instance().dispatch(new flux_qt::Action(ActionType::SetCounter, counter));
}
