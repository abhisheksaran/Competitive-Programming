//18:07
//good question
class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        //set of avilable nr days
        set<int> nr;
        //ans array
        vector<int> ans(rains.size(),-1);
        //storing last day when they get lakes got filled
        unordered_map<int,int> lakes;
        for(int i=0;i<rains.size();i++){
            //if there is no rain insert this day in nr days set
            if(rains[i]==0){
                ans[i]=i+1;
                nr.insert(i);
            }
            //if it rains on lake number rains[i], we have to see if it's dry or full
        
            else{
                //if lake is alrady full
                if(lakes.find(rains[i])!=lakes.end()){
                    //find the first nr days after last time the lakes got full
                    //so that we can use that day to dry this lake to avoud flood
                    auto dryday= nr.lower_bound(lakes[rains[i]]);
                    if(dryday==nr.end()){
                        ans.clear();
                        return ans ;
                    }
                    else {
                        //we will dry this lake on the the next avl nr day
                        ans[*dryday]=rains[i];
                        //erase the day from available nr days set
                        nr.erase(dryday);
                            
                    }
                }
               
             }
            
            //update the last day when a lake got full
            lakes[rains[i]]=i;;
        }
        return ans;
    }
};
/*
Idea is to maintain a set of the indexes of zero and a hashmap of indexes of rain.
Whenever we find a zero in the rains vector, we push it into zero set which maintain the indexes of zero.
If the rains[i] is non-zero, then we see if we have already filled the lake.
If it is already filled, we try to empty it.
We find the last index of rains[i].
Then we find the index of the lake we want to empty which is the next bigger element than the last index of rains[i]. (As we can't empty the lake before it is filled).
If, no such zero slot is found, the lake will be flooded, hence return an empty result.
Once zero is filled, erase it from the set.
*/
//18:59
