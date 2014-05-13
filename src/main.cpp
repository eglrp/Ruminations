/*
 * main.cpp  测试程序
 *	lming_08@hotmail.com
 */
#include "memleakcheck.h"
#include "smartpointer.h"
#include <iostream>
#include <string>
#include <boost/shared_ptr.hpp>

int main(void)
{
	{
		SmartPtr<int> sp(2);
		SmartPtr<int> sp2(sp);
		SmartPtr<int> sp3(3);
		sp = sp3;
		sp2 = sp3;
	}	

	{
		SmartPtr<std::string> sp("123");
		SmartPtr<std::string> sp2(sp);
		SmartPtr<std::string> sp3("abc");
		sp = sp3;
		sp2 = sp3;
	}	

	{
		SmartPtr<std::string> sp(new std::string("123"));
		SmartPtr<std::string> sp2(sp);
		SmartPtr<std::string> sp3(new std::string("abc"));
		sp = sp3;
		sp2 = sp3;
	}	

	{
		boost::shared_ptr<char> pch(new char[10]);
	}
	_CrtDumpMemoryLeaks();

	return 0;
}
