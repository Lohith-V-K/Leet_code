class Solution {
public:
    string minWindow(string s, string t) {
        if(s.length()==0 || t.length()==0 || t.length()>s.length())return "";
        vector<int>targetchars(128,0);
        vector<int>formedchars(128,0);
        for(char c:t)
        {
            targetchars[c]++;
        }

        int minlength=-1;
        int left=0;
        int minstart=0;
        int formedcharss=0;
        int requiredchars=0;
        int right=0;
        for(int i=0;i<128;i++)
        {
            if(targetchars[i]>0)
            {
                requiredchars++;
            }
        }
        while(right<s.size())
        {
            formedchars[s[right]]++;
            if(targetchars[s[right]]>0 && targetchars[s[right]]==formedchars[s[right]])
            formedcharss++;
            while(left<=right && formedcharss==requiredchars)
            {
                if(minlength==-1||right-left+1<minlength)
                {
                    minlength=right-left+1;
                    minstart=left;
                }
                formedchars[s[left]]--;
                if(targetchars[s[left]]>0 && targetchars[s[left]]>formedchars[s[left]])
                formedcharss--;
                left++;


            }
            right++;
        }
        return minlength==-1?"":s.substr(minstart,minlength);
    }
};