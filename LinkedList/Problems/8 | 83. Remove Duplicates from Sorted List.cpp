class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL) return head;

        int val = head->val;
        ListNode* temp = head;
        ListNode* newHead = head;
        ListNode* ans = newHead;

        while(temp){
            if(val != temp->val){
                newHead->next = temp;
                val = temp->val;
                newHead = newHead->next;
            }
            temp = temp->next;
        }
        
        newHead->next = NULL;
        return ans;
    }
};
