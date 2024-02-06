class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int> ahead(2,0),curr(2,0);
        //base condition is that ahead[0]=ahead[1]=0
        for(int i=n-1;i>=0;i--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                int profit=0;
                if(buy==1){
                    profit=max(-prices[i]+ahead[0],ahead[1]);
                }
                else{profit=max(prices[i]+ahead[1],ahead[0] );}
                curr[buy]=profit;
            }
            ahead=curr;
        }
        return ahead[1];//we need to return the profit when we are at the index 0 and we can buy


        
    }
};