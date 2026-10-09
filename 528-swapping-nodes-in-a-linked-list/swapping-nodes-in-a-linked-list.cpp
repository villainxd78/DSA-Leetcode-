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
    int getsizze(ListNode * head){
        int size = 0;
        while(head!=nullptr){
            size ++;
            head = head->next;
        }
        return size;
    }
    ListNode* swapNodes(ListNode* head, int k) {
        
        ListNode * temp = head;
       for(int i = 1;i<k;i++){
        temp = temp->next;
       }
       int o = getsizze(head);
       int diff = o-k;
       ListNode * curr = head;
       for(int i = 0;i<diff;i++){
         curr = curr->next;
       }
       swap(curr->val,temp->val);
       return head;
    }
};