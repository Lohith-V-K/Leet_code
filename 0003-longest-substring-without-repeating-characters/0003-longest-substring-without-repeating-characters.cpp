class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0,r=0,maxlength=0;
        int n=s.size();
        vector<int>hash(256,-1);
        while(r<n)
        {
            if(hash[s[r]]!=-1)
            {
                l=max(hash[s[r]]+1,l);
            }
            int length=r-l+1;
             hash[s[r]]=r;
            maxlength=max(maxlength,length);
            r++;
        }
        return maxlength;
    }
};