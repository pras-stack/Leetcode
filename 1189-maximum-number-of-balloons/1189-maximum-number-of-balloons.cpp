class Solution {
public:
    int maxNumberOfBalloons(string s)
    {
        int count = 0;
    unordered_map<char, int> h;
    for (char c : s) h[c]++;
    while (h['b'] > 0 && h['a'] > 0 && h['l'] > 1 && h['o'] > 1 && h['n'] > 0)
    {
        h['b']--;
        h['a']--;
        h['l'] -= 2;
        h['o'] -= 2;
        h['n']--;
        count++;
    }
    return count ;
    }
};