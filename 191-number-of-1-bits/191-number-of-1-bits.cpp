class Solution {
public:
    int hammingWeight(uint32_t n)
    {
         // base case
    if (n == 0)
        return 0;
 
    else
 
        // if last bit set add 1 else add 0
        return (n & 1) + hammingWeight(n >> 1);
    }
};