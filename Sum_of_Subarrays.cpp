/*
Problem: Sum of Subarrays
URL: https://www.geeksforgeeks.org/problems/sum-of-subarrays2229/1
Difficulty: Medium
Timestamp: 08:43 am, 26 Jul 2025
*/

class Solution {
  public:
    int subarraySum(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;
        
        for(int i=0; i<n; i++){
            sum += (arr[i]*(i+1)*(n-i));
        }
        return sum;
    }
};

/*
Notes:
- TC: O(n) | SC: O(1)

- No of times each element occurs in all the subarrays is given by the formula:
(i + 1) * (n - i), where i is the current index.

- We can make use of this formula to ge the number of times each element occured in all the subarryas and calculate the
sum of all the subarrays in O(n) time.
*/

