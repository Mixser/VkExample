#include "VkApp.h"
#include <iostream>

VkApp::VkApp(void)
{
	vkServerAuth = new VkServerAuth(APP_ID, APP_SECURE_KEY);
	vkRequestSender = new VkRequestSender();
	menu = new ConsoleMenu(vkRequestSender);
	initMenu();
	connect(vkServerAuth, SIGNAL(authenticated(QString &)), menu, SLOT(print()));
	connect(vkServerAuth, SIGNAL(authenticated(QString &)), vkRequestSender, SLOT(setAccessToken(QString &)));
	connect(vkRequestSender, SIGNAL(replyIsReady(QString*)), SLOT(printReplyInfo(QString*)));
}


void VkApp::initMenu() {
	menu->addMenuItem(QString("Send user(s) request"), (sendUserRequest)); 
	menu->addMenuItem(QString("Exit"), (exitFromProgram));

}


void VkApp::printReplyInfo(QString * data) {
	std::cout << data->toStdString() << std::endl;
	menu->print();	
}

VkApp::~VkApp(void)
{
	delete vkServerAuth;
	delete vkRequestSender;
	vkServerAuth = nullptr;
	vkRequestSender = nullptr;
}

void sendUserRequest(VkRequestSender * sender) {
	IVkRequest * userRequest = VkUserRequest::makeUserRequestByConsole();
	sender->sendRequest(userRequest);
	delete userRequest;
}

void exitFromProgram(VkRequestSender *) {
	QCoreApplication::exit(0);
}