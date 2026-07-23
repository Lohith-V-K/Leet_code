class Solution {
public:
vector<int>nse(vector<int> &arr)
{
    stack<int>st;
    int n=arr.size();
    vector<int>ans(n);
    
    for(int i=n-1;i>=0;i--)
    {
        while(!st.empty() && arr[st.top()]>arr[i])
        {
            st.pop();
        }
        ans[i]=!st.empty()?st.top():n;
        st.push(i);

    }
    return ans;
}
    vector<int>nge(vector<int> &arr)
{
    stack<int>st;
     int n=arr.size();
    vector<int>ans(n);
   
    for(int i=n-1;i>=0;i--)
    {
        while(!st.empty() && arr[st.top()]<=arr[i])
        {
            st.pop();
        }
        ans[i]=!st.empty()?st.top():n;
        st.push(i);

    }
    return ans;
}
vector<int>pse(vector<int> &arr)
{
    stack<int>st;
    int n=arr.size();
    vector<int>ans(n);
    
    for(int i=0;i<n;i++)
    {
        while(!st.empty() && arr[st.top()]>=arr[i])
        {
            st.pop();
        }
        ans[i]=!st.empty()?st.top():-1;
        st.push(i);

    }
    return ans;
}
vector<int>pge(vector<int> &arr)
{
    stack<int>st;
    int n=arr.size();
    vector<int>ans(n);
    
    for(int i=0;i<n;i++)
    {
        while(!st.empty() && arr[st.top()]<arr[i])
        {
            st.pop();
        }
        ans[i]=!st.empty()?st.top():-1;
        st.push(i);

    }
    return ans;
}
long long maxsubrange(vector<int> &arr)
{
    vector<int>pge_in=pge(arr);
    vector<int>nge_in=nge(arr);
    int n=arr.size();
    long long sum=0;
    for(int i=0;i<n;i++)
    {
        long long left=i-pge_in[i];
        long long right=nge_in[i]-i;
        long long freq=1LL*left*right;
        long long val=freq*arr[i]*1LL;
        sum+=val;
    }
    return sum;

}
long long minsubrange(vector<int> &arr)
{
    vector<int>pse_in=pse(arr);
    vector<int>nse_in=nse(arr);
    int n=arr.size();
    long long sum=0;
    for(int i=0;i<n;i++)
    {
        long long left=i-pse_in[i];
        long long right=nse_in[i]-i;
        long long freq=1LL*left*right;
        long long val=freq*arr[i]*1LL;
        sum+=val;
    }
    return sum;

}
    long long subArrayRanges(vector<int>& arr) {
        long long minsubsum=minsubrange(arr);
        long long  maxsubsum=maxsubrange(arr);
         return maxsubsum-minsubsum;
        
    }
};