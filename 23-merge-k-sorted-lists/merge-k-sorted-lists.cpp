/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    class Compare{
        public: 
        bool operator()(ListNode* a, ListNode*b){
            return a->val > b->val;
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
         priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
           for (ListNode* node : lists) {
            if (node != nullptr)
                pq.push(node);
        }

        ListNode* root = new ListNode(0);
        ListNode * tail = root;
        
        ListNode *temp;

        while(!pq.empty()){
            temp = pq.top();
            pq.pop();
            tail -> next = temp;
            tail = tail-> next;

            if( temp-> next != NULL){
                pq.push(temp->next);
            }
        }
        return root->next;
    }
};