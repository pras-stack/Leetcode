class Solution {
public:
    double myPow(double x, int n) {
       if (n == 0) {
            return 1.0; // Base case: x^0 = 1
        }
        
        double half = myPow(x, n / 2);
        
        if (n % 2 == 0) {
            return half * half; // x^n = (x^2)^(n/2) for even n
        } else if (n > 0) {
            return x * half * half; // x^n = x * (x^2)^(n/2) for positive odd n
        } else {
            return (1 / x) * half * half; // x^n = (1/x) * (x^2)^(n/2) for negative odd n
        }
    }
};