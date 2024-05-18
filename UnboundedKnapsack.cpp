int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector<int> prev(W+1,0);
        vector<int> curr(W+1,0);
        for(int w=0;w<=W;w++){
            prev[w]=((int)(w/wt[0]))*val[0];
        }
        for(int ind=1;ind<N;ind++){
            for(int w=0;w<=W;w++){
                int notTake=prev[w];
                int take=0;
                if(wt[ind]<=w)
                take=val[ind]+curr[w-wt[ind]];
                
                curr[w]=max(take,notTake);
            }
            prev=curr;
        }
        return prev[W];
    }