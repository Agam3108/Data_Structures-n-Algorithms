class Solution {
public:
    int maxDistance(string s, int k) {
        int n = s.length();
        int north = 0;
        int south = 0;
        int east = 0;
        int west = 0;
        int ans = 0;
        for(char it : s){
            switch(it){
                case 'N' :
                north++;
                break;
                case 'S' :
                south++;
                break;
                case 'E' :
                east++;
                break;
                case 'W' :
                west++;
                break;
            }
            int times1 = min(north,min(south,k));
            int times2 = min(east,min(west,k-times1));
            ans = max(ans,count(north,south,times1)+count(east,west,times2));

        }
       return ans;
    }
    int count(int drt1,int drt2,int times)
    {
        return abs(drt1-drt2) + times*2 ;
    }
};