class Solution {
public:

     void dfs(int row,int col,vector<vector<int>>&vis,vector<vector<char>>&mat)
    {
        vis[row][col]=1;
        int m=mat.size();
        int n=mat[0].size();
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        for(int i=0;i<4;i++)
        {
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && !vis[nrow][ncol] && mat[nrow][ncol]=='O')
            {
                vis[nrow][ncol]=1;
                dfs(nrow,ncol,vis,mat);
            }
        }
        return;
    }
    void solve(vector<vector<char>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i=0;i<n;i++)
        {
            if(mat[0][i]=='O' && !vis[0][i])
                dfs(0,i,vis,mat);

            if(mat[m-1][i]=='O' && !vis[m-1][i])
                dfs(m-1,i,vis,mat);

        }
        for(int j=0;j<m;j++)
        {
            if(mat[j][0]=='O' && !vis[j][0])
                dfs(j,0,vis,mat);
            if(mat[j][n-1]=='O' && !vis[j][n-1])
                dfs(j,n-1,vis,mat);
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!vis[i][j] && mat[i][j]=='O')
                    mat[i][j]='X';
            }
        }
        
    }
};
 