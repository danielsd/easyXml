#include "exception.h"
#include <iostream>
#include <cmath>
#include <stdio.h>

namespace EASYXML_NAMESPACE
{
	EasyXmlException::EasyXmlException(const std::string msg, int code, int line) : message(msg), errorCode(code), lineNumber(line)
	{ }

	EasyXmlException::~EasyXmlException() throw ()
	{ }

	const char* EasyXmlException::what() const throw()
	{
		if (lineNumber > 0)
		{
			char* buf = new char[message.length() + static_cast<int>(log10(lineNumber)) + 1];
			sprintf(buf, message.c_str(), lineNumber);
			return buf;
		}
		else
		{
			return message.c_str();
		}
	}
}
