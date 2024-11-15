class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        arr.insert(arr.begin(), 0);
        arr.push_back(INT_MAX); 

        stack<int> A, B;
        int p = 1, q = n;
        int M = 0;

        while (p <= q) {
            if (arr[p - 1] <= arr[p]) {
                A.push(arr[p]);
                p++;
            } else if (arr[q] <= arr[q + 1]) {
                B.push(arr[q]);
                while (!A.empty() && A.top() > B.top()) { 
                    A.pop();
                }
                q--;
            } else {
                break;
            }
            M = max(M, (int)(A.size() + B.size()));
        }

        return n - M;

    }
};