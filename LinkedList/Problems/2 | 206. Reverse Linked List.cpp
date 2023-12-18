Approach 1 : Iterative

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* forward = NULL;

        while(curr){
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }

        return prev;        
    }
};



Approach 2: Recursive implementation:
class Solution {
public:
    void reverseLL(ListNode* &head,ListNode* &curr,ListNode* &prev){
        if(curr == NULL){
            head = prev;
            return;
        }

        ListNode* forward = curr->next;
        reverseLL(head,forward,curr);
        curr->next = prev;
}

    ListNode* reverseList(ListNode* head) {
           ListNode* curr = head;
           ListNode* prev = NULL;

           reverseLL(head,curr,prev);
           return head;     
    }
};

Usign return 


class Solution {
public:
    ListNode* reverseLL(ListNode* &prev,ListNode* &curr){
        if(curr == NULL) return prev;
        ListNode* forward = curr->next;
        curr->next = prev;
        return reverseLL(curr,forward);
    }
    ListNode* reverseList(ListNode* head) {
           ListNode* curr = head;
           ListNode* prev = NULL;
           return reverseLL(prev,curr);
    }
};

