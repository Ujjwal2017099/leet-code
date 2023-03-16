
class Solution {
    int ind ;
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        ind = postorder.size()-1;   
        return fun(inorder,postorder,0,inorder.size()-1);
    }
    
    TreeNode* fun(vector<int>& in, vector<int>& post,int s,int e){
        if(s>e){
            return nullptr;
        }
        
        TreeNode* node = new TreeNode(post[ind]);
        ind--;
        
        if(s == e) return node;
        int pos=-1;
        
        for(int i=s;i<=e;i++){
            if(in[i]==node->val){
                pos = i;
                break;
            }
        }
        
        node->right = fun(in,post,pos+1,e);
        node->left = fun(in,post,s,pos-1);
        
        
        return node;
    }
};