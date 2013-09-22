
#include <QtCore/QCoreApplication>

#include "VkServerAuth.h"
#include "VkRequestSender.h"

#include "VkUserRequest.h"
#include "VkApp.h"
#include <iostream>
#include <fstream>

int main(int argc, char *argv[])
{
	setlocale(LC_ALL,"Russian");
	
	qDebug() << "start\n";
	QCoreApplication a(argc, argv);
	
	VkApp app;
	
	return a.exec();
}
