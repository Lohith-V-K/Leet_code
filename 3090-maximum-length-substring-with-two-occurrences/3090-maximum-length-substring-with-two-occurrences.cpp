class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n=s.size();
        int maxt=0;
        for(int i=0;i<n-1;i++)
        {
            vector<int>hash(27,0);
            for(int j=i;j<n;j++)
            {
                hash[s[j]-'a']++;
                if(hash[s[j]-'a']>2)
                {
                    break;
                }
                  maxt=max(maxt,j-i+1);
            
            }
           
        }
        return maxt;
        
    }
};