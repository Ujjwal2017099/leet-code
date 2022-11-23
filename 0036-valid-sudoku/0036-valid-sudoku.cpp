class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& b) {
        for(int i=0;i<9;i+=3){
            int k=i;
            unordered_map<char,bool> mp;
            unordered_map<char,bool> mq;
            unordered_map<char,bool> mr;
            while(k<i+3){
                for(int j=0;j<3;j++){
                    if(mp[b[k][j]]) return 0;
                    if(b[k][j]>='1' && b[k][j]<='9') mp[b[k][j]]=1;
                }
                k++;
            }
            k=i;
            while(k<i+3){
                for(int j=3;j<6;j++){
                    if(mq[b[k][j]]) return 0;
                    if(b[k][j]>='1' && b[k][j]<='9') mq[b[k][j]]=1;
                }
                k++;
            }
            k=i;
            while(k<i+3){
                for(int j=6;j<9;j++){
                    if(mr[b[k][j]]) return 0;
                    if(b[k][j]>='1' && b[k][j]<='9') mr[b[k][j]]=1;
                }
                k++;
            }
            for(int i=0;i<9;i++){
                unordered_map<char,bool> m;
                for(int j=0;j<9;j++){
                    if(m[b[i][j]]) return 0;
                    if(b[i][j]>='1' && b[i][j]<='9') m[b[i][j]]=1;
                }
            }
            for(int i=0;i<9;i++){
                unordered_map<char,bool> m;
                for(int j=0;j<9;j++){
                    if(m[b[j][i]]) return 0;
                    if(b[j][i]>='1' && b[j][i]<='9') m[b[j][i]]=1;
                }
            }
            
        }
            return 1;
    }
};