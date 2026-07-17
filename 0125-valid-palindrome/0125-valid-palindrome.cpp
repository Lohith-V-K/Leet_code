class Solution {
public:
    bool isPalindrome(string s) {
        string c="";
        string ans="";
        for(char z:s)
        {
            if(isalnum(z))
            {
                c+=tolower(z);
            }
           
        }
        ans=c;
        reverse(c.begin(),c.end());
        if(c==ans)
        {
            return true;
        }
        else
        {
            return false;
        }
        

        
    }
};