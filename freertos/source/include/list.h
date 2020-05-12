#include "portmacro.h"

struct xLIST_ITEM
{
	  TickType_t  xItemValue;               /* 辅助值，用于帮助节点进行顺序排序 */
		struct      xLIST_ITEM  * pxNext;     /* 指向链表下一个节点 */
	  struct      xLIST_ITEM  * pxPrevious; /* 指向链表上一个节点 */
	  void  * pvOwner;                      /* 指向拥有该节点的内核对象，通常是TCB */
	  void  * pvContainer;                  /* 指向该节点所在的链表 */
};
typedef struct xLIST_ITEM ListItem_t;     /* 节点数据类型重定义 */

