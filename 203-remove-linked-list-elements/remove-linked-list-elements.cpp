/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode * dummynode = new ListNode(0);
        dummynode->next = head;
        ListNode* temp = dummynode;
         while(temp!=nullptr && temp->next!=nullptr){
            if(temp->next->val!=val){
                temp = temp->next;
            }else{
                temp->next = temp->next->next;
            }
         }
         return dummynode->next;
    }
};