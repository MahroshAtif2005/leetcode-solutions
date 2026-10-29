class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //select the cheapest day to buy
        //and select the highest one after buying to sell
        int minPrice = prices[0];
        int maxProfit = 0;

        for(int i = 1; i<prices.size(); i++){
            int profitToday = prices[i]-minPrice;
            if(profitToday>maxProfit){
                maxProfit = profitToday;
            }
            if(prices[i]<minPrice){
                minPrice = prices[i];
            }
         }
    return maxProfit;
    }
};