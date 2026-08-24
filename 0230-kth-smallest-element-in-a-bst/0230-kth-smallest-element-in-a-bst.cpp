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
 int value;
 int cnt=0;
    void traversal(TreeNode* root,int k)
    {
        if(root==NULL)return;
        traversal(root->left,k);
        cnt++;
        if(cnt==k){
        value=root->val;
        return;
        }
        traversal(root->right,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        cnt=0;
        traversal(root,k);
        return value;
        
    }
};