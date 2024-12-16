class Solution {
public:

    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n =classes.size();
        auto calculategain = [] (int passes,int totalStudents){
            return (double) (passes+1)/(totalStudents+1) - (double)(passes)/(totalStudents) ;
        };
        priority_queue<pair<double,pair<int,int>>> pq;
        for(int i = 0;i<n;i++){
            int pass = classes[i][0];
            int total = classes[i][1];
            double gain = calculategain(pass,total);
            pq.push({gain,{pass,total}});
        }
        while(extraStudents--){
            auto node = pq.top();
            pq.pop();
            int passes = node.second.first;
            int totalStudents = node.second.second;
            double g = node.first;
            passes += 1;
            totalStudents += 1;
            g = calculategain(passes,totalStudents);
            pq.push({g,{passes,totalStudents}});
        }
        double totalPassRatio = 0.0;
        while(!pq.empty()){
            totalPassRatio += (double)(pq.top().second.first)/(pq.top().second.second) ;
            pq.pop();
        }
        return totalPassRatio/n ;

    }
};