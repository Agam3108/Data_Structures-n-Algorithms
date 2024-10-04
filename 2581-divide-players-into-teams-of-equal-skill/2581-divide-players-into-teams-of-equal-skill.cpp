class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
       int n = skill.size();
        if (n % 2 != 0) return -1;  
        sort(skill.begin(),skill.end());
        int targetSum = skill[0]+skill[n-1];
        long long totalChemistry = 0;
        for(int i =0;i<n/2;i++){
            if(skill[i] + skill[n-i-1] != targetSum)
            return -1;
           totalChemistry += (long long)(skill[i]*skill[n-i-1]);
        }
     return totalChemistry;
    }
};