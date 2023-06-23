#include "ExampleControl.h"


ExampleControl::ExampleControl(QObject* parent): QObject(parent) {}

QString ExampleControl::text() const {
	return _text;
}

void ExampleControl::setText(const QString& text) {
	if (_text == text)
		return;

	_text = text;

	emit textChanged();
}
