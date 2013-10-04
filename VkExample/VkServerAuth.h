#pragma once
#include <QtCore>
#include <QtNetwork>

class VkServerAuth : public QObject
{
	Q_OBJECT
private:
	static QString serverAuthUrl;
	QString access_token;
	QNetworkAccessManager * manager;
	QSemaphore * semaphore;
	//TODO: do smth @mixser
signals:
	void authenticated(QString & access_token);
private slots:
	void getReply(QNetworkReply *);

public:
	VkServerAuth(int, QString &);
	QString getAccessToken();
	~VkServerAuth(void);
};

