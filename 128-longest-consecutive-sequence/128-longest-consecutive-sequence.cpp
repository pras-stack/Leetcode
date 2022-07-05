class Solution {
public:
    int longestConsecutive(vector<int>& nums)
    {
	unordered_set<int> s(begin(nums), end(nums)); // inserting all elements into hashset
	int longest = 0;
	for(auto& num : s)
    {
		int cur_longest = 1;
		// find consecutive elements in the backward and forward direction from num
		for(int j = 1; s.count(num - j); j++) s.erase(num - j), cur_longest++;
		for(int j = 1; s.count(num + j); j++) s.erase(num + j), cur_longest++;
		longest = max(longest, cur_longest);  // update longest to hold longest consecutive sequence till now
	}
	return longest;
}
/*Python

def longestConsecutive(self, nums: List[int]) -> int:
	longest, s = 0, set(nums)
	for num in nums:
		cur_longest, j = 1, 1
		while num - j in s: 
			s.remove(num - j)
			cur_longest, j = cur_longest + 1, j + 1
		j = 1
		while num + j in s: 
			s.remove(num + j)
			cur_longest, j = cur_longest + 1, j + 1
		longest = max(longest, cur_longest)
	return longest
Time Complexity : O(N)
Space Complexity : O(N)

✔️ Solution - III (Using Hashset - w/ optimizations)

We can form a solution without the need to spend time erasing elements from the hashset.

Instead of taking the first element that we find in the hashset and iterating both forward and backward, we can just keep skipping till we find that hashset contains num - 1. Finally, we can just iterate in the forward direction till we find consecutive elements in hashset and update longest at the end

C++

int longestConsecutive(vector<int>& nums) {
	unordered_set<int> s(begin(nums), end(nums));
	int longest = 0;
	for(auto& num : s) {
        if(s.count(num - 1)) continue;
		int j = 1;
		while(s.count(num + j)) j++;
		longest = max(longest, j);
	}
	return longest;
} */
};