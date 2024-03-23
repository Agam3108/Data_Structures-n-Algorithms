 void reorderList(ListNode* head) {
        if(head==NULL || head->next==NULL)
        return ;
        ListNode* slow=head;
        ListNode* fast=head;
        
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
       ListNode* prev=NULL; ListNode* curr=slow->next; ListNode* nextNode=NULL;
       while(curr!=NULL){
        nextNode=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nextNode;
       } 
       slow->next=NULL;
       ListNode* first=head; ListNode* second=prev;
        while (second) {
        ListNode *nextFirst = first->next;
        ListNode *nextSecond = second->next;
        first->next = second;
        second->next = nextFirst;
        first = nextFirst;
        second = nextSecond;
    }
     
    }