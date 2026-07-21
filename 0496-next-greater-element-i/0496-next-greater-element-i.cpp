class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st;
        int n=nums2.size();
        unordered_map<int,int>ans;
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && st.top()<=nums2[i])
            {
                st.pop();
            }
            if(st.empty()) ans[nums2[i]]=-1;
            else
            ans[nums2[i]]=st.top();
            st.push(nums2[i]);
        }
         vector<int>ans1;
         ans1.reserve(nums1.size());
        for(int x:nums1)
        {

            ans1.push_back(ans[x]);
        }
        return ans1;


        
        
        
    }
};