class Solution {
public:
    int maxSumDivThree(vector<int>& arr) {
        int n = arr.size();
        int remainderOne = INT_MIN;
        int remainderTwo = INT_MIN;
        int remainderZero = 0;
        int remainderOneLast = 0;
        int remainderTwoLast = 0;
        int remainderZeroLast = 0;

        for(int i=1;i<=n;i++){
            remainderOneLast = remainderOne;
            remainderTwoLast = remainderTwo;
            remainderZeroLast = remainderZero;
            if(arr[i-1]%3==0){
                remainderTwo = max(remainderTwoLast, remainderTwoLast + arr [i-1]);
                remainderOne = max(remainderOneLast, remainderOneLast+arr[i-1]);
                remainderZero = remainderZeroLast + arr [i-1];
            }
            else if (arr[i-1]%3==1){
                
                remainderZero = max(remainderZeroLast, remainderTwoLast+arr[i-1]);
                remainderTwo = max(remainderTwoLast, remainderOneLast + arr[i-1]);
                remainderOne = max(remainderZeroLast+arr[i-1],remainderOneLast);
            }
            else {
                remainderTwo = max(remainderZeroLast+arr[i-1], remainderTwoLast);
                remainderZero = max(remainderZeroLast, remainderOneLast+arr[i-1]);
                remainderOne = max(remainderOneLast, remainderTwoLast+arr[i-1]);
            }
            
            //cout<<remainderZero<<" "<<remainderOne<<" "<<remainderTwo<<"\n";
        }
        return remainderZero;
        
    }
};
