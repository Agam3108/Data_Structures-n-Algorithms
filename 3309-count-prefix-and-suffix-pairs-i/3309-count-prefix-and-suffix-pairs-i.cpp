class Solution {
public:
bool isPrefixandSuffix(string a,string b){
    int n = b.length();
    int m = a.length();
    if(b.find(a)==0){
        if(b.rfind(a)==n-m)
        return true;
    }
    return false;
}
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int count = 0;
        for(int i = 0;i<n-1;i++){
             for(int j = i+1;j<n;j++){
            if(isPrefixandSuffix(words[i],words[j]))
            count++;
             }
        }
        return count;
    }
};