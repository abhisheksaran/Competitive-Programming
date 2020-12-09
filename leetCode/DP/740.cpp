class Solution {
public:
    int deleteAndEarn(vector<int>& arr) {
        if(arr.size()==0) return 0;
        sort(arr.begin(),arr.end());
        int n = arr.size();
        unordered_map <int ,int > um;
        int last1 = -1;
        int last2 = -1;
        for(int i=1;i<n;i++){
            
            if(arr[i]!=arr[i-1]){
                last2 = last1;
                last1 = i-1;
                if(last2>=0) um[i] = last2; 
                //cout<<100<<" "<<um[100]<<"\n";
            }
            
        }
        
        //dp [i] stores the maximum sum ending with arr[i]
        //mx[i] stores the maximum sum possible till index i.
        vector<int> dp (n,0);
        vector<int> mx(n,0);
        //base condition
        dp[0] = arr[0];
        mx[0] = dp[0];
        for(int i=1;i<n;i++){
            
            if(arr[i]==arr[i-1]) dp[i] = dp[i-1]+arr[i];
            else if(arr[i]-arr[i-1]>1) dp[i] = arr[i]+ mx[i-1];
            //we have to find the maximum sum possible till last possible index s.t. arr[index]<arr[i]-1 
            else {
                if(um.find(i)==um.end()){
                    dp [i] = arr[i];
                    //cout<<um[arr[i]-1]<<"\n";   
                }
                else{
                    dp[i] = arr[i]+mx[um[i]];
                    cout<<"asdf "<<i<<" "<<um[i]<<" "<<dp[um[i]]<<"\n";
                }
            }
            cout<<dp[i]<<"\n";
            mx[i] = max(mx[i-1],dp[i]);
        }
            
        return mx[n-1];
    }
};
//identification 
//given a array
//have to find optimum
//given two option to pick to delete or not
//seems like knapsack
//Hint 2 - Easier way. it's more like house robbery. Can be done easily with dp of size 10,000 and then linear iteration in dp from 0 to 10k. 

