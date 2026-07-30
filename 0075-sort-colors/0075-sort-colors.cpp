class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int count1=0,count2=0,count0=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==1)count1++;
            if(nums[i]==2)count2++;
            if(nums[i]==0)count0++;
        }
        int k=0;
       while(count0!=0)
       {
        nums[k]=0;
        count0--;
        k++;
       }
       while(count1!=0)
       {
        nums[k]=1;
        count1--;
        k++;
       }
       while(count2!=0)
       {
        nums[k]=2;
        count2--;
        k++;
       }

        
    }
};