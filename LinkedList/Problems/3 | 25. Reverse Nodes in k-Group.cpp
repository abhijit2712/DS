Approach 1: Recursive code: love Babbar code

class Solution {
public:
    int getLength(ListNode* &head){
        int len = 0;
        ListNode* temp = head;
        while(temp != NULL){
            temp = temp->next;
            len++;
        }
        return len;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
     // Empty Linked List case
    if(head == NULL){
        return head;
    }
    // Invalid case
    int len = getLength(head);
    if(k > len){
        return head;
    }
    // Step - 1 => Reverse first k nodes
    ListNode* prev = NULL;
    ListNode* curr = head;
    ListNode* forward = curr->next;
    int count = 0;
    while(count < k){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        count++;
    }
    // Step - 2 => Recursion 
    if(forward != NULL){ // We still have nodes left to reverse
        head->next = reverseKGroup(forward,k); // Connection step
    }
    // Return head 
    return prev;
    }
};







Approach 2 : Striver's code non recursive code


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

    ListNode* findkthNode(ListNode* temp, int k){
        k -= 1;

        while(temp != NULL && k>0){
            k--;
            temp = temp->next;
        } 

        return temp;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* nextNode = NULL;
        ListNode* prev = NULL;
        ListNode* kthnode=NULL;

        while(temp != NULL){
            kthnode = findkthNode(temp, k);

            if(kthnode == NULL){
                if(prev) prev->next = temp;
                break;
            }

            nextNode = kthnode->next;
            kthnode->next = NULL;

            //reverse k group
            reverseList(temp);

            //identify it is first group or not
            if(temp==head){
                head = kthnode;
            }else{
                prev->next = kthnode;
            }

            prev = temp;
            temp = nextNode;
        }

        return head;
    }
};
