class Solution {
public:
    int maxProfit(vector<int>& a) {
        //max profit it when you go with this strategy
        //and strategy is to buy in the velly and sell it in the peaks; 
        //why?Second, suppose the first sequence is "a <= b <= c <= d", the profit is "d - a = (b - a) + (c - b) + (d - c)" without a doubt. And suppose another one is "a <= b >= b' <= c <= d", the profit is not difficult to be figured out as "(b - a) + (d - b')". So you just target at monotone sequences.

       int profit=0;
        for(int i=1;i<a.size();i++){
            if(a[i]>a[i-1]) {
                profit+=(a[i]-a[i-1]);
            }
        }
        return profit;
        
    }
};
