/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* oddEvenList(struct ListNode* head) {
     if(head==NULL || head->next==NULL){
            return head;
        }
        struct ListNode *dummynode = (struct ListNode*)malloc(sizeof(struct ListNode));
        
        struct ListNode * temp = dummynode;
       struct  ListNode * even = head->next;
       struct ListNode * odd = head;
        

        while(even!=NULL&&even->next!=NULL){
            odd->next = even->next;
            odd = odd->next;
            temp->next = even;
            temp=even;
           temp->next = NULL;
           even = odd->next;
        }
        if(even!=NULL){
            temp->next = even;
            temp = even;
            temp->next = NULL;
        }
        odd->next = dummynode->next;
        return head;
}