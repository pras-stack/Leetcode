class Solution {
public:
    
    int firstocc(vector<int>& nums,  int n, int target)
    {
        int l=0, r=n-1;
        int fo =-1;
        
        while(l<=r)
        {
            int mid = (l+r)/2;
            
            if(nums[mid]< target)
            {
                l= mid +1;
            }
            else if (nums[mid]> target)
            {
                r= mid-1;
            }
            else
            {
                fo =mid;
                r=mid-1;
            }
        }
        return fo;
    }
    
    
    int lastocc(vector<int>& nums,  int n, int target)
    {
        int l=0, r=n-1;
        int lo =-1;
        
        while(l<=r)
        {
            int mid = (l+r)/2;
            
            if(nums[mid]< target)
            {
                l= mid +1;
            }
            else if (nums[mid]> target)
            {
                r= mid-1;
            }
            else
            {
                lo =mid;
                l=mid+1;
            }
        }
        return lo;
    }
    
    
    
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        int n= nums.size();
        
        int fo= firstocc( nums,   n, target);
        int lo= lastocc( nums,   n, target);
        return {fo, lo};
    }
};