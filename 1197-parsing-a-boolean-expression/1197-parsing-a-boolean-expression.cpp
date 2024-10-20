class Solution {
public: 
char parseNot(char op,vector<char> & values){
    int n = values.size();
    return values[0] == 't'?'f':'t';
}
char parseAnd(char op,vector<char> &values){
      int n = values.size();
    for(char value : values){
        if(value == 'f')
        return 'f';
    }
   return 't';
}
char parseOr(char op,vector<char> &values){
    int n = values.size();
    for(char value : values){
        if(value == 't')
        return 't';
    }
   return 'f';
}
    bool parseBoolExpr(string expression) {
        int n = expression.length();
        stack<char> st;
        for(int i = 0;i<n;i++){
            if(expression[i] == ')'){
                vector<char> values;
                while(st.top() != '('){
                    char ch = st.top();
                    st.pop();
                    values.push_back(ch);
                }
                st.pop();
                char op = st.top();
                st.pop();
                char result;
                if(op == '|')
                result = parseOr(op,values);
                else if(op == '&')
                result = parseAnd(op,values);
                else
                result = parseNot(op,values);
                st.push(result);

            }
            else  if(expression[i] != ',')
            st.push(expression[i]);
        }
        return st.top() == 't';
       }
};