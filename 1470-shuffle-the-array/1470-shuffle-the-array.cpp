class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) 
    {
            vector<int> shuffled(2*n);
    for (int i = 0; i < 2*n; i++) {
        if (i % 2 == 0)
            shuffled[i] = nums[i/2];
        else
            shuffled[i] = nums[n + (i/2)];
    }
    return shuffled;
    }
};