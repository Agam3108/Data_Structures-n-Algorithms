class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = status.size();
        queue<int> q;
        vector<bool> vis(n,false);
        for(int box : initialBoxes){
            q.push(box);
        }
        int res = 0;
        int curr = 0;
        while(!q.empty()){
            int size = q.size();
            for(int i =0;i<size;i++){
                curr = q.front();
                q.pop();
                vis[curr] = true;
                if(status[curr]){
                    res += candies[curr];
                }
                for(int box : containedBoxes[curr]){
                    if(!vis[box]){
                        q.push(box);
                    }
                }
                for(int key : keys[curr]){
                   if(status[key] == 0 && key != curr)
                   {
                    status[key] = 1;
                    if(vis[key]){
                        q.push(key);
                    }
                   }
                }
            }
        }
        return res;
    }
};