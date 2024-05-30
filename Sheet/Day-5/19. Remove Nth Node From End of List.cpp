class Solution {
public:
    int LLlenght(ListNode* head){
        int cnt = 0;
        ListNode* temp = head;

        while(temp){
            cnt++;
            temp = temp->next;
        }

        return cnt;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next==NULL){
            return NULL;
        }


        int cnt = 0;
        ListNode* prev = head;
        int len = LLlenght(head);

        if(len==n){
            head=head->next;
        }
        int pos = len - n + 1;
        ListNode* temp = head;

        while(cnt < pos-1){
            prev = temp;
            temp = temp->next;
            cnt++;
        }

        prev->next = temp->next;

        return head;
    }
};
