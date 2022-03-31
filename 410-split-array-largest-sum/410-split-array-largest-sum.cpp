class Solution {
public:
    
    bool isPossible(vector<int>& nums, int mid, int m)
    {
        int sum1 = 0;
        int count = 1;
        for(int i = 0; i < nums.size(); i++)
        {
            if(sum1 + nums[i] <= mid)
            {
                sum1 += nums[i];
            }
            else{
                count++;
                if(count > m || nums[i] > mid)
                {
                    return false;
                }
                sum1 = nums[i];
            }
        }
        return true;
    }
    
    int splitArray(vector<int>& nums, int m)
    {
        int sum = 0, ans = -1;
        for(int i = 0; i< nums.size(); i++)
        
        {
            sum += nums[i];
        }
        int s = 0, e = sum;
        int mid = s + (e-s)/2;
        while(s<=e)
        {
            if(isPossible(nums, mid, m))
            {
                ans = mid;
                e = mid-1;
            }
            else
            {
                s = mid + 1;
            }
            mid = s + (e-s)/2;
        }
        return ans;
    }
};