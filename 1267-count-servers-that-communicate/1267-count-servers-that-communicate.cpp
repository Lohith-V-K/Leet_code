class Solution {
public:
    int bfs(int i,int j,vector<vector<int>>&visited,vector<vector<int>>& grid)
    {
        int count=1;
        visited[i][j]=1;
        queue<pair<int,int>>q;
        q.push({i,j});
        while(!q.empty())
        {
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int i=0;i<grid[0].size();i++)
            {
                if(i!=col)
                {
                if(grid[row][i]==1&& !visited[row][i])
                {
                    count++;
                    visited[row][i]=1;
                    q.push({row,i});
                }
                }
            }
            for(int i=0;i<grid.size();i++)
            {
                if(i!=row)
                {
                if(grid[i][col]==1 && !visited[i][col])
                {
                    count++;
                    visited[i][col]=1;
                    q.push({i,col});
                }
                }
            }

        }
        return count;
    }
    int countServers(vector<vector<int>>& grid) {
        int cnt=0;
        int total=0;
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>visited(grid.size(),vector<int>(grid[0].size(),0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(visited[i][j]==0 && grid[i][j]==1)
                {
                   cnt=bfs(i,j,visited,grid);
                   if(cnt>1){
                    total+=cnt;
                    cnt=0;
                   }
                }
            }
        }
        return total;
    }
};