class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char> st;
        int arr[26] = {0};
        bool ch[26] = {0};
        
        for(int i=0;i<s.size();i++) arr[s[i]-'a'] = i;
        
        for(int i=0;i<s.size();i++){
            if(ch[s[i]-'a']) continue;
            
            while(st.size() > 0 && st.top() > s[i] && i < arr[st.top() - 'a']){
                ch[st.top() - 'a'] = 0; 
                st.pop();
            }
            st.push(s[i]); 
            ch[s[i]-'a'] = 1; 
        }
        string ans="";
        while(st.size()){
            ans.push_back(st.top());st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
};