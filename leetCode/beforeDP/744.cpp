//timestamp 7/10 13:37
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        //sorted, use uppper bound
        auto it=upper_bound(letters.begin(),letters.end(), target);
        //read question carefullly to understand this if statement
        if(it==letters.end()) return letters[0];
        else return letters[it-letters.begin()];
    }
};
//timestamp 7/10 13:41
