/*
 *  filename: 	abstraction.h
 *	created:	2014:5:15 13:56
 *	email:  lming_08@hotmail.com
 */
#ifndef _ABSTRACTION_H_
#define _ABSTRACTION_H_
#include <boost/shared_ptr.hpp>

class AbstractionImp;
typedef boost::shared_ptr<AbstractionImp> AbstractionImpPtr;

class Abstraction
{
public:
	virtual ~Abstraction();
	virtual void operate() = 0;
protected:
	Abstraction()	;
};
typedef boost::shared_ptr<Abstraction> AbstractionPtr;

class RefinedAbstraction : public Abstraction
{
public:
	RefinedAbstraction(AbstractionImpPtr abs_imp);
	virtual ~RefinedAbstraction();
	virtual void operate();
private:
	AbstractionImpPtr abs_imp_;
};
#endif  //  _ABSTRACTION_H_
