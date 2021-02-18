class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        //what do you do when you get lower ele?
        // two choices either increse the curr ele
        // or decrese the last ele 
        // we give priority to second one if possible 
        //and count the number of such modification
        // if it count is greater than 1 we return false
        //else true
        
        
        //simple another method is simply find the breaking point
        //braeking point means where next ele is smaller than prev one
        // if such breaking points are greater than 2
        //for sure it's not possible to make it non-decr with just one modification
        //if breaking point is one
        //no, we don't return true
        //beccause take this example : 5 8 2 3
        //breaking point is one but not possible to make it non decr with just one modification
        //but it's easy now that problem is reduced to smaller space 
        //and we can observer, in which cased it would not be possible
        
        
        
    }
};
