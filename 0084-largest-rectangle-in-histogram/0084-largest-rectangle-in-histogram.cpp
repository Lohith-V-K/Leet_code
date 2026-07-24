class Solution {
public:
vector<int>findpse(vector<int> & heights)
{
    stack<int>st;
    int n=heights.size();
    vector<int>ans(n);
    for(int i=0;i<n;i++)
    {
    while(!st.empty() && heights[st.top()]>=heights[i])
    {
        st.pop();
    }
        ans[i]=!st.empty()?st.top()+1:0;
        st.push(i);
    }
    return ans;

}
vector<int>findnse(vector<int> & heights)
{
    stack<int>st;
    int n=heights.size();
    vector<int>ans(n);
    for(int i=n-1;i>=0;i--)
    {
    while(!st.empty() && heights[st.top()]>=heights[i])
    {
        st.pop();
    }
        ans[i]=!st.empty()?st.top()-1:n-1;
        st.push(i);
    }
    return ans;
}

    int largestRectangleArea(vector<int>& heights) {
        stack<int>st;
        int n=heights.size();
        vector<int>nse_id=findnse(heights);
        vector<int>pse_id=findpse(heights);
        int maxa=INT_MIN;
        for(int i=0;i<n;i++)
        {
            int width=nse_id[i]-pse_id[i]+1;
            int area=width*heights[i];
            maxa=max(maxa,area);
        }
        return maxa;
        
        
        
    }
};