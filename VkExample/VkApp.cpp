#include "VkApp.h"
#include <iostream>
#include <fstream>
VkApp::VkApp(void)
{
	vkServerAuth = new VkServerAuth(APP_ID, APP_SECURE_KEY);
	vkRequestSender = new VkRequestSender();
	connect(vkServerAuth, SIGNAL(authenticated()), this, SLOT(drawMenu()));
	QObject::connect(vkRequestSender, SIGNAL(replyIsReady(QString*)), SLOT(printReplyInfo(QString*)));
}


VkApp::~VkApp(void)
{
}


void VkApp::printReplyInfo(QString * data) {
	std::ofstream out("out.txt");
	out  << data->toStdString();
	out.close();
	drawMenu();
}

void VkApp::drawMenu() {
	std::cout << "\nAuth: OK\n";
	std::cout << "1.User\n";
	std::cout << "2.Exit\n";
	int choose;
	std::cin >> choose;
	switch (choose) {
	case 1: {
			vkRequestSender->sendRequest(VkUserRequest::makeUserRequestByConsole(), vkServerAuth->getAccessToken());		
			break;
			}
	case 2: {
				exit(0);
			}
	}
}