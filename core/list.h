#ifndef __LIST_H
#define __LIST_H


typedef struct xLIST_ITEM
{
   struct xLIST_ITEM * pxNext;
   struct xLIST_ITEM * pxPrevious;
}list_item;

void list_init(list_item *plist_head);
void list_add(list_item *pre_node,list_item *new_node,list_item *next_node);
void list_insert_head(list_item *list,list_item *node);
void list_insert_tail(list_item *list,list_item *node);
void list_remove(list_item *node);
int list_isEmpty(list_item *list);
unsigned int list_len(list_item *list);
void list_replace(list_item *old_node,list_item *new_node);




#endif /*__LIST_H*/




