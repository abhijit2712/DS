class Solution {
public:
    ListNode* reverseLL(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* forward = NULL;
        while(curr){
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }

    ListNode* findmid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        int flag = 0;
        while(fast != NULL){
            flag = 0;
            fast = fast->next;

            if(fast != NULL){
                flag = 1;
                fast = fast->next;
                slow = slow->next;
            }
        }
        if(flag == 0){
            slow = slow->next;
        }
        return slow;
    }

    bool isPalindrome(ListNode* head) {
        ListNode* mid = findmid(head);
        ListNode* rev = reverseLL(mid);
        while(rev){
            if(head->val != rev->val) return false;
            head = head->next;
            rev = rev->next;
        }
        return true;
    }
};
