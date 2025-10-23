#include "list.h"//Ë«ÏòÑ­»·Á´±í

void list_init(list_item *plist_head)
{
    plist_head->pxNext = plist_head;
    plist_head->pxPrevious = plist_head;
}

void list_add(list_item *pre_node,list_item *new_node,list_item *next_node)
{
   next_node->pxPrevious = new_node;
   new_node->pxNext = next_node;
   new_node->pxPrevious = pre_node;
   pre_node->pxNext = new_node;
}

void list_insert_head(list_item *list,list_item *node)
{
    list_add(list,node,list->pxNext);
}
void list_insert_tail(list_item *list,list_item *node)
{
    list_add(list->pxPrevious,node,list);
}
void list_remove(list_item *node)
{
    node->pxNext->pxPrevious = node->pxPrevious;
    node->pxPrevious->pxNext = node->pxNext;
    list_init(node);
} 
int list_isEmpty(list_item *list)
{
    return (list->pxNext == list);
}
unsigned int list_len(list_item *list)
{
    unsigned int len = 0;
    list_item *p = list;
    while(p->pxNext != list)
    {
        len++;
        p = p->pxNext;
    }
    return len;
}
void list_replace(list_item *old_node,list_item *new_node)
{
    new_node->pxNext = old_node->pxNext;
    new_node->pxNext->pxPrevious = new_node;
    new_node->pxPrevious = old_node->pxPrevious;
    new_node->pxPrevious->pxNext = new_node;
    list_init(old_node);
}
