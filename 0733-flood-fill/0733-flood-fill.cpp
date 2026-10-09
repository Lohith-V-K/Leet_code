class Solution{
    public:
    void dfs(vector<vector<int>>&image,int oldcolor,int newcolor,int row,int col)
    {
        int nrow=image.size();
        int ncol=image[0].size();
        if( row<0 || row>=nrow || col<0 || col>=ncol)
        {
            return ;
        }
        if(image[row][col]!=oldcolor)
        {
            return ;
        }
        image[row][col]=newcolor;
        dfs(image,oldcolor,newcolor,row-1,col);
        dfs(image,oldcolor,newcolor,row,col-1);
        dfs(image,oldcolor,newcolor,row+1,col);
        dfs(image,oldcolor,newcolor,row,col+1);
        return ;
    }
    vector<vector<int>> floodFill(vector<vector<int>> &image,
                                  int sr, int sc, int newColor) {
    int m=image.size();
    int n=image[0].size();
    int oldcolor=image[sr][sc];
    if(oldcolor==newColor)
    return image;
    dfs(image,oldcolor,newColor,sr,sc);
    return image;
                                    
      
    }
};
