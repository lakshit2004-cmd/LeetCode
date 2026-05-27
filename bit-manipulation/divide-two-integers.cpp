class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle the overflow case per requirements
        if (dividend == -2147483648 && divisor == -1) return 2147483647;

        // Determine sign
        bool isNegative = (dividend < 0) ^ (divisor < 0);

        // Convert to unsigned by casting first, then negating using unsigned logic
        // This avoids the "negation of -2147483648" error entirely
        unsigned int uDivd = (dividend < 0) 
            ? (0U - static_cast<unsigned int>(dividend)) 
            : static_cast<unsigned int>(dividend);
            
        unsigned int uDivs = (divisor < 0) 
            ? (0U - static_cast<unsigned int>(divisor)) 
            : static_cast<unsigned int>(divisor);

        unsigned int quotient = 0;

        // Standard bit-shifting division
        for (int i = 31; i >= 0; --i) {
            if ((uDivd >> i) >= uDivs) {
                quotient |= (1U << i);
                uDivd -= (uDivs << i);
            }
        }

        // Using 0U - quotient for the negative case is also sanitizer-safe
        if (isNegative) {
            unsigned int negQuotient = 0U - quotient;
            return static_cast<int>(negQuotient);
        }
        
        return static_cast<int>(quotient);
    }
};