class Solution {
public:
int minimumsum(vector<int>& cardPoints, int k)
{
    int ans=INT_MAX,currsum=0;
    int start=0;
    for(int i=0;i<cardPoints.size();i++)
    {
        currsum+=cardPoints[i];
        while((i-start+1)>k)
        {
            currsum-=cardPoints[start];
            start++;
        }
        if((i-start+1)==k)
        {
            ans=min(ans,currsum);
        }

    }
    return ans;
}
    int maxScore(vector<int>& cardPoints, int k) {
        int totalsum=0;
        for(int i=0;i<cardPoints.size();i++)
        {
            totalsum+=cardPoints[i];
        }
        int windowsize=cardPoints.size()-k;
        int minsum=minimumsum(cardPoints,windowsize);
        return totalsum-minsum;
        
        
    }
};