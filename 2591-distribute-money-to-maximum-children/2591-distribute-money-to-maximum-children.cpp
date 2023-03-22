class Solution {
public:
    int distMoney(int m, int c) {
        if(m-c<0) return -1;
        if(m-c==0) return 0;
        
        int cnt=0;
        int x = m/8;
        int y = m%8;
        cout<<x<<" "<<y<<endl;
        if(x==0 || x+y==c) return x;
        if(x+y>c) {
            if(x<c){
                int a = c-x-1;    
                if(y-a==4 && !a) return x-1;
                return x;
            }
            return c-1;
        }
        do{
            int f = c-(x+y);
            x -= (f+7)/8; 
            y += ((f+7)/8)*7+(f+7)/8;
        }while(x+y<c);
        return x<0 ? 0 : x;
    }
};