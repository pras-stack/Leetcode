class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) 
    {
         int n = s.length();
    int left = 0, right = 0;
    int cost = 0;
    int maxLen = 0;

    while (right < n) {
        cost += abs(s[right] - t[right]); // Calculate the cost of changing the character at the right index.

        while (cost > maxCost) { // Shrink the window if cost exceeds maxCost.
            cost -= abs(s[left] - t[left]);
            left++;
        }

        maxLen = max(maxLen, right - left + 1); // Update the maxLen with the current window length.

        right++; // Expand the window to the right.
    }

    return maxLen;
    }
};