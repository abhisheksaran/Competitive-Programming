class Solution {
public:
    //seems a very good q
    int findKthPositive(vector<int>& arr, int k) {
        
        
        int i=0;
        int j=arr.size()-1;
        int m;
        while(i<j){
            m=i+(j-i)/2;
            if(arr[m]-m-1<k) i=m+1;
            else j=m;
        }
        cout<<j<<" "<<k<<endl;
        return j+k;
        
        
    }
};
