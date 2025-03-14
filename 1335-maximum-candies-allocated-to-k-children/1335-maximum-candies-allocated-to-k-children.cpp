class Solution {
public :
bool canWeAllocate(vector<int> &candies,long long k, int num){
 long long  int maxi = 0;
  for(int i = 0;i<candies.size();i++){
    maxi += candies[i]/num ;
  }
  if(maxi >= k)
  return true;
  return false;
}
    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size();
       
        int maxi = INT_MIN;
        for(int candy : candies){
           if(candy > maxi)
           maxi = candy;
        }
        int l = 0;int r = maxi;
        while(l<r){
            int mid = (l+r+1)/2;
            if(canWeAllocate(candies,k,mid))
            l = mid;
            else{
                r = mid-1;

            }
       
        }
      return l;
    }
};