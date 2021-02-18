class Solution {
public:
    
    int lcs(string s1, string s2){ 
        //return the longest common subsequence size of both strings
        return 0;
    }
    bool isInterleave(string s1, string s2, string s3) {
        //simple
        //hint: Use LCS method
        if (lcs(s1,s3)== s1.size() and lcs(s2,s3) == s2.size()){
            
            //some extra checks like, the size of s3 has to be size od s1+ s2
            //and the frequencies of chars in both the string s1 and s2 should be equal to frequency of each char in s3
            return true;
        }
        
        else return false;
    }
};
/*
 * Can be done using iterative DP as well, in O(m*n) time complexity
 */
