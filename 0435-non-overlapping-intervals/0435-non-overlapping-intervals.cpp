class Solution {
public:
static bool compare(const vector<int>&a ,const vector<int>&b )
{
    return a[1]<b[1];
}
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),compare);
        int cnt=0;
        int lastendtime=INT_MIN;
        for(int i=0;i<intervals.size();i++)
        {
            if(intervals[i][0]>=lastendtime)
            {
                cnt=cnt+1;
                lastendtime=intervals[i][1];
            }
        }
        return intervals.size()-cnt;

        
    }
};