class Solution{
public:
    void bfs(vector<vector<char>>&grid,int row,int col,vector<vector<int>>&vis,int m ,int n)
    {
        queue<pair<int,int>>q;
        vis[row][col]=1;
        q.push({row,col});
        while(!q.empty())
        {
            int rows=q.front().first;
            int cols=q.front().second;
            q.pop();
            int delrow[]={-1,0,1,0};
            int delcol[]={0,1,0,-1};
                for(int i=0;i<4;i++)
                {
                    int nnrow=rows+delrow[i];
                    int nncol=cols+delcol[i];
                    if(nnrow>=0 && nnrow<m && nncol>=0 && nncol<n && grid[nnrow][nncol]=='1' && vis[nnrow][nncol]==0)
                    {
                        vis[nnrow][nncol]=1;
                        q.push({nnrow,nncol});
                    }
                }
            
        }
    }

    int numIslands(vector<vector<char>> &grid){
        int m=grid.size();
        int n=grid[0].size();
        int cnt=0;
        vector<vector<int>>vis(m,vector<int>(n,0));

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(vis[i][j]==0 && grid[i][j]=='1')
                {
                    vis[i][j]=1;
                    cnt++;
                    bfs(grid,i,j,vis,m,n);
                }
            }
        }
        return cnt;
    }
};