class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int>baskets;
        int left=0;
        int maxlength=0;
        for(int right=0;right<fruits.size();right++)
        {
            baskets[fruits[right]]++;
            while(baskets.size()>2)
            {
                baskets[fruits[left]]--;
                if(baskets[fruits[left]]==0)
                {
                    baskets.erase(fruits[left]);
                }
                left++;
            }
            maxlength=max(maxlength,right-left+1);
        }
        return maxlength;


        
    }
};