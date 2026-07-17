class Solution {
public:
    int trap(vector<int>& height) {
        int left=0,right=height.size()-1;
        int leftmax=INT_MIN,rightmax=INT_MIN;
        int water=0;
        while(left<=right)
        {
            if(height[left]<=height[right])
            {
                leftmax=max(leftmax,height[left]);
                water+=leftmax-height[left];
                left++;
            }
            else
            {
                rightmax=max(rightmax,height[right]);
                water+=rightmax-height[right];
                right--;
            }
        }
        return water;
        
    }
};