class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>>a(rowIndex+1,vector<int>(rowIndex+1,0));
        for(int i=0;i<=rowIndex;i++)
        {
            for(int j=0;j<=i;j++)
            {
                if(j==0||j==i)
                {
                    a[i][j]=1;
                }
                else
                {
                    a[i][j]=a[i-1][j-1]+a[i-1][j];
                }
            }
        }
        return a[rowIndex];
    }
};