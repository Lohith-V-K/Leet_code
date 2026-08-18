class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int largest=-1;
         unordered_map<int,int>hash;
         if(nums.size()==k)
         {
            largest=*max_element(nums.begin(),nums.end());
            return largest;
         }
        for(int i=0;i<nums.size()-k+1;i++)
        {
            for(int j=i;j<i+k;j++)
            {
                hash[nums[j]]++;

            }
        }
       for(auto const&[key,val]:hash)
       {
        if(val==1)
        largest=max(largest,key);
       }
        return largest;

    }
};