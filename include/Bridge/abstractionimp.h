/*
 *  filename: 	abstractionimp.h
 *	created:	2014:5:15 14:09
 *	email:  lming_08@hotmail.com
 */
#ifndef _ABSTRACTIONIMP_H_
#define _ABSTRACTIONIMP_H_
#include <boost/shared_ptr.hpp>

class AbstractionImp
{
public:
	virtual ~AbstractionImp(){}
	virtual void operate() = 0;
protected:
	AbstractionImp(){}
};

class ConcreteAbstractionImpA : public AbstractionImp
{
public:
	virtual ~ConcreteAbstractionImpA(){}
	ConcreteAbstractionImpA(){}

	virtual void operate()
	{
		std::cout<<"ConcreteAbstractionImpA::operate()"<<std::endl;
	}
};

#endif  //  _ABSTRACTIONIMP_H_
