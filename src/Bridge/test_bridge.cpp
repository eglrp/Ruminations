/*
 *  filename: 	test_bridge.cpp
 *	created:	2014:5:19 10:16
 *	email:  lming_08@hotmail.com
 */
#include "Bridge/abstraction.h"
#include "Bridge/abstractionimp.h"

void test_bridge()
{
	AbstractionImpPtr abstr_imp(new ConcreteAbstractionImpA());
	AbstractionPtr  abstr(new RefinedAbstraction(abstr_imp));
	abstr->operate();
}
