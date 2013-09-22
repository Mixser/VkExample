#pragma once
#include "ivkrequest.h"

class VkUserRequest : public IVkRequest
{
private:
	QSet<QString> fields;
	QSet<int> users;

public:
	VkUserRequest(void);
	void addFields(QString & );
	void addUser(unsigned int id);
	static IVkRequest * makeUserRequestByConsole();
	QString getRequestUri();
	~VkUserRequest(void);
};

