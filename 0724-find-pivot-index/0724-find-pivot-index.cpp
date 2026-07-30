class Solution {
public:
    int pivotIndex(vector<int>& nums) {
       int n=nums.size();
       long long presum=0;
       long long sufsum=0;
       for(int i=0;i<n;i++)
       {
        int left=0;
        int right=n-1;
        presum=0;
        sufsum=0;
        while(left!=i)
        {
            presum+=nums[left];
            left++;
        }
        while(right!=i)
        {
            sufsum+=nums[right];
            right--;
        }
        if(presum==sufsum)return i;
       } 
       return -1;
    }
};