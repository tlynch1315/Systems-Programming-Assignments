/* list.c */

#include "list.h"

/* Internal Function Prototypes */

static struct node*	reverse(struct node *curr, struct node *next);
static struct node *	msort(struct node *head, node_compare f);
static void		split(struct node *head, struct node **left, struct node **right);
static struct node *	merge(struct node *left, struct node *right, node_compare f);

/**
 * Create list.
 *
 * This allocates a list that the user must later deallocate.
 * @return  Allocated list structure.
 */
struct list *	list_create() {
    struct list *l = malloc(sizeof(struct list));
    if(l != NULL){
        l->head = NULL;
        l->tail = NULL;
        l->size = 0;
    }
    return l;
}

/**
 * Delete list.
 *
 * This deallocates the given list along with the nodes inside the list.
 * @param   l	    List to deallocate.
 * @return  NULL pointer.
 */
struct list *	list_delete(struct list *l) {
    node_delete(l->head, true);
    free(l);
    return NULL;
}

/**
 * Push front.
 *
 * This adds a new node containing the given string to the front of the list.
 * @param   l	    List structure.
 * @param   s	    String.
 */
void		list_push_front(struct list *l, char *s) {
    struct node * newNode = node_create(s, l->head);
    l->head = newNode;
    (l->size)++;
    if(l->size ==1) l->tail = newNode;
}

/**
 * Push back.
 *
 * This adds a new node containing the given string to the back of the list.
 * @param   l	    List structure.
 * @param   s	    String.
 */
void		list_push_back(struct list *l, char *s) {
    struct node * newTail = node_create(s, NULL);
    if(l->size > 0)
        l->tail->next = newTail;
    l->tail = newTail;
    l->size++;
    if(l->size == 1)
        l->head = newTail;
}

/**
 * Dump list to stream.
 *
 * This dumps out all the nodes in the list to the given stream.
 * @param   l	    List structure.
 * @param   stream  File stream.
 */
void		list_dump(struct list *l, FILE *stream) {
    struct node * curr = l->head;
    while(curr != NULL){
        node_dump(curr, stream);
        curr = curr->next;
    }
}

/**
 * Convert list to array.
 *
 * This copies the pointers to nodes in the list to a newly allocate array that
 * the user must later deallocate.
 * @param   l	    List structure.
 * @return  Allocate array of pointers to nodes.
 */
struct node **	list_to_array(struct list *l) {
    struct node ** arr = malloc(l->size*sizeof(struct node *));
    struct node *temp = l->head;
    for(int i = 0; i < l->size; i++){
        arr[i] = temp;
        temp = temp->next;
    }
    return arr;
}

/**
 * Sort list using qsort.
 *
 * This sorts the list using the qsort function from the standard C library.
 * @param   l	    List structure.
 * @param   f	    Node comparison function.
 */
void		list_qsort(struct list *l, node_compare f) {
    struct node ** arr = list_to_array(l);
    qsort(arr, l->size, sizeof(arr[0]), f);
    for(int i = 0; i <(l->size) -1; i++){
        arr[i]->next = arr[i+1];    
    }
    arr[(l->size) -1]->next = NULL;
    l->head = arr[0];
    l->tail = arr[(l->size)-1];
    free(arr);
}

/**
 * Reverse list.
 *
 * This reverses the list.
 * @param   l	    List structure.
 */
void		list_reverse(struct list *l) {
    if(l->size > 2){
        struct node *newHead = l->head;
        struct node *Next = l->head->next;
        struct node *temp = Next->next;
        while(temp != NULL){
            newHead = reverse(Next, newHead);
            Next = temp;
            temp = Next->next;
        }
        newHead = reverse(Next, newHead);
        l->tail = l->head;
        l->head = newHead;
        l->tail->next = NULL;
    }
    else if(l->size == 2){
        struct node *newHead = reverse(l->tail, l->head);
        l->head->next = NULL;
        l->tail = l->head;
        l->head = newHead;
    }
}

/**
 * Reverse node.
 *
 * This internal function recursively reverses the node.
 * @param   curr    The current node.
 * @param   prev    The previous node.
 * @return  The new head of the singly-linked list.
 */
struct node*	reverse(struct node *curr, struct node *prev) {
    curr->next = prev;
    return curr;
}

/**
 * Sort list using merge sort.
 *
 * This sorts the list using a custom implementation of merge sort.
 * @param   l	    List structure.
 * @param   f	    Node comparison function.
 */
void		list_msort(struct list *l, node_compare f) {
    if(l->size > 1){
        l->head = msort(l->head, f);
        struct node * curr = l->head;
        while(curr->next != NULL){
            curr = curr->next;
        }
        l->tail = curr;
    }

}

/**
 * Performs recursive merge sort.
 *
 * This internal function performs a recursive merge sort on the singly-linked
 * list starting with head.
 * @param   head    The first node in a singly-linked list.
 * @param   f	    Node comparison function.
 * @return  The new head of the list.
 */
struct node *	msort(struct node *head, node_compare f) {
    struct node * left = head;
    struct node * right = head;
    split(head, &left, &right);

    if(left->next != NULL)
        left = msort(left, f);
    if(right->next != NULL)
        right = msort(right, f);
    head = merge(left, right, f);
    return head;
}

/**
 * Splits the list.
 *
 * This internal function splits the singly-linked list starting with head into
 * left and right sublists.
 * @param   head    The first node in a singly-linked list.
 * @param   left    The left sublist.
 * @param   right   The right sublist.
 */
void		split(struct node *head, struct node **left, struct node **right) {
    struct node * slow = head;
    struct node * fast = head;
    while((fast->next) != NULL){
        fast = fast->next;
        if(fast->next != NULL)
            fast = fast->next;
        else
            break;
        slow = slow->next;
    }
    *left = head;
    *right = slow->next;
    slow->next = NULL;
}

/**
 * Merge sublists.
 *
 * This internal function merges the left and right sublists into one ordered
 * list.
 * @param   left    The left sublist.
 * @param   right   The right sublist.
 * @param   f	    Node comparison function.
 * @return  The new head of the list.
 */
struct node *	merge(struct node *left, struct node *right, node_compare f) {
    struct node *newHead = NULL;
    if(f(&left, &right) < 0){
        newHead = left;
        left = left->next;
    }
    else{
        newHead = right;
        right = right->next;
    }
    struct node *temp;
    struct node *tail = newHead;
    while(left && right){
        if(f(&left, &right) < 0){
            temp = left;
            left = left->next;
        }
        else{
            temp = right;
            right = right->next;
        }
        tail->next = temp;
        tail = temp;
    }
    if(left)
        tail->next = left;
    else
        tail->next = right;
    return newHead;
}
