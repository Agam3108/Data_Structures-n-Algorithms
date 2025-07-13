class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        
        int ans = 0;
        int n = players.size();
        int m = trainers.size();
        if (m == 0)
            return 0;
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        int top = 0, bottom = 0;
        while (top < n && bottom < m) {
            if (players[top] <= trainers[bottom]) {
                top++;
                ans++;
            }
            bottom++;
        }

        return ans;
    }
};