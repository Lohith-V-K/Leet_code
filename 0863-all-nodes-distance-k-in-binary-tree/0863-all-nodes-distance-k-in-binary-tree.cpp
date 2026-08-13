/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
void MarkParent(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&parent)
{
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty())
    {
        TreeNode* node=q.front();
        q.pop();
        if(node->left)
        {
            q.push(node->left);
            parent[node->left]=node;
        }
        if(node->right)
        {
            q.push(node->right);
            parent[node->right]=node;
        }
    }
}
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>parent;
        MarkParent(root,parent);
        queue<TreeNode*>q;
        q.push(target);
        int currlevel=0;
        unordered_map<TreeNode*,bool>visited;
        visited[target]=true;
        while(!q.empty())
        {
            int size=q.size();
            if(currlevel==k)break;
            currlevel++;
            for(int i=0;i<size;i++)
            {
                TreeNode* node=q.front();
                q.pop();
                if(node->left && !visited[node->left])
                {
                    visited[node->left]=true;
                    q.push(node->left);
                }
                if(node->right && !visited[node->right])
                {
                    visited[node->right]=true;
                    q.push(node->right);
                }
                if(parent[node] && !visited[parent[node]] )
                {
                    q.push(parent[node]);
                    visited[parent[node]]=true;
                }
            }

        }
        vector<int>ans;
        while(!q.empty())
        {
            TreeNode* curr=q.front();
            q.pop();
            ans.push_back(curr->val);
        }
        return ans;
    }
};