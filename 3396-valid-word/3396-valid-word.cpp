class Solution {
public:
int isVowel(char ch)
{
    string str = "aeiouAEIOU";
    return (str.find(ch) != string::npos);
}
int isConsonant(char ch){
    if(!isdigit(ch) && !isVowel(ch))
    return true;
    return false;
}

    bool isValid(string word) {
        int n = word.size();
        
        if(n >= 3){
            int cc = 0;
            int vc = 0;
            int cs = 0;
            for(int i = 0;i<n;i++){
                if(isalnum(word[i]) && isVowel(word[i]))
                vc++;
                else if(isalnum(word[i]) && isConsonant(word[i]))
                cc++;
                else if(!isalnum(word[i])){
                   cs++;
                }
            }
            if(vc >= 1 && cc>=1 && cs == 0)
            return true;
        }
        return false;
    }
};