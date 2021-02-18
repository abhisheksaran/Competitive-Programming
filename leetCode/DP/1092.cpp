class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        //find the longest common subsequence
    
        int n = str1.size();
        int m = str2.size();
        
        vector<vector<int>> dp (n+1, vector<int> (m+1, 0));
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(str1[i-1]==str2[j-1]) dp[i][j] = 1+ dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp [i][j-1]);
            }
        }
        
        //simulate the subsequence;
        string lcs;
        
        int i =n;
        int j =m;
        while(i>0&&j>0){
            if(str1[i-1]==str2[j-1]){
                lcs.push_back(str1[i-1]);
                i--, j--;
            }
            else if(dp[i-1][j]>dp[i][j-1]){
                i--;
            }
            else j--;
        }
        reverse(lcs.begin(),lcs.end());
        
        cout<<lcs<<"\n";
        //simulate shortest common supersequence given lcs
        string scs = str1;
        //j traverse in ans
        j =0;
        //k traverse in lcs
        int k =0;
        //i traverse in str2
        i=0;
        //traverse as you keep finding lcs
        while(i<m&&k<lcs.size()){
            if(str2[i]==lcs[k]){
                while(scs[j]!=lcs[k]) j++;
                i++;
                j++;
                k++;
            }
            else{
                scs.insert(j,1,str2[i]);
                j++;
                i++;
            }
            cout<<i<<" "<<j<<" "<<k<<"\n";
        }
        
        //insert remaining of string 2 into scs
        while(i<m){
            scs.insert(j,1,str2[i]);
            i++,j++;
        }
        
        return scs;
        
    }
};
/*
*more concise version to simulate scs using lcs
*The idea is to insert lcs chars only once;
for(char c : lcs) {
      while (str1.charAt(i) != c)
         sb.append(str1.charAt(i++));
      while (str2.charAt(j) != c)
         sb.append(str2.charAt(j++));
      sb.append(c);    i++;    j++;
   }
   sb.append(str1.substring(i)).append(str2.substring(j));
*/
