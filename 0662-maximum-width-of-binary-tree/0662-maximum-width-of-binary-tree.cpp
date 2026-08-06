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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL)
        {
            return 0;
        }
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        long long maxwidth=0;
        while(!q.empty())
        {
            long long size=q.size();
            long long minindex=q.front().second;
            long long last=0;
            long long first=0;
            for(int i=0;i<size;i++)
            {
                long long currindex=q.front().second-minindex;
                TreeNode* node=q.front().first;
                q.pop();
                if(i==0)first=currindex;
                if(i==size-1)last=currindex;
                if(node->left)
                q.push({node->left,2*currindex+1});
                if(node->right)
                q.push({node->right,2*currindex+2});
            }
            maxwidth=max(maxwidth,last-first+1);
        }
        return maxwidth;
        
        
    }
};