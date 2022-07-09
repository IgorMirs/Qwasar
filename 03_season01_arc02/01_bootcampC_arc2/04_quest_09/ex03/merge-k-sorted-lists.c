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

#ifndef STRUCT_LISTNODE_ARRAY
#define STRUCT_LISTNODE_ARRAY
typedef struct s_listnode_array
{
    int size;
    listnode **array;
} listnode_array;
#endif

////****FUNCTION PROTOTYPES****////

/**
 * @brief   Merge k sorted linked lists and return it as one sorted list.
 * @param   list_array an array of linked lists
 * @return  a pointer to a merged linked list
 */
listnode* merge_k_sorted_lists(listnode_array* list_array);


/**
 * @brief   Free the memory allocated for the linked list
 * @param   head a pointer to the first element of the linked list
 * @return  void
 */
void free_listnode(listnode* head);

/**
 * @brief   Sort the values of the nodes in the linked list
 *          in the ascending order.
 * @param   head a pointer to the first node of the linked list
 * @param   size the total number of the linked list in the array
 * @return  void
 */
void bubble_sort(listnode* head, int size);

/**
 * @brief   Swaps the values in two given linked list nodes
 * @param   n1 a pointer to the first node of the linked list
 * @param   n2 a pointer to the second node of the linked list
 * @return  void
 */
void swap_nodes(listnode* n1, listnode* n2);

/**
 * @brief   Prints the given linked list
 * @param   head a pointer to the first node of the linked list
 * @return  void
 */
void print_list(listnode* head);

////****FUNCTION IMPLEMENTATIONS****////

listnode* merge_k_sorted_lists(listnode_array* list_array) {
    if (list_array->size == 0) {
        return NULL;
    }
    int total_nodes = 0;
    
    //skip all the empty lists at the beginning
    int i = 0;
    while (list_array->array[i] == NULL) {
        if (i == list_array->size) { 
            //all lists are empty
            return NULL;
        }
        i++;
    }
    listnode* head = list_array->array[i];
    //connect all the linked lists together
    for(; i < list_array->size; i++) {
        listnode* temp = list_array->array[i];
        if (temp != NULL) {
            total_nodes++; //count the first node 
        }
        while (temp != NULL && temp->next != NULL) {
            temp = temp->next;
            total_nodes++;
        }
        if (i != list_array->size - 1) {
            while(list_array->array[i + 1] == NULL) {
                if (i == list_array->size - 1) {
                    temp->next = NULL; //if all the remaining lists are empty
                    return head;
                }
                i++;
            }
            temp->next = list_array->array[i + 1];
        }
        else {
            temp->next = NULL;
        }
    }

    //sort teh overall linked list
    bubble_sort(head, total_nodes);

    return head;
}

void swap_nodes(listnode* n1, listnode* n2) {
    int temp = n1->val;
    n1->val = n2->val;
    n2->val = temp;
}

void print_list(listnode* head) {
    listnode* temp = head;
    while(temp != NULL) {
        printf((temp->next != NULL) ? "%d -> " : "%d", temp->val);
        temp = temp->next;
    }
    printf("%s", "\n");
}

void free_listnode(listnode* head) {
    if (head == NULL) {
        return;
    }
    free_listnode(head->next);
    free(head);
}

void bubble_sort(listnode* head, int size) {
    if (head == NULL || head->next == NULL) {
        return;
    }

    int wall = 0;
    for(int k = 0; k < size - wall; k++) {
        listnode* left = head;
        listnode* right = head->next;
        while(right != NULL) {
            if (left->val > right->val) {
                swap_nodes(left, right);
            }
            left = left->next;
            right = right->next;
        }
        wall++;
    }
}

// int main() {
//     // listnode *l = (listnode*) malloc(sizeof(listnode));
//     // l->val = 1;
//     // l->next = (listnode*) malloc(sizeof(listnode));

//     // l->next->val = 4;
//     // l->next->next = (listnode*) malloc(sizeof(listnode));

//     // l->next->next->val = 5;
//     // l->next->next->next = NULL;

//     listnode* l = NULL;

//     listnode *l2 = (listnode*) malloc(sizeof(listnode));
//     l2->val = 1;
//     l2->next = NULL;

//     // l2->next->val = 3;
//     // l2->next->next = (listnode*) malloc(sizeof(listnode));

//     // l2->next->next->val = 4;
//     // l2->next->next->next = NULL;

//     // listnode *l3 = (listnode*) malloc(sizeof(listnode));
//     // l3->val = 2;
//     // l3->next = (listnode*) malloc(sizeof(listnode));

//     // l3->next->val = 6;
//     // l3->next->next = NULL;



//     listnode_array* list_array = (listnode_array*)malloc(sizeof(listnode_array));
//     list_array->array = (listnode**)malloc(sizeof(listnode*) * 2);
//     list_array->array[0] = l;
//     list_array->array[1] = l2;
//     //list_array->array[2] = l3;
//     list_array->size = 2;

//     listnode* res = merge_k_sorted_lists(list_array);

//     print_list(res);

//     //free the memory
//     free(res); //merged linked list
//     free(list_array->array);
//     free(list_array);

//     return 0;
// }