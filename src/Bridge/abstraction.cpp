/*
 *  filename: 	abstraction.cpp
 *	created:	2014:5:15 14:09
 *	email:  lming_08@hotmail.com
 */
#include "Bridge/abstraction.h"
#include "Bridge/abstractionimp.h"

Abstraction::Abstraction()
{

}

Abstraction::~Abstraction()
{

}

RefinedAbstraction::RefinedAbstraction(AbstractionImpPtr abs_imp)
{
	abs_imp_ = abs_imp;
}

RefinedAbstraction::~RefinedAbstraction()
{

}

void RefinedAbstraction::operate()
{
	abs_imp_->operate();
}
