Approach 4: Floyd cycle detection algoriothm
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL) return false;

        ListNode* slow = head;
        ListNode* fast = head;


        while(fast != NULL){
            fast = fast->next;
            if(fast!= NULL){
                fast = fast->next;
                slow = slow->next;
            }
            if(fast == slow) return true;
        }


        return false;
    }
};



Approach 1:Using map
class Solution {
public:
    bool hasCycle(ListNode *head) {
        map<ListNode*, int> mpp;
        ListNode* temp = head;
        

        while(temp){
            if(mpp.find(temp) != mpp.end()){
                return true;
            }
            mpp[temp] = 1;
            temp = temp->next;
        }

        return false;
    }
};


Approach 2: Using map
class Solution {
public:
    bool hasCycle(ListNode *head) {
        map<ListNode*, int> mpp;
        ListNode* temp = head;
        

        while(temp){
            if(mpp.find(temp) != mpp.end()){
                return true;
            }
            mpp[temp] = 1;
            temp = temp->next;
        }

        

        return false;
    }
};



Approach 3: Using Set
class Solution {
public:
    bool hasCycle(ListNode *head) {
        set<ListNode*> st;
        ListNode* temp = head;

        while(temp){
            if(st.find(temp) != st.end()){
                return true;
            }
            st.insert(temp);
            temp = temp->next;
        }

        return false;
    }
};





