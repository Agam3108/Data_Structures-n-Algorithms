class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime,
                    vector<int>& endTime) {
             int n = startTime.size();
             vector<pair<int,int>> meetings;
          for(int i =0;i<n;i++){
             int s = startTime[i];
             int e = endTime[i];
             meetings.push_back({s,e});
          }
          sort(meetings.begin(),meetings.end());
          vector<int> gaps;
          if(meetings[0].first > 0)
          gaps.push_back(meetings[0].first);
          
         for(int i = 0;i<n-1;i++){
            int e = meetings[i].second;
            int s = meetings[i+1].first;
            gaps.push_back(s-e);
         }
         if(eventTime - meetings[n-1].second > 0);
          gaps.push_back(eventTime-meetings[n-1].second);
          int temp = 0;
          for(int i =0;i<=k && i<gaps.size();i++){
            temp += gaps[i];
          }
          int maxi = temp;
          for(int  i = k+1;i<gaps.size();i++){
            temp += gaps[i]-gaps[i-k-1];
            maxi = max(maxi,temp);
          }
          return maxi;
    }
};