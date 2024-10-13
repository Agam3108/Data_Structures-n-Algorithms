class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        vector<int> indices(k,0);
        vector<int> range = {0,INT_MAX};
        while(true){
            int currMin = INT_MAX;
            int currMax = INT_MIN;
            int minListIndex = 0;
            for(int i = 0;i<k;i++){
                int currElement = nums[i][indices[i]];
                if(currElement <currMin){
                   currMin = currElement;
                   minListIndex = i;
                }
                if(currElement > currMax)
                currMax = currElement ;

            }
            if(currMax - currMin < range[1]-range[0]){
                range[0] = currMin;
                range[1] = currMax;
            }
            //indices[minListIndex]++;
            if(++indices[minListIndex] == nums[minListIndex].size())
            break;
        }
     return range;
    }
};