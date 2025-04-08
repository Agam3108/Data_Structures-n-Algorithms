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
ListNode* deleteTail(ListNode* head) {
    if (head == NULL || head->next == NULL)
        return NULL;
    ListNode* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    return head;
}
ListNode* removesHead(ListNode* head) {
    if (head == NULL)
        return head;
    ListNode* temp = head;
    head = head->next;
    delete temp;
    return head;
}
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        ListNode* temp = head;
        while(temp!=NULL){
            count++;
            temp = temp->next;
        }
        int res = count-n;
        if(n==1){
            return deleteTail(head);
        }
        else if(n==count){
          return removesHead(head);
        }
        temp = head;
        while(temp!=NULL){
                    res--;
                    if(res==0){
                        break;
                    }
                    temp = temp->next;
        }
          ListNode* delNode = temp->next;
            temp->next = temp->next->next;
            delete(delNode);
      return head;
    }
};