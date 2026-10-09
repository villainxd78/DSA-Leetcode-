/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
     int getSize(ListNode * head){
        int size = 0;
        while(head!=nullptr){
            size++;
            head = head->next;
        }
        return size;
     }
    ListNode * getIntersectionNode(ListNode * headA, ListNode *headB) {
        int m = getSize(headA);
        int n = getSize(headB);

        ListNode * t1 = headA;
        ListNode * t2 = headB;
           
        int diff = 0;
        if(m>=n){

          diff = m-n;
          for(int i = 0;i<diff;i++){
            t1= t1->next;
          }
        }else{
            diff = n-m;
            for(int j = 0;j<diff;j++){
                t2 = t2->next;
            }

        }
        while(t1!=nullptr && t2!=nullptr && t1!=t2){
            t1 = t1->next;
            t2 = t2->next;
        }
        if(t1==nullptr){
            return nullptr;
        }else{
          return t1;
        }
       


        
    }
};