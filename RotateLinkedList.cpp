 
    Node* rotate(Node* head, int k)
    {
      if(head == NULL||head->next == NULL||k == 0) return head;
        int len=1;
        Node* tail=head;
        while(tail->next!=NULL){
            len++;
            tail=tail->next;
        }
         if (k == len || k % len == 0) 
         return head;
        k=k%len;
    Node* prev = NULL;
    Node* curr = head;
    for (int i = 0; i < k; i++) {
        prev = curr;
        curr = curr->next;
    }

    // Move tail pointer to the last node
    tail->next = head;

    // Update head to the k-th node and set prev's next to nullptr
    head = curr;
    prev->next = nullptr;

   
        return head;
    }