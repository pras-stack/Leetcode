class Solution {
public:
    int fib(int n)
    {
        int memo[31] = {0};        //optimised solution
    
    {
        if(n<=1)
            return n;
        if(memo[n])
            return memo[n];
        return memo[n] = fib(n-1) + fib(n-2);
    }
    }
};