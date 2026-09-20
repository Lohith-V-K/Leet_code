class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int vis[m][n];
        int cnt=0;
        int cntfresh=0;
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==2){
                q.push({{i,j},0});
                vis[i][j]=2;
                }
                else
                {
                    vis[i][j]=0;
                }
                if(grid[i][j]==1)cntfresh++;
            }
        }
        int tm=0;
        int drow[4]={-1,0,1,0};
        int dcol[4]={0,1,0,-1};
        int t=0;
        while(!q.empty())
        {
            int nrow=q.front().first.first;
            int ncol=q.front().first.second;
            int t=q.front().second;
            q.pop();
            tm=max(tm,t);
            for(int i=0;i<4;i++)
            {
                    int r=nrow+drow[i];
                    int c=ncol+dcol[i];
                    if( r>=0&& r<m && c>=0 && c<n && grid[r][c]==1&&vis[r][c]==0)
                    {
                        q.push({{r,c},t+1});
                        vis[r][c]=2;
                        cnt++;
                    }
                
            }
        }
        if(cnt!=cntfresh)return -1;
        else
        return tm;
    }
};