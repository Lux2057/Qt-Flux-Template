#ifndef FRAMESHANDLINGSURFACE_H
#define FRAMESHANDLINGSURFACE_H

#include <QObject>

class ExampleControl : public QObject
{
	Q_OBJECT
	Q_PROPERTY(QString text READ text WRITE setText NOTIFY textChanged)

public:
	explicit ExampleControl(QObject* parent = nullptr);

	QString text() const;
	void setText(const QString& text);

signals:
	void textChanged();

private:
	QString _text{ "" };
};
#endif // FRAMESHANDLINGSURFACE_H
