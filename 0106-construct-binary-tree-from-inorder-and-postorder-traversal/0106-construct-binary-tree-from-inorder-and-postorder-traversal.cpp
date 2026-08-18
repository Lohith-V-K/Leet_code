/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int>mp;
        for(int i=0;i<inorder.size();i++)
        {
            mp[inorder[i]]=i;
        }
        if(inorder.size()!=postorder.size())return nullptr;
        return buildtree(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,mp);
        
    }
    TreeNode* buildtree(vector<int>& inorder,int ins,int ine,vector<int>&postorder,int ps,int pe,unordered_map<int,int>&mp)
    {
        if(ps>pe||ins>ine)return nullptr;
        TreeNode* root=new TreeNode(postorder[pe]);
        int inroot=mp[postorder[pe]];
        int numsleft=inroot-ins;
        root->left=buildtree(inorder,ins,inroot-1,postorder,ps,ps+numsleft-1,mp);
        root->right=buildtree(inorder,inroot+1,ine,postorder,ps+numsleft,pe-1,mp);
        return root;
    }
};