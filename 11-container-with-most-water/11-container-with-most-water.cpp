class Solution {
public:
    int maxArea(vector<int>& h)
    {
        int maxArea =0  , start =0, end = h.size()-1;
        while(start <end)
        {
            int height = min(h[start], h[end] );
            int width = end- start;
            
            int currentArea = height*width;
            maxArea = max(currentArea, maxArea);
            
            if(h[start] < h[end])
            {
                start ++;
            }
            else
            {
                end--;
            }
        }
            
        
        return maxArea;
    }
};