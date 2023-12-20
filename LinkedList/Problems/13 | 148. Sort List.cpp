class Solution {
public:
    ListNode* findMid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(1);
        ListNode* curr = dummy;

        while(list1 && list2){
            if(list1->val < list2->val){
                curr->next =list1;
                list1 = list1->next;
            }else{
                curr->next = list2;
                list2 = list2->next;
            }
            if(curr->next != NULL) curr = curr->next;
        }

        if(list1) curr->next = list1;
        if(list2) curr->next = list2;

        return dummy->next;
    }


    ListNode* merge(ListNode* l1,ListNode* l2){
        ListNode *cur = new ListNode(0);
        ListNode *temp = cur;

        while(l1 && l2){
            if(l1->val < l2->val){
                cur->next = l1;
                l1 = l1->next;
            }else{
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        if(l1){
            cur->next = l1;
        } 
        if(l2){
            cur->next = l2;
        }
        return temp->next;
    }

    ListNode* sortList(ListNode* head) {
        if(head==0 || head->next==0) return head;

        ListNode* mid = findMid(head);
        ListNode* left  = head;
        ListNode* right = mid->next;
        mid->next = 0;

        left  = sortList(left);
        right = sortList(right);

        ListNode* ans = merge(left, right);

        return ans;
    }
};
