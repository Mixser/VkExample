#include "VkRequestSender.h"


VkRequestSender::VkRequestSender(void)
{
	manager = new QNetworkAccessManager();
	semaphore = new QSemaphore(0);
	connect(manager, SIGNAL(finished(QNetworkReply *)), SLOT(getRequestResult(QNetworkReply *)));
}

void VkRequestSender::getRequestResult(QNetworkReply * reply) {
	if (reply->error() == QNetworkReply::NoError) {
		serverReply = QString(reply->readAll());
		emit replyIsReady(&serverReply);
		//qDebug() << serverReply;
	} else {
		qDebug() << reply->error();
		
	}
	reply->deleteLater();
}

void VkRequestSender::sendRequest(QString access_token) {
	QString url = "https://api.vk.com/method/getProfiles.xml?uid=66748%1";
	url = url.arg(access_token);
	QNetworkRequest req(url);
	manager->get(req);
}


void VkRequestSender::sendRequest(VkRequest * request, QString access_token) {
	QString url = request->getRequestUri() + "&" + access_token;

	QNetworkRequest req(url);
	manager->get(req);
}

void VkRequestSender::sendRequest(VkRequest * request, QString * access_token) {
	QString url = request->getRequestUri() + "&" + *access_token;

	QNetworkRequest req(url);
	manager->get(req);
}



QString VkRequestSender::getReply() {

	return serverReply;
}

VkRequestSender::~VkRequestSender(void)
{
	delete manager;
	manager = NULL;
}