class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int n = arr.size();
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                if(arr[j]*2 == arr[i] || arr[i]*2 == arr[j]){
                    return true;
                    break;
                }
            }
        }
        return false;
    }
};