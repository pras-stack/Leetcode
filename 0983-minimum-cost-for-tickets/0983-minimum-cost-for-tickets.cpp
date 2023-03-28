class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs)
    {
        int n = days.size();
    vector<int> dp(366, 0); // dp[i] represents the minimum cost to travel up to day i

    for(int i = 1; i <= 365; i++) {
        if(find(days.begin(), days.end(), i) == days.end()) {
            // if the current day is not a travel day, we don't need to buy a ticket
            dp[i] = dp[i-1];
        } else {
            // if the current day is a travel day, we need to decide which ticket to buy
            dp[i] = dp[i-1] + costs[0]; // 1-day pass
            dp[i] = min(dp[i], dp[max(0, i-7)] + costs[1]); // 7-day pass
            dp[i] = min(dp[i], dp[max(0, i-30)] + costs[2]); // 30-day pass
        }
    }

    return dp[365];
    }
};