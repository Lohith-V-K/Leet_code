class Solution {
public:
long long countpairtotarget(vector<int>&nums,int target)
{
    int left=0;
    int right=nums.size()-1;
    long long sum=0;
    long long count=0;
    while(left<right)
    {
        sum=nums[left]+nums[right];
        if(sum<=target)
        {
            count+=right-left;
            left++;
        }
        else
        {
            right--;
        }
    }
    return count;

}
    long long countFairPairs(vector<int>& nums, int lower, int upper) {

        sort(nums.begin(),nums.end());
        return countpairtotarget(nums,upper)-countpairtotarget(nums,lower-1);


    }
};