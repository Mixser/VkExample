#include "VkUserRequest.h"


VkUserRequest::VkUserRequest(void)
{
	xmlResult = false;
}


VkUserRequest::~VkUserRequest(void)
{

}


QString VkUserRequest::getRequestUri() 
{
	QString uri = "https://api.vk.com/method/users.get";
	if (xmlResult) {
		uri += ".xml?";
	} else {
		uri += "?";
	}
	
	if (users.isEmpty() == false) {
		uri+= "user_ids=";
		for (auto i = users.constBegin(); i!= users.constEnd(); i++) {
			uri += QString::number(*i);
			if (i + 1 != users.constEnd()) {
				uri += ", ";
			}

		}
	} else { 
		throw "You must choose user's id!!!!";
	}

	if (fields.isEmpty() == false)  {
		uri += "&fields=";
		for (auto i = fields.constBegin(); i != fields.constEnd(); i++) {
			uri+=*i;
			if (i + 1 != fields.constEnd())
				uri+=", ";
			}
	}
	
	return uri;
}

void VkUserRequest::addUser(unsigned int id) {
	users.insert(id);
}

void VkUserRequest::addFields(QString & field) {
	fields.insert(field);
}

VkRequest * VkUserRequest::makeUserRequestByConsole() {
	VkUserRequest * user = new VkUserRequest();
	int user_id = 0;
	std::cin >> user_id;
	user->addUser(user_id);
	int count_of_field;
	std::cin>>count_of_field;
	for (int i = 0; i < count_of_field; i++) {
		char line[256];
		std::cin >> line;
		user->addFields(QString(line));
	}
	return user;
}