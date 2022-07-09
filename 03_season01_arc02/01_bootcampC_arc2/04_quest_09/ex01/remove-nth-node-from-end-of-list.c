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
 * @brief   Calculates the number of nodes in the given linked list
 * @param   head a pointer to the first element of the linked list
 * @return  the number of nodes in the given linked list
 */
int list_size(listnode* head);

/**
 * @brief   Removes the nth node from the end of a linked list.
 *          Doesn't delete if n is greater than linked list size or if n is
 *          negative.
 * @param   head a pointer to the first element of the linked list
 * @param   n_node n-th node from the end
 * @return  the linked list head
 */
listnode* remove_nth_node_from_end_of_list(listnode* head, int n_node);

int list_size(listnode* head) {
    int size = 0;
    listnode* cur = head;
    while (cur != NULL) {
        size++;
        cur = cur->next;
    }

    return size;
}


listnode* remove_nth_node_from_end_of_list(listnode* head, int n_node) {
    if (n_node <= 0 || n_node > list_size(head)) {
        return head;
    }
    
    int nth_from_start = list_size(head) - n_node;
    listnode* to_delete;
    if (nth_from_start == 0) {
        to_delete = head;
        head = head->next;
    }
    else {
        listnode* cur = head;
        int i = 1;
        while (i < nth_from_start) {
            cur = cur->next;
            i++;
        }
        to_delete = cur->next;
        cur->next = to_delete->next;
    }

    free (to_delete);

    return head;
}

// int main() {
//     listnode *l = (listnode*) malloc(sizeof(listnode));
//     l->val = 1;
//     l->next = (listnode*) malloc(sizeof(listnode));

//     l->next->val = 2;
//     l->next->next = (listnode*) malloc(sizeof(listnode));

//     l->next->next->val = 3;
//     l->next->next->next = NULL;

//     listnode* temp = l;

//     while(temp != NULL) {
//         printf("%d -> ", temp->val);
//         temp = temp->next;
//     }
//     printf("%s", "\n");

//     temp = remove_nth_node_from_end_of_list(l, 4);

//     while(temp != NULL) {
//         printf("%d -> ", temp->val);
//         temp = temp->next;
//     }
//     printf("%s", "\n");

    
//     return 0;
// }