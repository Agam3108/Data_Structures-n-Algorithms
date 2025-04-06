class Solution {
public:
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
vector<int> findNGE(vector<int> &arr) {
    int n = arr.size();
    vector<int> nge(n);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && arr[st.top()] <= arr[i])
            st.pop();
        nge[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    return nge;
}
vector<int> findPGE(vector<int> &arr) {
    int n = arr.size();
    vector<int> pge(n);
    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] < arr[i])
            st.pop();
        pge[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return pge;
}
long long sumSubarrayMins(vector<int>& arr) {
    int n = arr.size();
    vector<int> nse = findNSE(arr);
    vector<int> pse = findPSE(arr);
    long long total = 0;
    for(int i = 0;i<n;i++){
        long long left = i - pse[i];
        long long right = nse[i] - i;
        long long len = left * right;
        total += arr[i] * len;
    }
    return total;
}
long long sumSubarraymaxi(vector<int>& arr) {
    int n = arr.size();
    vector<int> nge = findNGE(arr);
    vector<int> pge = findPGE(arr);
    long long total = 0;
    for (int i = 0; i < n; i++) {
        long long left = i - pge[i];
        long long right = nge[i] - i;
        long long len = left * right;
        total += arr[i] * len;
    }
    return total;
}
long long subArrayRanges(vector<int>& nums) {
    long long smi = sumSubarrayMins(nums);
    long long smx = sumSubarraymaxi(nums);
    return smx - smi;
}
};
