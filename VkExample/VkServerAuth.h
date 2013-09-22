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
signals:
	void authenticated();
private slots:
	void getReply(QNetworkReply *);

public:
	VkServerAuth(int, QString &);
	QString getAccessToken();
	~VkServerAuth(void);
};

