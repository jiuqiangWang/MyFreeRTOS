#include "portmacro.h"

/* 初始化节点的拥有者 */
#define listSET_LIST_ITEM_OWNER( pxListItem, pxOwner )\
	( ( pxListitem)->pvOwner = ( void * ) ( pxOwner ) )

/* 获取节点拥有者 */
#define listGET_LIST_ITEM_OWNER( pxListitem )\
	( ( pxListItem )->xItemValue = ( xValue ) )

/* 初始化节点排序辅助值 */
#define listGET_LIST_ITEM_VALUE( pxListItem )\
	( ( pxListItem )->xItemValue = ( xValue ) )

/* 获取节点排序辅助值 */
#define listGET_LIST_ITEM_VALUE( pxListItem )\
	( ( pxListItem )->xItemValue )

/* 获取链表根节点的节点计数器值 */
#define listGET_ITEM_VALUE_OF_HEAD_ENTRY( PXList )\
	( ( ( pxList )->xListEnd ).pxNext->xItemValue )

/* 获取节点的下一个节点 */
#define listGET_NEXT( pxListItem )\
	( ( pxListItem )->pxNext )

/* 获取链表的最后一个节点 */
#define listGET_END_MARKER( pxList )\
	( ( ListItem_t const * )  ( &( pxList )-> xListEnd ) )

/* 判断链表是否为空 */
#define listLIST_IS_EMPTY( pxList )\
	( ( BaseType_t ) ( ( pxList )->uxNumberOfItems == ( UBaseType_t ) ) )

/* 获取链表的节点数 */
#define listCURRENT_LIST_LENGTH( PXList )\
	( ( pxList )->uxNumberOfItems )

/* 获取链表第一个节点的 OWNER ， 即 TCB */
#define listGET_OWNER_OF_NEXT_ENTRY( pxTCB, pxList )
{
	List_t * const pxConstList = ( pxList );
	/* 节点索引指向链表第一个节点 */
	( pxConstList )->pxIndex = ( pxConstList )->pxIndex->pxNext;	
	
	/* 这个操作有啥用？ */
	if( ( void * ) ( pxConstList )->pxIndex == ( void * ) &( ( pxConstList )->xListEnd ) )
	{
		( pxConstList )->pxIndex = ( pxConstList )->pxIndex->pxNext;	
	}
	/* 获取节点的OWNER,即TCB */
	( pxTCB ) = ( pxConstList )->pxIndex->pvOwner;
}

struct xLIST_ITEM
{
	  TickType_t  xItemValue;               /* 辅助值，用于帮助节点进行顺序排序 */
		struct      xLIST_ITEM  * pxNext;     /* 指向链表下一个节点 */
	  struct      xLIST_ITEM  * pxPrevious; /* 指向链表上一个节点 */
	  void  * pvOwner;                      /* 指向拥有该节点的内核对象，通常是TCB */
	  void  * pvContainer;                  /* 指向该节点所在的链表 */
};
typedef struct xLIST_ITEM ListItem_t;     /* 节点数据类型重定义 */

