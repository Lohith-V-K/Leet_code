class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        stack<int>st;
        vector<int>nse(t.size(),0);
        int n=t.size();
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && t[st.top()]<=t[i])
            st.pop();
            (!st.empty())?nse[i]=abs(i-st.top()):0;
            st.push(i);

        }
        return nse;
        
    }
};