class Solution {
public:
    vector<string> ans;
    vector<string> generateParenthesis(int n) {
        string s;
        for(int i=1;i<=n;i++) s+='(';
        for(int i=1;i<=n;i++) s+=')';
        
        do{
            if(isvalid(s)) ans.push_back(s);
        }while(next_permutation(s.begin(),s.end()));
        return ans;
    }
    bool isvalid(string& s){
        stack<char> st;
        for(int i=0;i<s.length();i++){
            if(st.empty() && s[i]==')') return 0;
            if(!st.empty() && st.top()=='(' && s[i]==')') st.pop();
            else st.push(s[i]);
        }
        return st.empty();
    }
};