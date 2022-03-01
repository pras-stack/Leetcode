// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n)
    {
         int low= 1, high = n, mid ;
 
    
    while( low < high){
        // get the mid value
        int mid= low + (high-low)/2;
            
        // if it is bad, then no need to check right half
        if( isBadVersion( mid) )
            high=mid;
        
        // else no need to check left half ( we can exclude our checking on "mid" becoz we will always get atleast 
        // 1 bad version after "mid", i.e., in the right half)
        else
            low= mid+1;
    }
    
    
    return high;

    }
};