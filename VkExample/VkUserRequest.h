#pragma once
#include "vkrequest.h"

class VkUserRequest : public VkRequest
{
private:
	QSet<QString> fields;
	QSet<int> users;

public:
	VkUserRequest(void);
	void addFields(QString & );
	void addUser(unsigned int id);
	static VkRequest * makeUserRequestByConsole();
	QString getRequestUri();
	~VkUserRequest(void);
};

