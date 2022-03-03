class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) 
    {
        int total =0; // total is the subarrays we want
        int n = nums.size();
        int c=0;
        for(int i=0; i< n-1; i++) //iterate(n-1) bcoz we always have to choose 2 elmnts.
        {
            
            int diff= nums[i+1]- nums[i];  // we find diff btw the ith and [i-1]th no.
            for(int j=i+2; j<n; j++)   //then for (i+2)
            {
                if(nums[j]- nums[j-1]== diff) //if diff btwn [i+2]& prev no. is eq to diff, if yes then we keep incremnting the total
                    total ++;
            else break; // if not then break
            
        }
    }
    return total;
}
};