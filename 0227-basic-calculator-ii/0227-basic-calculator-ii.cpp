class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int val=0;
        int sign=0;
        char op='+';
        for(int i=0;i<s.size();i++){
            if(s[i]==' ') continue;
            if(s[i]>='0' && s[i]<='9') val = val*10 + (s[i]-'0');
            if(s[i]=='-'){
                val = sign ? -val:val;
                if(op=='*'){
                    int x=st.top();st.pop();
                      val *= x;  
                }else if(op=='/'){
                    int x=st.top();st.pop();
                    x /= val;
                    val=x;
                }
                st.push(val);
                sign=1;
                val=0;
                op='+';
            }
            if(s[i]=='+') {
                val = sign ? -val:val;
                if(op=='*'){
                    int x=st.top();st.pop();
                      val *= x;  
                }else if(op=='/'){
                    int x=st.top();st.pop();
                    x /= val;
                    val=x;  
                }
                st.push(val);
                val=0;
                op='+';
                sign=0;
            }
            if(s[i]=='*' || s[i]=='/'){
                val = sign ? -val:val;
                if(op=='*'){
                    int x=st.top();st.pop();
                      val *= x;  
                }else if(op=='/'){
                    int x=st.top();st.pop();
                    x /= val;
                    val=x;  
                }
                st.push(val);
                val=0;
                op=s[i];
                sign=0;
            }
        }
        val = sign ? -val:val;
        cout<<val;
        if(op=='*'){
            int x=st.top();st.pop();
              val *= x;  
        }else if(op=='/'){
            int x=st.top();st.pop();
            x /= val;
            val=x;
        }
        st.push(val);
        int ans=0;
        while(st.size()){
            // cout<<st.top()<<" ";
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};