#include <stdio.h>
#include <stdlib.h>

#ifndef STRUCT_LISTNODE
#define STRUCT_LISTNODE

typedef struct s_listnode
{
    int val;
    struct s_listnode* next;
} listnode;
#endif

///***************FUNCTIONS PROTOTYPES***********////

/**
 * @brief   Removes duplicates from the sorted linked list.
 * @param   head a pointer to the first element of the linked list
 * @return  the linked list head
 */
listnode* remove_duplicates_from_sorted_list(listnode* head); 

/**
 * @brief   Free the memory allocated for the linked list
 * @param   head a pointer to the first element of the linked list
 * @return  void
 */
void free_memory(listnode* head);

///***************FUNCTIONS IMPLEMENTATIONS***********////
listnode* remove_duplicates_from_sorted_list(listnode* head) { 
    listnode* cur = head;
    while(cur != NULL && cur->next != NULL) {
        if (cur->val == cur->next->val) {
            listnode* to_delete;
            if (cur == head) {
                to_delete = head;
                head = head->next;
                cur = head;
            }
            else {
                to_delete = cur->next;
                cur->next = cur->next->next;
            }
            free(to_delete);
        }
        else {
            cur = cur->next;
        }
    }

    return head;
}

void free_memory(listnode* head) {
    if (head == NULL) {
        return;
    }
    free_memory(head->next);
    free(head);
}

// int main() {
//     listnode *l = (listnode*) malloc(sizeof(listnode));
//     l->val = 1;
//     l->next = (listnode*) malloc(sizeof(listnode));

//     l->next->val = 1;
//     l->next->next = (listnode*) malloc(sizeof(listnode));

//     l->next->next->val = 4;
//     l->next->next->next = (listnode*) malloc(sizeof(listnode));

//     l->next->next->next->val = 4;
//     l->next->next->next->next = NULL;


//     listnode* temp = l;

//     while(temp != NULL) {
//         printf("%d -> ", temp->val);
//         temp = temp->next;
//     }
//     printf("%s", "\n");

//     temp = remove_duplicates_from_sorted_list(l);

//     while(temp != NULL) {
//         printf("%d -> ", temp->val);
//         temp = temp->next;
//     }
//     printf("%s", "\n");

//     free_memory(temp);

//     return 0;
// }