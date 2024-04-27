 int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        // Code here
     queue<pair<string,int>> q;
     q.push({startWord,1});
     unordered_set<string> st(wordList.begin(),wordList.end());
     st.erase(startWord);
     while(!q.empty()){
         string word=q.front().first;
         int steps=q.front().second;
         q.pop();
         if(word==targetWord)
         return steps;
         for(int i=0;i<word.size();i++){
             char ch=word[i];
             for(char c='a';c<='z';c++){
                 word[i]=c;
                 if(st.find(word)!=st.end()){
                     st.erase(word);
                     q.push({word,steps+1});
                 }
                 
             }
             word[i]=ch;
         }
     }
      return 0;  
        