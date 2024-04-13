class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> prev(amount+1,0);
        for(int i=0;i<=amount;i++)
        {prev[i]=(i%coins[0]==0);}
        int n=coins.size();
        for(int i=1;i<n;i++)
        {
            for(int t=0;t<=amount;t++)
            {
                int nottake=prev[t];
                int take=0;
                if(t>=coins[i]){take=prev[t-coins[i]];}
                prev[t]=take+nottake;
            }
        }
        return prev[amount];


        
    }
};