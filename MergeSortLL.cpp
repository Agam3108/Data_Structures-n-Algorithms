 Node* findMiddle(Node* head){
        Node* slow=head;
        Node* fast=head->next;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            
        }
        return slow;
    }
    Node* merge2LL(Node* head1,Node* head2){
        Node* t1=head1;
        Node* t2=head2;
        Node* dummyNode = new Node(-1);
        Node* temp=dummyNode;
        while(t1!=NULL && t2!=NULL){
            if(t1->data<t2->data){
                temp->next=t1;
                temp=t1;
                t1=t1->next;
            }
            else{
                temp->next=t2;
                temp=t2;
                t2=t2->next;
            }
        }
        if(t1)
            temp->next=t1;
            if(t2)
            temp->next=t2;
        return dummyNode->next;
    }
    Node* mergeSort(Node* head) {
        // your code here
        if(head==NULL || head->next==NULL)
        return head;
        Node* middle=findMiddle(head);
        Node* leftHead=head;
        Node* rightHead=middle->next;
        middle->next=NULL;
        leftHead = mergeSort(leftHead);
        rightHead = mergeSort(rightHead);
        return merge2LL(leftHead,rightHead);
        
    }