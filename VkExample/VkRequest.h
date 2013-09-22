#pragma once
#include <QtCore>
#include <iostream>
class VkRequest
{

protected:
	bool xmlResult;
public:
	VkRequest(void);
	void setXml(bool);
	virtual QString getRequestUri() = 0;
	~VkRequest(void);
};

