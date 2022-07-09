#ifndef STRUCT_LISTNODE
#define STRUCT_LISTNODE
#include <stdio.h>

typedef struct s_listnode
{
    int val;
    struct s_listnode* next;
} listnode;
#endif


listnode* reverse_linked_list(listnode* list) {
    if (list == NULL) {
        return list;
    }
    listnode* prev = NULL;    
    listnode* next = NULL;
    while (list != NULL) {
        next = list->next;
        list->next = prev;
        prev = list;
        list = next;
    }
    
    return prev;
}