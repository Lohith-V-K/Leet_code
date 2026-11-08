class Solution {
public:
    void backtrack(vector<string>&res,string currstr,int opencnt,int closecnt,int maxpairs)
    {
        if(currstr.length()==2*maxpairs)
        {
            res.push_back(currstr);
            return;
        }
        if(opencnt<maxpairs)
        {
            backtrack(res,currstr+"(",opencnt+1,closecnt,maxpairs);
        }
         if(closecnt<opencnt)
        {
            backtrack(res,currstr+")",opencnt,closecnt+1,maxpairs);
        }

    }
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        backtrack(res,"",0,0,n);
        return res;
        
    }
};