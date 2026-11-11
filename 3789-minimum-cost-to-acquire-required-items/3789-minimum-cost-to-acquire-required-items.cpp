class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costboth, int need1, int need2) {
        if(costboth<cost1 && costboth<cost2)
        {
            return (long long)costboth*max(need1,need2);
        }
        if(costboth<cost2 && costboth>=cost1)
        {
            if(need1<need2)
            return (long long)costboth*need2;
            else
            return (long long)costboth*need2+(long long)cost1*(need1-need2);
        }
         if(costboth>=cost2 && costboth<cost1)
        {
            if(need2<need1)
            return (long long)costboth*need1;
            else
            return (long long)costboth*need1+(long long)cost2*(need2-need1);
        }
        if(costboth<cost1+cost2)
        {
            long long overlap=min(need1,need2);
            return (overlap*costboth)+(long long)cost1*(need1-overlap)+(long long)cost2*(need2-overlap);
        }
            return (long long)cost1*need1+(long long)cost2*need2;

    }
};