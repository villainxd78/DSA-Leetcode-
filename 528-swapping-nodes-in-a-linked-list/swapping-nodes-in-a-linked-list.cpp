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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode * temp = head;
         ListNode* p1 =head;
         ListNode* p2 = head;
          
          int i = 1;
          while(i<k){
           p1 = p1->next;
            i++;
          }
         temp = p1;

          temp = temp->next;
            
            while(temp!=NULL){
                  temp = temp->next;
                  p2 = p2->next;
            }
            
          
     swap(p2->val,p1->val);
        return head;
          

    }
     
};