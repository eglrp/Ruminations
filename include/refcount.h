/*
 * refcount.h  引用计数
 *	lming_08@hotmail.com
 */
#ifndef _REFCOUNT_H_
#define _REFCOUNT_H_

class RefCount
{
public:
	RefCount() : use(new size_t(1)){}
	RefCount(const RefCount &refcnt) : use(refcnt.use)
	{
		inc();
	}
	~RefCount()
	{
		if (decr() == 0)
		{
			delete use;
		}
	}
	RefCount & operator=(const RefCount &refcnt)
	{
		if (decr() == 0)
		{
			delete use;
		}
		use = refcnt.use;
		inc();
		return *this;
	}

	void init()
	{
		use = new size_t(1);
	}

	bool only()
	{
		return *use == 1;
	}

	inline size_t inc()
	{
		return ++*use;
	}

	inline size_t decr()
	{
		return --*use;
	}

	bool reattach(const RefCount &refcnt)
	{
		++*refcnt.use;
		if (only())
		{
			delete use;
			use = refcnt.use;
			return true;
		}
		else
		{
			--*use;
			use = refcnt.use;
			return false;
		}
	}

private:
	size_t *use;
};

#endif  //  _REFCOUNT_H_
