#pragma once
#include <QtCore>

#include <QtNetwork>
#include "VkRequest.h"
class VkRequestSender : public QObject
{
	Q_OBJECT
private:
	QNetworkAccessManager * manager;
	QString serverReply;
	QSemaphore * semaphore;

private slots:
	void getRequestResult(QNetworkReply *);
public slots:
	void sendRequest(VkRequest *, QString * access_token);

signals: 
	void replyIsReady(QString * data);
public:
	VkRequestSender(void);
	void sendRequest(QString access_token);
	void sendRequest(VkRequest *, QString access_token);
	QString getReply();
	~VkRequestSender(void);
};

