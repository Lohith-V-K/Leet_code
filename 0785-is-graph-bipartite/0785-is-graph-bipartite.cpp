class Solution {
public:
     bool dfs(int node,int col,vector<int>&coloured,vector<vector<int>>&edges)
    {
        coloured[node]=col;
        for(auto it:edges[node])
        {
            if(coloured[it]==-1)
            {
                if(dfs(it,!col,coloured,edges)==false)return false;
            }
            else
            {
                if(coloured[it]==coloured[node])return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& edges) {
        int V=edges.size();
        vector<int>coloured(V,0);
        for(int i=0;i<V;i++)
        {
            coloured[i]=-1;
        }
        for(int i=0;i<V;i++)
        {
            if(coloured[i]==-1)
           if(dfs(i,0,coloured,edges)==false)return false;
        }
        return true;
    }
};