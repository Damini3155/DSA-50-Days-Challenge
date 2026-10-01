class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* second = slow->next;
        slow->next = NULL;
        ListNode* prev = NULL;
        while(second!=NULL){
            ListNode* next = second->next;
            second->next = prev;
            prev = second;
            second=next;
        }
        ListNode* first = head;
        second = prev;

        while(second!=NULL){
            ListNode* Temp1 = first->next;
            ListNode* Temp2 = second->next;

            first->next=second;
            second->next=Temp1;
            first=Temp1;
            second=Temp2;
        }
    }
};