class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq; // Deque to store indices of elements in the current window
    vector<int> result; // Vector to store maximum elements for each window

    for (int i = 0; i < nums.size(); i++) {
        // Remove elements from the back of the deque that are smaller than the current element
        while (!dq.empty() && nums[i] >= nums[dq.back()])
            dq.pop_back();

        dq.push_back(i); // Add the current index to the back of the deque

        // If the current index minus the front index of the deque is equal to or greater than k,
        // remove the front element from the deque as it is outside the current window.
        if (i - dq.front() >= k)
            dq.pop_front();

        // Store the maximum element (the front element of the deque) if the current index is greater than or equal to k-1
        if (i >= k - 1)
            result.push_back(nums[dq.front()]);
    }

    return result;
    }
};