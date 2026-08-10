class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       unordered_map<string,vector<string>>mp;
       vector<vector<string>>res;
       for(auto& it:strs)
       {
        string sorted=it;
        sort(sorted.begin(),sorted.end());
        mp[sorted].push_back(it);
       }   
       for(auto& it:mp)
       {
        res.push_back(it.second);
       }
       return res;
    }
};