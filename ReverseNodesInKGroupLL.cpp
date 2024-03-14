ListNode* reverseLinkedList(ListNode *head)
{
   // Initialize'temp' at
   // head of linked list
   ListNode* temp = head;  
   
   // Initialize pointer 'prev' to NULL,
   // representing the previous node
   ListNode* prev = NULL;  
   
   // Traverse the list, continue till
   // 'temp' reaches the end (NULL)
   while(temp != NULL){  
       // Store the next node in
       // 'front' to preserve the reference
       ListNode* front = temp->next;  
       
       // Reverse the direction of the
       // current node's 'next' pointer
       // to point to 'prev'
       temp->next = prev;  
       
        // Move 'prev' to the current
        // node for the next iteration
       prev = temp;  
       
        // Move 'temp' to the 'front' node
        // advancing the traversal
       temp = front; 
   }
   
   // Return the new head of
   // the reversed linked list
   return prev;  
}

ListNode* findKthNode(ListNode* temp,int k){
    k-=1;
    while(temp!=NULL && k>0){
        k--;
        temp=temp->next;
    }
    return temp;
} 
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* prev=NULL;
        while(temp!=NULL){
            ListNode* kthNode=findKthNode(temp,k);
            if(kthNode==NULL){
                if(prev){
                    prev->next=temp;
                }
                break;
            }
            ListNode* nextNode=kthNode->next;
            kthNode->next=NULL;
            reverseLinkedList(temp);
            if(temp==head)
            head=kthNode;
            else{
            prev->next=kthNode;}

            prev=temp;
            temp=nextNode;

        }
        return head;
    }