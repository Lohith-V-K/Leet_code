class Solution {
public:
    int longestSubstring(string s, int k) {
        int len=0;
        for(int i=0;i<s.size();i++)
        {
            unordered_map<char,int>mp;
            for(int j=i;j<s.size();j++)
            {
                mp[s[j]]++;
                 int cnt=0;
            for(auto& it:mp)
            {
                if(it.second<k)
                cnt++;
            }
            if(cnt==0)
            {
                len=max(len,j-i+1);
            }
            }
        }
       

        return len;
        
    }
};