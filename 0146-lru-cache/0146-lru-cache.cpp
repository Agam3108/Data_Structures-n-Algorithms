
class LRUCache {
public:
class Node {
      public:
        int key;
      int val;
      Node * next;
      Node*  prev;
      Node(int _key, int _val) {
        key = _key;
        val = _val;
      }
    };

  Node * head = new Node(-1, -1);
  Node * tail = new Node(-1, -1);
map<int,Node*> mpp;
int capacity_ ;

void deleteNode(Node* node){
    Node* prevNode = node->prev;
    Node* afterNode = node->next;
    prevNode->next = afterNode ;
    afterNode->prev = prevNode ;
}
void insertAfterHead(Node* newnode){
   Node * temp = head -> next;
    newnode -> next = temp;
    newnode -> prev = head;
    head -> next = newnode;
    temp -> prev = newnode;
}
    LRUCache(int capacity) {
        capacity_ = capacity;
        head->next = tail ;
        tail->prev = head;
        mpp.clear(); 
    }
    
    int get(int key_) {
       if (mpp.find(key_) != mpp.end()) {
      Node * resnode = mpp[key_];
      int res = resnode -> val;
      mpp.erase(key_);
      deleteNode(resnode);
      insertAfterHead(resnode);
      mpp[key_] = head -> next;
      return res;
    }

    return -1;
    }
    
    void put(int key, int value) {
        if(mpp.find(key)!=mpp.end()){
            Node* node = mpp[key];
    mpp.erase(key);
    node->val = value; 
    deleteNode(node);
    insertAfterHead(node);
    mpp[key] = node;
        }
        else{
            if(mpp.size()==capacity_){
                Node* node = tail->prev;
                mpp.erase(node->key);
                deleteNode(node);
            }
            Node* node = new Node(key,value);
            mpp[key] = node;
            insertAfterHead(node);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */