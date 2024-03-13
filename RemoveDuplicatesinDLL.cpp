Node * removeDuplicates(struct Node *head)
    {
        // Your code here
        Node* temp=head;
        while(temp!=NULL && temp->next!=NULL){
            Node* nextNode=temp->next;
            while(nextNode!=NULL && nextNode->data==temp->data){
                Node* dup=nextNode;
                nextNode=nextNode->next;
                free(dup);
                
            }
            temp->next=nextNode;
            if(nextNode)
            nextNode->prev=temp;
            temp=temp->next;
        }
        return head;
    }