/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    if (list1 == NULL) {
        return list2;
    } else if (list2 == NULL) {
        return list1;
    }
    struct ListNode* dummyhead = malloc(sizeof(struct ListNode)); 
    //keep track of head of list
    dummyhead->next = list1;
    dummyhead->val = 0;
    struct ListNode* tr = dummyhead; 
    struct ListNode* ptr1 = list1; 
    struct ListNode* ptr2 = list2;
    // add until done with list2
    
    while(ptr2 != NULL) {
        if (ptr1 == NULL || ptr1->val >= ptr2->val) {
            struct ListNode* tmpNode;
            tmpNode = ptr2->next;
            tr->next = ptr2;
            ptr2->next = ptr1;
            tr = ptr2;
            ptr2 = tmpNode;
            // at the end of this, we are at the next node of list2
        } else {
            //don't advance in list2, we stay
            //we advance in list1, both tr and ptr1
            tr = ptr1;
            ptr1 = ptr1->next;
        }
    }
    list1 = dummyhead->next;
    free(dummyhead);
    return list1;
}