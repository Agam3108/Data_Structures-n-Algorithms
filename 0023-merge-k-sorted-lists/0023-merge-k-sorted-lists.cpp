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
public:
ListNode* convertArrToLL(vector<int> arr){
    if(arr.size() == 0)
    return NULL;
    int n = arr.size();
    ListNode* head = new ListNode(arr[0]);
    ListNode* mover = head;
    for(int i = 1;i<n;i++){
        int val = arr[i];
        ListNode* temp = new ListNode(val);
        mover->next = temp;
        mover = mover->next;

    }
    return head;
}
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> arr;
        for(int i = 0;i<lists.size();i++){
            ListNode* temp = lists[i];
            while(temp != NULL){
                arr.push_back(temp->val);
                temp = temp->next;
            }
        }
        sort(arr.begin(),arr.end());
        ListNode* ans = convertArrToLL(arr);
        return ans;
    }
};