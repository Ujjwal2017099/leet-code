
class Solution {
    int ind = 0;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return fun(preorder,inorder,0,inorder.size()-1);   
    }
    TreeNode* fun(vector<int>& pre,vector<int>& in,int s,int e){
        if(s>e) return nullptr;
        
        TreeNode* node = new TreeNode(pre[ind]);
        ind++;
        if(s==e) return node;
        int pos = -1;
        for(int i=s;i<=e;i++){
            if(in[i] == node->val) {
                pos = i;
                break;
            }
        }
        
        node->left = fun(pre,in,s,pos-1);
        node->right = fun(pre,in,pos+1,e);
        
        return node;
    }
};