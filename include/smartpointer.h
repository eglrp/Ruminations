/*
 * 智能指针
 *	lming_08@hotmail.com
 */
#ifndef _SMARTPOINTER_H_
#define _SMARTPOINTER_H_

#include "refcount.h"

template <typename T>
class SmartPtr
{
public:
	SmartPtr() : ptr_(new T)
	{
		refcnt_.init();
	}

	SmartPtr(const T & obj) : ptr_(new T(obj)){}
	
	SmartPtr(T * pobj) : ptr_(pobj)
	{
		//refcnt_初始化时，*use = 1
		if (pobj == nullptr)
		{
			refcnt_.decr();
		}		
	}

	SmartPtr(const SmartPtr &spnt) : ptr_(spnt.ptr_), refcnt_(spnt.refcnt_){	}

	~SmartPtr()
	{
		if (refcnt_.only())
		{
			delete ptr_;
			ptr_ = nullptr;
		}		
	}

	SmartPtr & operator=(const SmartPtr &spnt)
	{
		//这一步相当于对refcnt_进行赋值
		if (refcnt_.reattach(spnt.refcnt_))
		{
			delete ptr_;
		}
		ptr_ = spnt.ptr_;
		return *this;
	}

	T * operator->()
	{
		return ptr_;
	}

private:
	T * ptr_;
	RefCount refcnt_;
};

#endif  //  _SMARTPOINTER_H_
