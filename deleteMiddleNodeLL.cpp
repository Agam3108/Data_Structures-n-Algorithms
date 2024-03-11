Node* deleteMid(Node* head)
    {
        // Your Code Here
        Node* temp=head;
        int n=0;
        while(temp!=NULL){
            n++;
            temp=temp->next;
        }
        int res=n/2;
        temp=head;
        while(temp!=NULL){
            res--;
            if(res==0){
                Node* middle=temp->next;
                temp->next=temp->next->next;
                free(middle);
                break;
            }
            temp=temp->next;
        }
        return head;
    }