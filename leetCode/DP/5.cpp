class Solution {
public:
    string longestPalindrome(string s) {
       int el=0;
        int er=0;
        int odl=0;
        int odr=0;
        int n=s.length();
        //odd length palindrome calculation
       /* int l=1;
        for(int i=2;i<n;i++){
            if(l-1>=0){
               l--; 
            }
            else l=i-2;
            
            if(s[i]==s[l]){
                if(odr-odl<i-l){
                    odr=i;
                    odl=l;
                }
            }
            else l=i;
                
        } 
            
        
        
        //even length palindrome 
        l=0;
         for(int i=1;i<n;i++){
            if(l-1>=0&&l!=i-1){
               l--; 
            }
            else l=i-1;
            
            if(s[i]==s[l]){
                if(er-el<i-l){
                    er=i;
                    el=l;
                }
            }
            else l=i;
                
        } 
        */
        int l;
        int r;
        //odd
        for(int i=1;i<n;i++){
            l=i-1;
            r=i+1;
            while(l>=0&&r<n&&s[l]==s[r]){
                l--;
                r++;
            }
         
            if(odr-odl<r-l){
                r--;
                l++;
                odr=r;
                odl=l;
            }
        }
      //even
        int temp=0;
        for(int i=1;i<n;i++){
            l=i-1;
            r=i;
            while(l>=0&&r<n&&s[l]==s[r]){
    
                l--;
                r++;
                temp=1;
            }
    
            if(er-el<r-l){
                r--;
                l++;
                
                er=r;
                el=l;
            }
            temp=0;
        }
               
        
        if(odr-odl+1>er-el+1) return s.substr(odl,odr-odl+1);
        else return s.substr(el,er-el+1);
       // string s=substr(odl,odr-odl+1);;
       
    }
};
