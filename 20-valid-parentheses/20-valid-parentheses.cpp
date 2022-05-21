class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char c:s){
            if(c == '(' or c == '[' or c == '{') st.push(c);
            
            else if(c == ')' and !st.empty() and st.top() == '(') st.pop();
            else if(c == ']' and !st.empty() and st.top() == '[') st.pop();
            else if(c == '}' and !st.empty() and st.top() == '{') st.pop();
            
            else return false;
        }
        
        if(st.empty()) return true;
        
        return false;
    }
};