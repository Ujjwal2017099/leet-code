class Solution {
public:
    int arr[101][101]={{0}};
    int nearestExit(vector<vector<char>>& m, vector<int>& e) {
        queue<vector<int>> q;
        e.push_back(1);
        q.push(e);e.pop_back();
        int n1=m.size()-1;
        int n2=m[0].size()-1;
        int ans = 1e7;
        while(!q.empty()){
            vector<int> x = q.front();q.pop();
            if(m[x[0]][x[1]]=='+' || (arr[x[0]][x[1]] && arr[x[0]][x[1]] <= x[2])) continue;
            if(!(x[0]==e[0] && x[1]==e[1]) && (x[0]==0 || x[1]==0 || x[0]==n1 || x[1]==n2)){
                ans = min(ans,x[2]-1);
            }
            arr[x[0]][x[1]] = x[2];
            if(x[0]>0) q.push({x[0]-1,x[1],x[2]+1});
            if(x[1]>0) q.push({x[0],x[1]-1,x[2]+1});
            if(x[0]<n1) q.push({x[0]+1,x[1],x[2]+1});
            if(x[1]<n2) q.push({x[0],x[1]+1,x[2]+1});
        }
        if(ans==1e7) return -1;
        return ans;
    }
    
};