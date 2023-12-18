Approach 1:

class Solution {
public:
    int findLength(ListNode* head){
        int len = 0;
        ListNode* temp = head;

        while(temp){
            temp = temp->next;
            len++;
        }

        return len;
    }

    ListNode* middleNode(ListNode* head) {
        int len = findLength(head);
        cout << len << "  ";
        
        int pos = (len/2) + 1;;

        int i = 1;        
        ListNode* temp = head;
        while(i < pos){
            temp = temp->next;
            i++;
        }
        return temp;
    }
};



Approach 2: [Efficient] Tortoise-Hare-Approach
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next != NULL){
            slow = slow->next;
            fast = fast->next;

            if(fast->next != NULL) fast = fast->next;
        } 

        return slow;      
    }
};

