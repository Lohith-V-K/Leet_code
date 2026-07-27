class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int>freq(26,0);
        int left=0;
        int right=0;
        int maxlength=0;
        int mostfreq=0;
        int n=s.size();
        while(right<n)
        {
            freq[s[right]-'A']++;
            mostfreq=max(mostfreq,freq[s[right]-'A']);
            while((right-left+1)-mostfreq>k)
            {
              freq[s[left]-'A']--;
              left++;  
            }
            maxlength=max(maxlength,right-left+1);
            right++;
        }
        return maxlength;
        
    }
};