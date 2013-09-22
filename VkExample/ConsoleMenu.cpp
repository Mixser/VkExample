#include "ConsoleMenu.h"


ConsoleMenu::ConsoleMenu(VkRequestSender * sender)
{
	this->sender = sender;
}

void ConsoleMenu::addMenuItem(QString & title, void (*PtrAction)(VkRequestSender *)) {
	ConsoleMenuItem * newItem = new ConsoleMenuItem(title,menuItems.count() + 1,sender, PtrAction);
	
	this->menuItems.push_back(newItem);
}



void ConsoleMenu::print() {
	std::cout << "------MENU------" << std::endl;
	for (auto i = menuItems.constBegin(); i != menuItems.constEnd(); i++) {
		std::cout << *(*i);
	}
	std::cout << "----------------" << std::endl;
	chooseMenuItem();
}

void ConsoleMenu::chooseMenuItem() {
	int choose = 0;
	while (choose < 1 || choose > menuItems.count() + 1) {
		std::cin >> choose;
	} 
	menuItems.at(choose-1)->select();
}




ConsoleMenu::~ConsoleMenu(void)
{
	for (int i = 0; i < menuItems.size(); i++) {
		delete menuItems[i];
		menuItems[i] = NULL;
	}
	menuItems.clear();
}

