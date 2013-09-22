
#pragma once

#include <QObject>
#include <QList>

#include "ConsoleMenuItem.h"
#include "IVkRequest.h"
#include "VkRequestSender.h"
#include "VkUserRequest.h"
class ConsoleMenu : public QObject
{
	Q_OBJECT
	QList<ConsoleMenuItem *> menuItems;
	VkRequestSender * sender;
	void chooseMenuItem();

	

signals:
	void selected(IVkRequest *);
	
public:
	ConsoleMenu(VkRequestSender *);

	void addMenuItem(QString & title, void ( *PtrAction)(VkRequestSender *));

	~ConsoleMenu(void);
public slots:
	void print();

};

