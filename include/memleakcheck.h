/*
 * memleakcheck.h  VS环境下的内存泄漏检测工具
 *	lming_08@hotmail.com
 */
#ifndef _MEMLEAKCHECK_H_
#define _MEMLEAKCHECK_H_

#ifdef _DEBUG
#define New   New(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif

#define CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h>  
//在入口函数中包含 _CrtDumpMemoryLeaks();  
//即可检测到内存泄露

#endif  //  _MEMLEAKCHECK_H_
