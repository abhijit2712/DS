Approach 1:Optimizaion of second approach
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      ListNode* dummy=new ListNode();
    ListNode* temp=dummy;
        int carry=0;
        
        
        while(l1!=NULL || l2!=NULL || carry){
            int sum=0;
            if(l1!=NULL){
                sum=sum+l1->val;
                l1=l1->next;
            }
            
            if(l2!=NULL){
                sum=sum+l2->val;
                l2=l2->next;
            }
            
            sum=sum+carry;
            carry=sum/10;
            ListNode* node=new ListNode(sum%10);
            temp->next=node;
            temp=temp->next;
        }
        
        return dummy->next;   
    }
};


Approach 2:
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int borrowFlag = 0;
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        ListNode* ans = NULL;
        ListNode* res = NULL;

        while(temp1 && temp2){
            int sum = temp1->val + temp2->val + borrowFlag;
            if(sum >= 10){
                borrowFlag = 1;
                sum = sum - 10;
            }else borrowFlag = 0;

            ListNode* node = new ListNode(sum);
            if(ans == NULL){
                res = node;
                ans = node;
            }
            else{
                ans->next = node;
                ans = node;
            }

            temp1 = temp1 -> next;
            temp2 = temp2 -> next;
        }
        
        while(temp1){
            int sum = temp1->val + borrowFlag;
            if(sum >= 10){
                borrowFlag = 1;
                sum = sum - 10;
            }else borrowFlag = 0;
            ListNode* node = new ListNode(sum);
            if(ans == NULL){
                res = node;
                ans = node;
            }
            else{
                ans->next = node;
                ans = node;
            }
            temp1 = temp1 -> next;
        }

        while(temp2){
            int sum = temp2->val + borrowFlag;
            if(sum >= 10){
                borrowFlag = 1;
                sum = sum - 10;
            }else borrowFlag = 0;
            ListNode* node = new ListNode(sum);
            if(ans == NULL){
                res = node;
                ans = node;
            }
            else{
                ans->next = node;
                ans = node;
            }
            temp2 = temp2 -> next;
        }
        if(borrowFlag == 1){
            ListNode* node = new ListNode(1);
            if(ans == NULL){
                res = node;
                ans = node;
            }
            else{
                ans->next = node;
                ans = node;
            }
        }
        
        return res;
    }
};
