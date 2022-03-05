/* Approach 1 : just traverse through the array ,the n keep another array. keep pushing the non zero elements into the new array, also keep a counter which will keep a count of these zeroes.    => T.C.- O(N)
                    S.C. - O(N)
                    

  Approach 2 : keeping a left and a right pointer. 
  */

class Solution {
public:
    void moveZeroes(vector<int>& nums)
    {
        int n = nums.size();
        if(n==0 || n==1)
            return;
        
        int left =0 , right =0;
        int temp;
        
        while(right<n)
        {
            if(nums[right]==0)
                ++right;
            
            else
            {
                temp = nums[left];
                nums[left]= nums[right];
                nums[right]= temp;
                ++left;
                ++right;
            }
        }
    }
};