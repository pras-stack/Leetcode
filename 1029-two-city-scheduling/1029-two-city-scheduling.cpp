class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) 
    {
        int n = costs.size();
        vector<int> costDiff(n);
        
        int totalCityACost =0;
        
        for(int i=0; i<n;i++)
        {
            totalCityACost += costs[i][0];
            costDiff[i] = costs[i][1] - costs[i][0];
            
        }
        sort(costDiff.begin(), costDiff.end());
        
        for(int i=0; i<n/2;i++)
        {
            totalCityACost += costDiff[i];
        }
        
        return totalCityACost;
    }
};