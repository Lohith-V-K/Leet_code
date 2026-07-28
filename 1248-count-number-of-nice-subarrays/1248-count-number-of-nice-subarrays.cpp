class Solution {
public:
int atmost(vector<int>&nums, int k)
{
    
     int n=nums.size();
        int left=0,oddcount=0;
        int res=0;
        for(int right=0;right<n;right++)
        {
            if(nums[right]%2!=0) oddcount++;
            while(oddcount>k)
            {
                if(nums[left]%2!=0) oddcount--;
                left++;
            }
            res+=right-left+1;
        }
        return res;
}
    int numberOfSubarrays(vector<int>& nums, int k) {

    return atmost(nums,k)-atmost(nums,k-1); 
    }
};