class Solution {
public:
    vector<vector<int>> outerTrees(vector<vector<int>>& tree) {
        if(tree.size()<4) return tree;
        vector<vector<int>> ans;
        set<vector<int>> t;
        int mn=0;
        for(int i=0;i<tree.size();i++){
            if(tree[i][0] < tree[mn][0]){
                mn=i;
            }
        }
        int p=mn;
        // cout<<mn<<endl;
        unordered_map<int,bool> mp;
        do{
            int q = (p+1)%tree.size();
            for(int i=0;i<tree.size();i++){
                int o = slope(tree[p],tree[i],tree[q]);
                if(o>0 && !mp[i]) q=i;
            }
            mp[q]=1;
            for(int i=0;i<tree.size();i++){
                if(i!=p && i!=q && slope(tree[p],tree[i],tree[q])==0 && between(tree[p],tree[q],tree[i])) {
                    t.insert(tree[i]);
                }
            }
            t.insert(tree[q]);
            p=q;
            // cout<<p<<" ";
        }while(p!=mn);
        
        for(vector<int> x:t) ans.push_back(x);
        
        return ans;
    }
    int slope(vector<int>& p,vector<int>& q,vector<int>& r){
        return (q[1] - p[1]) * (r[0] - q[0]) - (q[0] - p[0]) * (r[1] - q[1]);
    }
    bool between(vector<int>& a,vector<int>& b,vector<int>& c){
        bool x = a[0]>=c[0] && b[0]<=c[0] || b[0]>=c[0] && a[0]<=c[0] ;
        bool y = a[1]>=c[1] && b[1]<=c[1] || b[1]>=c[1] && a[1]<=c[1] ;
        return x&&y;
    }
};