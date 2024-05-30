class Solution {
public:
    int findLen(ListNode* head){
        int cnt = 0;
        ListNode* temp = head;

        while(temp){
            cnt++;
            temp = temp->next;
        }

        return cnt;
    }

    ListNode* middleNode(ListNode* head) {
       ListNode* fast = head;
       ListNode* slow = head;

    //    while(fast->next){ 
    //     fast = fast->next;
    //     if(fast->next){
    //      fast = fast->next;   
    //     }
    //     slow = slow->next;
    //    }

     // while(fast && fast->next){
     //     fast = fast->next->next;
     //     slow = slow->next;
     // }
        int len = findLen(head);
        int middle = len / 2;
        // if(len % 2 == 0){
        //     middle = middle + 1;
        // }   

        ListNode* temp = head;

        while(middle--){
            temp = temp->next;
        }


       return temp; 
    }
};
