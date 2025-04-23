class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        if(n == 1)
        return stones[0];
        priority_queue<int> pq;
        for(int stone : stones){
            pq.push(stone);
        }
        while(!pq.empty()){
            if(pq.size() == 1)
            return pq.top();

            int topstone = pq.top();
            pq.pop();
            
            int secondtop = pq.top();
            pq.pop();
            if(topstone == secondtop)
            continue;
            else
            pq.push(topstone - secondtop);
        }
      return 0 ;
    }
};