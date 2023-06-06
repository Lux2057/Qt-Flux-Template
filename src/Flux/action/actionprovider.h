#ifndef QML_ACTION_PROVIDER_H
#define QML_ACTION_PROVIDER_H

#include <QObject>
#include <QString>

#include "action/actiontypes.h"
#include "lib/action.h"
#include "lib/dispatcher.h"

class ActionProvider final : public QObject
{
	Q_OBJECT

public:
	static ActionProvider& instance() {
		static ActionProvider self;
		return self;
	}	

    Q_INVOKABLE static void setCounter(const qint16& counter);

private:
	ActionProvider() = default;
	ActionProvider(const ActionProvider&) = delete;
	ActionProvider(ActionProvider&&) = delete;
	ActionProvider& operator=(const ActionProvider&) = delete;
	ActionProvider& operator=(ActionProvider&&) = delete;
	~ActionProvider() override = default;
};

#endif
