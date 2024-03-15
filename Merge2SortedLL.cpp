Node* sortedMerge(Node* head1, Node* head2)  
{  
    // code here
    if(head1==NULL)
    return head2;
    if(head2==NULL)
    return head1;
    Node* temp1=head1;
    Node* temp2=head2;
    Node* dummyNode=new Node(-1);
    Node* temp=dummyNode;
    while(temp1!=NULL && temp2!=NULL){
        if(temp1->data<temp2->data){
            temp->next=temp1;
            temp=temp1;
            temp1=temp1->next;
        }
        else{
            temp->next=temp2;
            temp=temp2;
            temp2=temp2->next;
        }
        if(temp1)
        temp->next=temp1;
        if(temp2)
        temp->next=temp2;
    }
    return dummyNode->next;
}