class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) 
    {
        sort(nums.begin(), nums.end());
        int closestSum = nums[0] + nums[1] + nums[2];
        int n = nums.size();
            for(int i = 0;i < n - 1;i++) 
    {
        int p1 = i + 1, p2 = n - 1;
         if(i > 0 and nums[i] == nums[i - 1]) 
             continue;
        while(p1 < p2)
        {

            int sum = nums[i] + nums[p1] + nums[p2];
            if(sum == target) 
                return sum;
            if(abs(sum - target) < abs(target - closestSum)) 
            {
                closestSum = sum;
            } 
            if(sum > target)
            {
                p2--;
            } 
            else
            {
                p1++;
            }
        }
    }
    return closestSum;
}
};