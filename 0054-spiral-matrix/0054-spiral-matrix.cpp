class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& m) {
        int x=0;
        vector<int> v;
        for(x;x<(int)(min(m.size(),m[0].size())+1)/2;x++){
            for(int j=x;j<(int)m[0].size()-x;j++){
                v.push_back(m[x][j]);
                cout<<'a';
            }
            for(int i=x+1;i<(int)m.size()-x;i++){
                v.push_back(m[i][(int)m[0].size()-x-1]);
                cout<<'b';
            }
            for(int j=(int)m[0].size()-x-2 ; j>=x && x<(int)m.size()-1-x;j--){
                v.push_back(m[(int)m.size()-1-x][j]);
                cout<<'c';
            }
            for(int i=(int)m.size()-2-x ; i>x && (int)m[0].size()-1-x;i--){
                v.push_back(m[i][x]);
                cout<<'d';
            }
        }
        while(v.size()>m.size()*m[0].size()) v.pop_back();
        return v;
    }
};