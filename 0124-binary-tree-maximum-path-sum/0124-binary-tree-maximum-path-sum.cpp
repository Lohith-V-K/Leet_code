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
int maxi(TreeNode* root,int &maxt)
{
    if(root==NULL)
    return 0;
    int leftsum=max(0,maxi(root->left,maxt));
    int rightsum=max(0,maxi(root->right,maxt));
    maxt=max(maxt,root->val+rightsum+leftsum);
    return root->val+max(leftsum,rightsum);
}
    int maxPathSum(TreeNode* root) {
        int maxt=INT_MIN;
        maxi(root,maxt);
        return maxt;

        
    }
};