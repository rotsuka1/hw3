#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************


#include "llrec.h"

void llpivot(Node*& head, Node*& smaller, Node*& larger, int pivot){
    if(head == NULL){
        smaller = NULL;
        larger = NULL;
        return;
    }

    Node* first = head;
    head = head->next;

    llpivot(head, smaller, larger, pivot);

    if(first->val <= pivot){
        first->next = smaller;
        smaller = first;
    }else{
        first->next = larger;
        larger = first;
    }
}