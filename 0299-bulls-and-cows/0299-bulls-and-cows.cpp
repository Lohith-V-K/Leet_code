class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int>secret_c(10,0);
        vector<int>guess_c(10,0);
        int cows=0;
        int bulls=0;
        for(int i=0;i<secret.size();i++)
        {
            if(secret[i]==guess[i])
            {
                bulls++;
            }
            else
            {
                secret_c[secret[i]-'0']++;
                guess_c[guess[i]-'0']++;
            }
        }
        for(int i=0;i<10;i++)
        {
            cows+=min(secret_c[i],guess_c[i]);
        }
        return to_string(bulls)+"A"+to_string(cows)+"B";
    }
};