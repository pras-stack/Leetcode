class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums)
    {
        priority_queue<int, vector<int>, greater<int>> q;   //by default it is a min heap
        for(int i=0; i<nums.size();i++)  //going over the array
        {
            q.push(nums[i]*nums[i]) ;   //push every sq of every didgit into the queue(min heap)
        }
        
        for(int i=0; i<nums.size();i++)  //going over the array
        {
            nums[i]= q.top();  //adding back results to the array
            q.pop();   //after popping next smallest elt will come to the top
        }
        
        return nums;
    }
};