#pragma once
#include <QtCore>
#include "VkServerAuth.h"
#include "VkRequestSender.h"

#include "VkUserRequest.h"

#define APP_ID 2939839
#define APP_SECURE_KEY (QString("2kQbRkdVBZW0vT8dVjJM"))

class VkApp :
	public QObject
{
	Q_OBJECT
	VkServerAuth * vkServerAuth;
	VkRequestSender * vkRequestSender;
	public slots:
		void printReplyInfo(QString * data);
		void drawMenu();
public:
	VkApp(void);
	~VkApp(void);
};

