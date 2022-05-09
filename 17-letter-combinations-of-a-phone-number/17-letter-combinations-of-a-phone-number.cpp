class Solution {
public:
    vector<string> letterCombinations(string digits) {
        map<char,string> m;
        m['2'] = "abc";
        m['3'] = "def";
        m['4'] = "ghi";
        m['5'] = "jkl";
        m['6'] = "mno";
        m['7'] = "pqrs";
        m['8'] = "tuv";
        m['9'] = "wxyz";
        
        vector<string> ans;
        string st;
        vector<int> arr(digits.length(),0);
        
        switch(digits.length()){
            case 0: return ans;
                break;
                
            case 1: goto Label1;
                break;
                
            case 2: goto Label2;
                break;
                
            case 3: goto Label3;
                break;
                
            case 4: goto Label4;
                break;
                
        }
        return ans;
        Label1:
        for(int l = 0 ; l < m[digits[0]].length() ; l++)
        {
            st = m[digits[0]][l];
            // st += m[digits[1]][l];
            // st += m[digits[2]][k];
            // st += m[digits[3]][l];
            // cout<<m[digits[0]][i] + m[digits[1]][j] + m[digits[2]][k] + m[digits[3]][l]<<endl;
            ans.push_back(st);
            st.clear();
        }
        return ans;
        Label2:
        for(int k = 0 ; k < m[digits[0]].length() ; k++)
        {
            for(int l = 0 ; l < m[digits[1]].length() ; l++)
            {
                st = m[digits[0]][k];
                st += m[digits[1]][l];
                // st += m[digits[2]][k];
                // st += m[digits[3]][l];
                // cout<<m[digits[0]][i] + m[digits[1]][j] + m[digits[2]][k] + m[digits[3]][l]<<endl;
                ans.push_back(st);
                st.clear();
            }
        }
        return ans;
        Label3:
        for(int j = 0 ; j < m[digits[0]].length() ; j++)
        {
            for(int k = 0 ; k < m[digits[1]].length() ; k++)
            {
                for(int l = 0 ; l < m[digits[2]].length() ; l++)
                {
                    st = m[digits[0]][j];
                    st += m[digits[1]][k];
                    st += m[digits[2]][l];
                    // st += m[digits[3]][l];
                    // cout<<m[digits[0]][i] + m[digits[1]][j] + m[digits[2]][k] + m[digits[3]][l]<<endl;
                    ans.push_back(st);
                    st.clear();
                }
            }
        }
        return ans;
        Label4:
        for(int i = 0 ; i < m[digits[0]].length() ; i++)
        {
            for(int j = 0 ; j < m[digits[1]].length() ; j++)
            {
                for(int k = 0 ; k < m[digits[2]].length() ; k++)
                {
                    for(int l = 0 ; l < m[digits[3]].length() ; l++)
                    {
                        st = m[digits[0]][i];
                        st += m[digits[1]][j];
                        st += m[digits[2]][k];
                        st += m[digits[3]][l];
                        // cout<<m[digits[0]][i] + m[digits[1]][j] + m[digits[2]][k] + m[digits[3]][l]<<endl;
                        ans.push_back(st);
                        st.clear();
                    }
                }
            }
        }
        
        return ans;
    }
};