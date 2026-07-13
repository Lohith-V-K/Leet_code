class Solution {
public:
vector<vector<string>>ans;
void backtracking(int row,int n,vector<string> &boards,
        unordered_set<int> &main_diag,
        unordered_set<int> &anti_diag,
        unordered_set<int> &cols)
        {
            if(row==n)
            {
                ans.push_back(boards);
                return;
            }
            for(int col=0;col<n;col++)
            {
                bool colconflict=cols.count(col)>0;
                bool mainconflict=main_diag.count(row-col)>0;
                bool anticonflict=anti_diag.count(row+col)>0;
                if(colconflict||mainconflict||anticonflict)
                {
                    continue;
                }
                cols.insert(col);
                main_diag.insert(row-col);
                anti_diag.insert(row+col);
                boards[row][col]='Q';
                backtracking(row+1,n,boards,main_diag,anti_diag,cols);
                cols.erase(col);
                main_diag.erase(row-col);
                anti_diag.erase(row+col);
                boards[row][col]='.';
            }
        }
    vector<vector<string>> solveNQueens(int n) {
        vector<string>boards(n,string(n,'.'));
        unordered_set<int>main_diag;
        unordered_set<int>anti_diag;
        unordered_set<int>cols;
        backtracking(0,n,boards,
        main_diag,
        anti_diag,
        cols);
        return ans;
        
    }
};