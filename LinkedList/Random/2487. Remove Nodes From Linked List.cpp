class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        vector<int> arr;
        ListNode* temp = head;

        while(temp){
            arr.push_back(temp->val);
            temp = temp->next;
        }

        vector<int> res;
        int n = arr.size() -1;
        int maxi = 0;
        for(int i=n;i>=0;i--){
           if (arr[i] >= maxi){
               res.push_back(arr[i]);
               maxi = arr[i];
           }
        }
        reverse(res.begin(),res.end());
        ListNode* dummy = new ListNode();
        ListNode* it = dummy;


        for(int i=0;i<res.size();i++){
            ListNode* curr = new ListNode(res[i]);
            it->next = curr;
            it = curr;
        }

        return dummy->next;
    }
};
