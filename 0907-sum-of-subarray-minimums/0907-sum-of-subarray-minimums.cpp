class Solution {
public:
vector<int>findnse(vector<int>& arr)
{
    int n=arr.size();
    vector<int>nse(n);
    stack<int>st;
    for(int i=n-1;i>=0;i--)
    {
    while(!st.empty() && arr[st.top()]>=arr[i])
    st.pop();
    nse[i]=!st.empty()?st.top():n;
    st.push(i);
    }
    return nse;

}
vector<int>findpse(vector<int>& arr)
{
    int n=arr.size();
    vector<int>pse(n);
    stack<int>st;
    for(int i=0;i<n;i++)
    {
    while(!st.empty() && arr[st.top()]>arr[i])
    st.pop();
pse[i]=!st.empty()?st.top():-1;
    st.push(i);
    }
    return pse;

}
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int>pse=findpse(arr);
        vector<int>nse=findnse(arr);
        int sum=0;
        int mod=1e9+7;
        for(int i=0;i<n;i++)
        {
            int left=i-pse[i];
            int right=nse[i]-i;
            long long freq=1LL*left*right;
            long long val=(freq*arr[i]*1LL)%mod;
            sum=(sum+val)%mod;

        }
        return sum;
        
    }
};