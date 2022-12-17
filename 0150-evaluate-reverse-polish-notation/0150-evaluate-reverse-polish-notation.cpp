class Solution {
public:
    int evalRPN(vector<string>& t) {
        stack<long long> st;
        for(int i=0;i<t.size();i++){
            if(t[i]!="-" && t[i]!="+" && t[i]!="*" && t[i]!="/"){
                st.push(stoi(t[i]));
            }
            else if(t[i]=="+"){
                long long a = st.top();st.pop();
                long long b = st.top();st.pop();
                st.push(a+b);
            }
            else if(t[i]=="-"){
                long long a = st.top();st.pop();
                long long b = st.top();st.pop();
                st.push(b-a);
            }
            else if(t[i]=="*"){
                long long a = st.top();st.pop();
                long long b = st.top();st.pop();
                st.push(a*b);
            }
            else{
                long long a = st.top();st.pop();
                long long b = st.top();st.pop();
                st.push(b/a);
            }
        }
        return st.top();
    }
};