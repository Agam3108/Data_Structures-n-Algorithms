class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
       int n = times.size();
       vector<int> target = times[targetFriend];
       sort(times.begin(),times.end());
       vector<int> chairTime(n,0);
       for(const auto time : times){
        for(int i =0;i<n;i++){
            if(chairTime[i] <= time[0]){
                chairTime[i] = time[1];
                if(time == target)
                return i;
                break;
            }
        }
       }
    return 0;

    }
};