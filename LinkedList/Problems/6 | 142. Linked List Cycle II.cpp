Approach 1: 
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
         if(head == NULL) return head;

        ListNode* slow = head;
        ListNode* fast = head;


        while(fast != NULL){
            fast = fast->next;
            if(fast!= NULL){
                fast = fast->next;
                slow = slow->next;
            }
            if(fast == slow)break;
        }

        if(fast == NULL) return NULL;

        slow = head;
        
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
};]


Approach 2: 
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL) return NULL;

        unordered_map<ListNode*, bool> mpp;
        ListNode* temp = head;
        ListNode* prev = NULL;

        while(temp != NULL){
            if(mpp[temp] == true) return temp;
            mpp[temp] = true;
            temp = temp->next;
        }

        return temp;
    }
};
