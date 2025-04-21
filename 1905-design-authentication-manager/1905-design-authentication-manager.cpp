class AuthenticationManager {
public:
 int t;
    int uniques {};
    unordered_map<string, int> st;
    queue<pair<string, int>> q;

    AuthenticationManager(int timeToLive) {
        t = timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        st[tokenId] = currentTime+t-1;
        ++uniques;
        q.push({tokenId, currentTime+t-1});

    }
    
    void renew(string tokenId, int currentTime) {
        if(st[tokenId]>=currentTime)
        {
            st[tokenId] = currentTime+t-1;
            q.push({tokenId, currentTime+t-1});
        }

    }
       void drop(int ct)
    {
        for( ; !empty(q) and q.front().second<ct; q.pop())
            if(st[q.front().first]==q.front().second and  st[q.front().first]<ct) --uniques; 
    }

    int countUnexpiredTokens(int currentTime) {
        drop(currentTime);
        return uniques;   
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */