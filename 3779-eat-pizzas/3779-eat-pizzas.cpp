class Solution {
public:
    long long maxWeight(vector<int>& pizzas) {
        int n = pizzas.size();
        sort(pizzas.rbegin(),pizzas.rend());
        int max = 0;
        int numDays = n/4;
        int oddDays = (numDays+1)/2;
        int evenDays = numDays - oddDays;
        long long w = 0;
        for(int i = 0;i<oddDays;i++){
            w += pizzas[max];
            max++;
        }
        for(int i = 0;i<evenDays;i++){
            max++;
            w += pizzas[max];
            max++;
        }
        return w;
    }
};