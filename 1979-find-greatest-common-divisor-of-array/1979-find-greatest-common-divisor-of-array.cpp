class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mint=*min_element(nums.begin(),nums.end());
        int maxt=*max_element(nums.begin(),nums.end());
        return gcd(mint,maxt);
        
    }
};