class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();
        int k=n/8;
        int r=n%8;
        return 8*(k*(k+1)/2)+r*(k+1);
    }
};