class Solution {
public:
    vector<int> p;
    unordered_map<int,bool> xa;
    unordered_map<int,bool> ya;
    int removeStones(vector<vector<int>>& s) {
        int x=0,y=0;
        for(vector<int> t:s){
            x=max(x,t[0]);
            y=max(y,t[1]);
        }
        p.resize(x+y+2,-1);
        int fact = x+1;

        for(vector<int> t:s){
            int a = t[0],b = t[1];
            Union(a,b+fact);
            xa[a]=1;
            ya[b+fact] = 1;
        }
        
        int cnt=0;
        for(int i=0;i<p.size();i++){
            if(p[i]<0 && (xa[i]|ya[i])) {
                cnt++;
            }
            // cout<<i<<" ";
        }
        
        return s.size()-cnt;
    }
    int find(int a){
        if(p[a]<0) return a;
        return find(p[a]);
    }
    void Union(int a,int b){
        int x = find(a);
        int y = find(b);
        
        if(x!=y){
            p[x] += p[y];
            p[y] = x;
        }
    }
};