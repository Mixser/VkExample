#include "VkServerAuth.h"

#include <iostream>
QString VkServerAuth::serverAuthUrl = "https://oauth.vk.com/access_token?client_id=%1&client_secret=%2&v=5.0&grant_type=client_credentials";

VkServerAuth::VkServerAuth(int APP_ID, QString & SECURE_CODE)
{
	manager = new QNetworkAccessManager();
	QNetworkRequest request(serverAuthUrl.arg(APP_ID).arg(SECURE_CODE));
	connect(manager, SIGNAL(finished(QNetworkReply *)), SLOT(getReply(QNetworkReply *)));
	QNetworkReply * reply = manager->get(request);
	semaphore = new QSemaphore(0);
	
}


void VkServerAuth::getReply(QNetworkReply * reply) {
	if (reply->error() == QNetworkReply::NoError) {
		QRegExp req("\"access_token\":\"([^\"]*)");
		QString replyBody = reply->readAll();
		if (req.indexIn(replyBody, 0) != -1) {
		//	semaphore->release();
			this->access_token = req.cap(1);
			emit authenticated();
		//	qDebug() << this->access_token;
		}

	} else { 
		std::cout << reply->error();
	}
	reply->deleteLater();
}

QString VkServerAuth::getAccessToken() {

	return access_token;
}

VkServerAuth::~VkServerAuth(void)
{
	access_token = "";
	manager->deleteLater();
	manager = NULL;
}
