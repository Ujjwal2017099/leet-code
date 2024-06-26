class Solution {
public:
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        
        vector<vector<int>> v;
        bool f=0;
        while(!q.empty()){
            TreeNode* x = q.front();q.pop();
            if(x==nullptr){
                if(!q.empty()) q.push(nullptr);
                f=0;
                continue;
            }
            if(x->left) q.push(x->left);
            if(x->right) q.push(x->right);
            if(!f){
                v.push_back({x->val});
            }else{
                v.back().push_back(x->val);
            }
            f=1;
        }
        int ans=0;
        for(vector<int> n:v){
            ans+=fun(n);
        }
        
        return ans;
    }
    int fun(vector<int>&nums)
	{
	    vector<pair<int,int>> v;
	    int n=nums.size();
	    for(int i=0;i<n;i++){
	        v.push_back({nums[i],i});
	    }
	    sort(v.begin(),v.end());
	    int s=0;
	    for(int i=0;i<n;i++){
	        if(v[i].second==i) continue;
	        else {
	            s++;
	            swap(v[i],v[v[i].second]);
	            i--;
	        }
	    }
	    return s;
	}
};