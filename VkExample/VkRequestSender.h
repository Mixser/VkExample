#pragma once
#include <QtCore>

#include <QtNetwork>
#include "IVkRequest.h"
class VkRequestSender : public QObject
{
	Q_OBJECT
private:
	QNetworkAccessManager * manager;
	QString serverReply;
	QString access_token;
private slots:
	void getRequestResult(QNetworkReply *);
public slots:
	void sendRequest(IVkRequest *);
	void setAccessToken(QString & access_token);
signals: 
	void replyIsReady(QString * data);
public:
	VkRequestSender();
	

	~VkRequestSender(void);
};

