#ifndef QMLCONSTANTSADAPTER_H
#define QMLCONSTANTSADAPTER_H

#include <QObject>

#include "LANGUAGE_CODES.h"

class QmlConstantsProvider final : public QObject
{
	Q_OBJECT	

	Q_PROPERTY(QString ru_RU READ ru_RU CONSTANT)

	Q_PROPERTY(QString en_US READ en_US CONSTANT)

public:
	static QmlConstantsProvider& instance() {
		static QmlConstantsProvider self;
		return self;
	}	

	static QString ru_RU();
	static QString en_US();

private:
	QmlConstantsProvider() = default;
	QmlConstantsProvider(const QmlConstantsProvider&) = delete;
	QmlConstantsProvider(QmlConstantsProvider&&) = delete;
	QmlConstantsProvider& operator=(const QmlConstantsProvider&) = delete;
	QmlConstantsProvider& operator=(QmlConstantsProvider&&) = delete;
	~QmlConstantsProvider() override = default;
};

#endif // QMLCONSTANTSADAPTER_H
