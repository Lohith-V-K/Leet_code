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
    vector<int>arr;
    void traverse(TreeNode* root)
    {
        if(root==NULL)return;
        traverse(root->left);
        arr.push_back(root->val);
        traverse(root->right);
    }
    bool findTarget(TreeNode* root, int k) {
        traverse(root);
        int j=arr.size()-1;
        int sum=0;
        int i=0;
        sort(arr.begin(),arr.end());
        while(i<j)
        {
            sum=arr[i]+arr[j];
            if(sum==k)return true;
            if(sum>k)j--;
            else
            i++;
            
        }
        return false;

        
    }
};