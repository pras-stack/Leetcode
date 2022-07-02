class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        if(nums2.size() < nums1.size())
            return findMedianSortedArrays(nums2,nums1);
        
        int n= nums1.size();
        int m= nums2.size();
        int l=0, r=n;
        while(l<=r)
        {
            int c1=(l+r)/2;
            int c2=(n+m+1)/2 - c1;
            
            int l1 = (c1==0) ? INT_MIN : nums1[c1-1];
            int l2 = (c2==0) ? INT_MIN : nums2[c2-1];
            int r1 = (c1==n) ? INT_MAX : nums1[c1];
            int r2 = (c2==m) ? INT_MAX : nums2[c2];
            
            if(l1<= r2 && l2<=r1)
            {
                if((n+m) & 1)
                    return max(l1,l2);
                else
                    return (max(l1,l2) + min(r1,r2))/2.0;
            }
            else if(l1>l2)      r=c1-1;
            else l= c1+1;
            
        }
        return 0.0;
        
    }
};