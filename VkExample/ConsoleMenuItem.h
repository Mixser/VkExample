#pragma once

#include <QObject>
#include <iostream>

#include "IVkRequest.h"
#include "VkRequestSender.h"
class ConsoleMenuItem :	public QObject
{
	Q_OBJECT
	QString title;
	unsigned int number;
	VkRequestSender * sender;
	void ( *ptrAction)(VkRequestSender *);
public:

	ConsoleMenuItem(QString &, unsigned int number, VkRequestSender * sender, void ( *PtrAction)(VkRequestSender *));

	void select();
	~ConsoleMenuItem(void);
	friend std::ostream & operator << (std::ostream &, ConsoleMenuItem &);
};

