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
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> nse = findNSE(heights);
        vector<int> pse = findPSE(heights);
        int maxi = INT_MIN;
        for(int i =0;i<n;i++){
            int area = heights[i]*(nse[i]-pse[i]-1);
            maxi = max(maxi,area);
        }
        return maxi;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> preSum(n,vector<int>(m,0));
        for(int j =0;j<m;j++){
            int sum = 0;
            for(int i =0;i<n;i++){
                //sum += (matrix[j][i]-'0');
                if(matrix[i][j]=='0')
                sum = 0;
                else
                sum += 1;
                preSum[i][j] = sum;
            }
        }
        int maxArea = 0;
        for(int i =0;i<n;i++){
           maxArea = max(maxArea,largestRectangleArea(preSum[i]));
        }
        return maxArea;
    }
};