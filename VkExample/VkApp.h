#pragma once
#include <QtCore>
#include "VkServerAuth.h"
#include "VkRequestSender.h"

#include "VkUserRequest.h"

#include "ConsoleMenu.h"

#define APP_ID 2939839
#define APP_SECURE_KEY (QString("2kQbRkdVBZW0vT8dVjJM"))

class VkApp :
	public QObject
{
	Q_OBJECT
	ConsoleMenu * menu;
	VkServerAuth * vkServerAuth;
	VkRequestSender * vkRequestSender;

	void initMenu();

	public slots:
		void printReplyInfo(QString * data);

public:
	VkApp(void);
	~VkApp(void);


	friend void exitFromProgram(VkRequestSender *);
	friend void sendUserRequest(VkRequestSender * sender);
};

