 Node* convertArrtoLL(vector<int> &arr){
        
    int n=arr.size();
    if(n==0)
    return NULL;
    Node* head=new Node(arr[0]);
    Node* mover=head;
    for(int i=1;i<n;i++){
        Node* temp= new Node(arr[i]);
        mover->bottom=temp;
        mover=mover->bottom;
    }
    return head;
    }
Node *flatten(Node *root)
{
   // Your code here
   vector<int> arr;
   Node* temp=root;
   Node* temp2=NULL;
   while(temp!=NULL){
       temp2=temp;
       while(temp2!=NULL){
           arr.push_back(temp2->data);
           temp2=temp2->bottom;
       }
       temp=temp->next;
   }

   Node* head=convertArrtoLL(arr);
   return head;
   
}

