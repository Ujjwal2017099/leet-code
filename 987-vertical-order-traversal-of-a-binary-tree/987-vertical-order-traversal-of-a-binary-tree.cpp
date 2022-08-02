class Solution {
public:
    int mn,mx;
    map<int,int> m;
    map<pair<int,int>,vector<int>> d;
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        mn = 0;mx = 0;
        distance(root,0,0);
        int j = 0;
        for(int in=mn;in<=mx;in++){
            m[in] = j;
            j++;
        }
        // cout<<mn<<" "<<mx<<endl;
        // for(auto i:d){
        //     cout<<i.first.first<<","<<i.first.second<<":";
        //     for(auto j:i.second){
        //         cout<<j<<" ";
        //     }
        //     cout<<endl;
        // }
        for(auto i:d){
            int x = m[i.first.first];
            sort(i.second.begin(),i.second.end());
            if(x>=ans.size()){
                ans.push_back(i.second);
            }else{
                for(auto j:i.second){
                    ans[x].push_back(j);
                }
            }
        }

        return ans;
    }
    void distance(TreeNode* root,int dis,int h){
        if(root == nullptr) return;
        
        mn = min(mn,dis);mx = max(mx,dis);
        // cout<<mn<<" "<<root->val<<" "<<h<<endl;
        d[{dis,h}].push_back(root->val);
        if(root->left) distance(root->left,dis-1,h+1);
        if(root->right) distance(root->right,dis+1,h+1);
    }
};