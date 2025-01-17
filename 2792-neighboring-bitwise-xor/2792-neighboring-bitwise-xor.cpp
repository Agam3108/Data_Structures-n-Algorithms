class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int xr = 0;
        for(int derive : derived){
          xr^= derive;        
          }
    
    if(xr==0)
    return true;
    return false;
    }
};