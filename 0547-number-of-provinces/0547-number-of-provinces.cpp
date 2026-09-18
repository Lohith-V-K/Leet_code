class Solution {
public:
    void dfs(int node,vector<int>&visited,vector<vector<int>>&adjlist)
    {
        visited[node]=1;
        for(auto& it:adjlist[node])
        {
            if(!visited[it])
            {
                dfs(it,visited,adjlist);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v=isConnected.size();
        vector<vector<int>>adjlist(v);
        vector<int>visited(v,0);
        int cnt=0;
        for(int i=0;i<v;i++)
        {
            for(int j=0;j<v;j++)
            {
                if(isConnected[i][j]==1 && i!=j)
                {
                    adjlist[j].push_back(i);
                }
            }
        }
            for(int i=0;i<v;i++)
            {
                if(!visited[i]){
                    cnt++;
                    dfs(i,visited,adjlist);
                }
            }
             return cnt;
        }
       

        
    
};