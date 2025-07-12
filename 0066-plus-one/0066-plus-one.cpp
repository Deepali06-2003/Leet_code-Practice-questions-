class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
    
    for (int i = n - 1; i >= 0; i--) {
        if (digits[i] < 9) {
            digits[i] += 1;
            return digits; // done, no carry needed
        }
        digits[i] = 0; // carry over
    }

    // If we're here, it means all digits were 9 -> [9,9,9] becomes [1,0,0,0]
    digits.insert(digits.begin(), 1);
    return digits;
    }
};