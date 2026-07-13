class Solution {
public:
vector<string>ans;
void backtracking(int index,string &s){
    if(index==s.length())
    {
        ans.push_back(s);
        return;
    }
    backtracking(index +1,s);
    if(isalpha(s[index]))
    {
        s[index]^=32;
        backtracking(index+1,s);
        s[index]^=32;
    }

}
    vector<string> letterCasePermutation(string s) {
        int n;
        n=s.length();
        backtracking(0,s);
        return ans;
        


        
    }
};