class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        int n = triangle.size();
        vector<int> pathSums(triangle.back());

        for (int layer = n - 2; layer >= 0; layer--)
        {
            for (int i = 0; i <= layer; i++) 
            {
                pathSums[i] = min(pathSums[i], pathSums[i + 1]) + triangle[layer][i];
            }
        }

        return pathSums[0];
    }
};