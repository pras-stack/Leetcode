class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) 
    {
        int n = dist.size();
        int left = 1; // Minimum possible speed
        int right = 10000007; // Maximum possible speed (10^7)
        int ans = -1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            double totalHours = 0.0;
            
            for (int i = 0; i < n - 1; i++) {
                totalHours += std::ceil(static_cast<double>(dist[i]) / mid);
            }
            
            totalHours += static_cast<double>(dist[n - 1]) / mid;
            
            if (totalHours <= hour) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        return ans;
    }
};