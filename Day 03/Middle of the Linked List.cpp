class Solution {
public:
    ListNode* middleNode(ListNode* head) {
         ListNode* left=head;
        ListNode* right=head;
        while(right!=NULL && right->next!=NULL){
            left=left->next;
            right=right->next->next;
            if(left==right)return left;
        }
        return left;
    }
};