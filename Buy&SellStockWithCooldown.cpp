 int maxProfit(vector<int>& prices) {
         int n=prices.size();
        vector<int> curr(2,0);
        vector<int> ahead(2,0);
        vector<int> ahead2(2,0);
    
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                int profit=0;
                if(buy){
                    profit=max(-prices[ind]+ahead[0],ahead[1]);
                }
                else{
                    profit=max(prices[ind]+ahead2[1],ahead[0]);
                }
                curr[buy]=profit;
            }
            ahead2=ahead;
            ahead=curr;
        }
     return curr[1];
    }