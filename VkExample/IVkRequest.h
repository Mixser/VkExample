#pragma once

#include <QtCore>
#include <iostream>
class IVkRequest
{

protected:
	bool xmlResult;
public:
// TODO: do smth
	IVkRequest(void);
	void setXml(bool);
	virtual QString getRequestUri() = 0;
	~IVkRequest(void);
};

