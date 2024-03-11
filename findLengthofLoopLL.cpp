
    int findLength(struct Node* slow,struct Node* fast)
    {
        int count=1;
        fast=fast->next;
        while(slow!=fast){
           count++;
           fast=fast->next;
           
        }
        return count;
    }
    
int countNodesinLoop(struct Node *head)
{
    // Code here
    struct Node* slow=head;
    struct Node* fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
        return findLength(slow,fast);
    }
    return 0;
}
  