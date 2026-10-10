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
        ListNode * temp = nullptr;
       while(head!=nullptr && head->val== val){
        temp = head;
        head = head->next;
        delete temp;
       }
       temp = head;
        while(temp!=nullptr && temp->next!=nullptr){
            if(temp->next->val!= val){
                temp = temp->next;
            }else{
             temp->next = temp->next->next;

            }
        }
        return head;
    }
};