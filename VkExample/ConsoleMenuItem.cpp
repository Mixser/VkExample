#include "ConsoleMenuItem.h"



ConsoleMenuItem::ConsoleMenuItem(QString & title, unsigned int number,VkRequestSender * sender, void ( *ptrAction)(VkRequestSender *))
{
	this->title = title;
	this->number = number;
	this->sender = sender;
	this->ptrAction = ptrAction;
}


std::ostream & operator << (std::ostream & out, ConsoleMenuItem & menuItem) {
	out << menuItem.number << ". "<< menuItem.title.toStdString() << std::endl;
	return out;
}

void ConsoleMenuItem::select() {
	if (ptrAction != nullptr)
		ptrAction(sender);
}






ConsoleMenuItem::~ConsoleMenuItem(void)
{

}
