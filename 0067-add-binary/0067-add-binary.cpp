class Solution {
public:
    string addBinary(string a, string b) {
        int prev=0;
        if(a.length()<b.length()) swap(a,b);
        int x=a.length()-1,y=b.length()-1;
        while(y>=0){
            if((a[x]-'0')&(b[y]-'0')){
                if(prev==0){
                    a[x] = '0';
                    prev=1;
                }
            }else{
                if((a[x]-'0')|(b[y]-'0')){
                    if(prev){
                        a[x]='0';
                    }else{
                        a[x]='1';
                    }
                }else{
                    if(prev){
                        a[x] = '1';
                        prev=0;
                    }
                }
            }
            x--;y--;
        }
        if(prev){
            while(x>=0){
                if((a[x]-'0')&prev){
                    a[x] = '0';
                    prev=1;
                }else if((a[x]-'0')|prev){
                    a[x]='1';
                    prev=0;
                }else{
                    break;
                }
                x--;
            }
        }
        if(prev){
            string ans = "1" + a;
                return ans;
        }
        return a;
    }
};