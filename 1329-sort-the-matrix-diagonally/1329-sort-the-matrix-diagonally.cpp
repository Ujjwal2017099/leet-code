class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& m) {
        priority_queue<int,vector<int>,greater<int>> q;
        for(int i=0;i<m.size();i++){
            for(int j=0;j<m[0].size();j++){
                int r = i , c = j;
                while(r<m.size() and c<m[0].size()){
                    q.push(m[r][c]);
                    r++;c++;
                }
                r=i;c=j;
                while(!q.empty()){
                    m[r][c] = q.top();q.pop();
                    r++;c++;
                }
            }
        }
        return m;
    }
};