class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
            pair<int,int>source={0,0};
            pair<int,int>destination={grid.size()-1,grid[0].size()-1};
                       int m=grid.size();
                        int n=grid[0].size();
                        if(grid[source.first][source.second]==1||grid[destination.first][destination.second]==1)
                        return -1;
                        if(source==destination)
                        return 1;
                        vector<vector<int>>dis(m,vector<int>(n,1e9));
                        dis[source.first][source.second]=1;
                        queue<pair<int,pair<int,int>>>q;
                        q.push({1,{source.first,source.second}});
                        int dr[]={-1,-1,-1,0,0,1,1,1};
                        int dc[]={-1,0,1,-1,1,-1,0,1};
                        while(!q.empty())
                        {
                            auto it=q.front();
                            q.pop();
                           int dist=it.first;
                           int row=it.second.first;
                           int col=it.second.second;
                           for(int i=0;i<8;i++)
                           {
                            int nrow=row+dr[i];
                            int ncol=col+dc[i];
                            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && grid[nrow][ncol]==0 && dist+1<dis[nrow][ncol]){
                            dis[nrow][ncol]=dist+1;
                            if(nrow==destination.first && ncol==destination.second) return dist+1;
                            q.push({dist+1,{nrow,ncol}});
                           }
                           }
                        }
                        return -1;

       
        
    }
};