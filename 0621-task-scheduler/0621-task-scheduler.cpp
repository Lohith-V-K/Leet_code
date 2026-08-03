class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<int,int>mp;
        for(char task:tasks)
        {
            mp[task]++;
        }
        priority_queue<int>pq;
        for(auto& entry:mp)
        {
            pq.push(entry.second);
        }
        int time=0;
        while(!pq.empty())
        {
            int i=0;
            int cycle=n+1;
            vector<int>temp;
            while(i<cycle && !pq.empty())
            {
                int cnt=pq.top();
                pq.pop();
                if(cnt>1)
                temp.push_back(cnt-1);
                 time++;
                i++;
            }
               
                for(int val:temp)
                {
                    pq.push(val);
                }
                if(pq.empty())break;
                time+=(cycle-i);

            


        }
        return time;
        
    }
};