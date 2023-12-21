class Solution {
public:
    int findLen(ListNode* head){
        int i = 0;
        while(head){
            head = head->next;
            i++;
        }
        return i;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) return head;
        int len =  findLen(head);
        k = k%len;
        if(k==0) return head;

        int cnt = len - k -1;
        ListNode* temp = head;
        
        for(int i=0;i<cnt;i++){
            temp = temp->next;
        }
        ListNode* newHead = temp->next;
        temp->next = 0;
        
        ListNode* it = newHead;
        while(it->next){
            it = it->next; 
        }
        it->next = head;

        return newHead;
    }
};
