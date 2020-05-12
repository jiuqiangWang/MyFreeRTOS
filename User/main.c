/*
*******************************************************************
include head file
*******************************************************************
*/

#include "list.h"

/*
*******************************************************************
Global Variable
*******************************************************************
*/

struct xLIST    List_Test;

struct xLIST_ITEM  List_Item1;
struct xLIST_ITEM  List_Item2;
struct xLIST_ITEM  List_Item3;

int main(void)
{
	/* 链表根节点初始化 */
	vListInitialise( &List_Test );
	
	/* 节点1初始化 */
	vListInitialise( &List_Item1 );
	List_Item.xItemValue = 1;
	
	/* 节点2初始化 */
	vListInitialise( &List_Item2 );
	List_Item.xItemValue = 2;
	
	/* 节点3初始化 */
	vListInitialise( &List_Item3 );
	List_Item.xItemValue = 3;
	
	/* 将节点插入链表，按照升序排列 */
	vListInsert( &List_Test, &List_Item2 );
	vListInsert( &List_Test, &List_Item1 );
	vListInsert( &List_Test, &List_Item3 );
	
	for (;;)
	{
		/* 啥事儿也不干 */	
	}
}
