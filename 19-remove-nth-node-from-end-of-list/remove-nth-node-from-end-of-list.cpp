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
     int getsize(ListNode * head){
        int size = 0;
        while(head!=NULL){
            size++;
            head = head->next;
        }
        return size;
     }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
         ListNode * temp = nullptr;
         int size = getsize(head);
         int diff = size-n;
          if (diff == 0) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }
        temp = head;
         for(int i = 1;i<diff;i++){
            temp = temp->next;
         }
         temp->next = temp->next->next;
         return head;
    }
};