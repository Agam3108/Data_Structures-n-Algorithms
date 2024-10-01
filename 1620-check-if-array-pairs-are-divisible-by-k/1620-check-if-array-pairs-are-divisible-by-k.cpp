class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int,int> mpp;

        for(int i = 0;i<n;i++){
           int x = arr[i];
           int mod = ((x%k)+k)%k ;
           mpp[mod]++;
        }
        for(auto i: arr){
            int rem = (i%k+k)%k;
            if(rem == 0) {
            if(mpp[rem]%2==1)
            return false;
            }
            else if(mpp[rem]!= mpp[k-rem])
            return false;
        }
        return true;
    }
};