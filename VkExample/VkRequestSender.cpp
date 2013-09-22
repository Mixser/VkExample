#include "VkRequestSender.h"

VkRequestSender::VkRequestSender()
{
	manager = new QNetworkAccessManager();
	
	connect(manager, SIGNAL(finished(QNetworkReply *)), SLOT(getRequestResult(QNetworkReply *)));
}

void VkRequestSender::setAccessToken(QString & access_token) {
	this->access_token = access_token;
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




void VkRequestSender::sendRequest(IVkRequest * request) {
	QString url = request->getRequestUri() + "&" + this->access_token;

	QNetworkRequest req(url);
	manager->get(req);
}


VkRequestSender::~VkRequestSender(void)
{
	delete manager;
	manager = NULL;
}