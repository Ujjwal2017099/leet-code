TreeNode* ptr = NULL ;
TreeNode *root2 = NULL ;

class Solution {
public:
    TreeNode* create(int v)
    {        
        if(!root2){root2 = new TreeNode(v) ; ptr = root2;}
        else {root2->right = new TreeNode(v); root2 = root2->right;}
        return ptr;
    }
    TreeNode* inorder(TreeNode* root)
    {
        if(root == NULL) return NULL;
        
        inorder(root->left );
        
        TreeNode* ptr2 = create(root->val);
        
        inorder(root->right);
        
        return ptr2;
        
    }
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* newRoot = NULL , *prev = NULL;
        newRoot = inorder(root);
        ::ptr = NULL;
        ::root2 = NULL;
        return newRoot;
    }
};