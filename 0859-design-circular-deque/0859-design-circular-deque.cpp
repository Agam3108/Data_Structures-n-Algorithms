class MyCircularDeque {
    vector<int> circularDQ;
    int front;
    int rear;
    int size;
    int capacity;
public:
    MyCircularDeque(int k) {
        circularDQ = vector<int>(k);
        size = 0;
        capacity = k;
        front = -1;
        rear = -1;
    }
    
    bool insertFront(int value) {
        if (isFull())
            return false;
        if (isEmpty()) {
            front = 0;
            rear = 0;
        } else if (front == 0) {
            front = capacity - 1;  
        } else {
            front--;
        }
        circularDQ[front] = value;
        size++;
        return true;
    }
    
    bool insertLast(int value) {
        if (isFull())
            return false;
        if (isEmpty()) {
            front = 0;
            rear = 0;
        } else if (rear == capacity - 1) {
            rear = 0;  
        } else {
            rear++;
        }
        circularDQ[rear] = value;
        size++;
        return true;
    }
    
    bool deleteFront() {
        if (isEmpty())
            return false;
        if (front == rear) {  
            front = -1;
            rear = -1;
        } else if (front == capacity - 1) {
            front = 0; 
        } else {
            front++;
        }
        size--;
        return true;
    }
    
    bool deleteLast() {
        if (isEmpty())
            return false;
        if (front == rear) { 
            front = -1;
            rear = -1;
        } else if (rear == 0) {
            rear = capacity - 1; 
        } else {
            rear--;
        }
        size--;
        return true;
    }
    
    int getFront() {
        if (isEmpty())
            return -1;
        return circularDQ[front];
    }
    
    int getRear() {
        if (isEmpty())
            return -1;
        return circularDQ[rear];
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == capacity;
    }
};
