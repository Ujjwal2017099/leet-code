class Solution {
public:
    string removeDuplicates(string s, int k) {
        
        vector<char> st;
        char prev = '#';
        s+='?';
        int cnt = 1;
        for(char c:s)
        {
            if(cnt == k){
                while(cnt--)
                {
                    st.pop_back();
                }
                cnt = 1;
                if(!st.empty())
                {
                    int i = st.size()-1-1;
                    for(i;i>=0 ; i--)
                    {
                        if(st.back() == st[i]) cnt++;
                        else break;
                    }
                }
            }
            if(!st.empty())prev = st.back();
            st.push_back(c);
            if(c == prev){
                cnt++;
            }
            else cnt = 1;
        }
        
        string ans;
        while(!st.empty()){
            ans += st.back();
            st.pop_back();
        }
        
        reverse(ans.begin(),ans.end());
        ans.pop_back();
        return ans;
    }
};