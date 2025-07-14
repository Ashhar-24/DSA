/*
Problem: Divisible by 13
URL: https://www.geeksforgeeks.org/problems/divisible-by-13/1
Difficulty: Easy
Timestamp: 04:50 am, 15 Jul 2025
*/

class Solution {
  public:
    bool divby13(string &s) {
        long long rem = 0;
        for(char c: s){
            rem = (rem * 10 + (c - '0')) % 13;
        }
        
        return rem == 0 ? 1 : 0;
    }
};

/*
Notes:
- TC: O(n) | SC: O(1)

- Standard approach of building a number while applying '%' to keep the number within the bound.
*/

