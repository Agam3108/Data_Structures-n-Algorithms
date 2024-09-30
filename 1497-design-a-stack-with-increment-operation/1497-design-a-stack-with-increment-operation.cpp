class CustomStack {
public:
vector<int> st;
int topIndex;
    CustomStack(int maxSize) {
        st.resize(maxSize);
        topIndex = -1;
    }
    
    void push(int x) {
      if(topIndex < (int)st.size()-1){
        ++topIndex;
        st[topIndex] = x;

      }
    }
    
    int pop() {
        if(topIndex ==-1)
        return -1;
        int top = st[topIndex--];
        
        return top;
    }
    
    void increment(int k, int val) {
         if(k>st.size()){
            for(int i =0 ;i<st.size();i++){
                st[i] += val;
            }
         }
         else{
            for(int i =0 ;i<k;i++){
                st[i] += val;
            }
         }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */