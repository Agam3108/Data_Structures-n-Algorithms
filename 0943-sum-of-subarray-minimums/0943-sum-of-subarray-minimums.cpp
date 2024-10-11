class Solution {
public:
const int mod = 1e9+7;
vector<int> findNSE(vector<int> &arr){
    int n = arr.size();
    vector<int> nse(n);
    stack<int> st;
    for(int i =n-1;i>=0;i--){
        while(!st.empty() && arr[st.top()]>=arr[i])
        st.pop();
        nse[i] = st.empty()?n :st.top();
        st.push(i);
    }
    return nse;
}
vector<int> findPSE(vector<int> &arr){
    int n = arr.size();
    vector<int> Pse(n);
    stack<int> st;
    for(int i =0;i<n;i++){
        while(!st.empty() && arr[st.top()] > arr[i])
        st.pop();
         Pse[i] = st.empty()?-1:st.top();
        st.push(i);
    }
    return Pse;
}
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse = findNSE(arr);
        vector<int> pse = findPSE(arr);
        int total = 0;
        for(int i = 0;i<n;i++){
          int left = i - pse[i];
          int right = nse[i] - i;
          long len = (left*right*1LL);
          long long sum = (arr[i]*len);
          total = (total+sum)%mod;

        }
        return total;
    }
};