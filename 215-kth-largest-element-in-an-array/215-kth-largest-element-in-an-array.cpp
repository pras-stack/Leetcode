class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        priority_queue<int>pq(nums.begin(), nums.end());  // creating prio queue
        int ans =0;
        while(k--)
        {
            ans = pq.top();
            pq.pop();
        }
        
        return ans;
        
    }
};