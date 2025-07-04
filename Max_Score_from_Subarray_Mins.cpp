/*
Problem: Max Score from Subarray Mins
URL: https://www.geeksforgeeks.org/problems/max-sum-in-sub-arrays0824/1
Difficulty: Easy
Timestamp: 12:22 am, 05 Jul 2025
*/

class Solution {
  public:
    int maxSum(vector<int> &arr) {
        // code here
        int n = arr.size();
        
        int sum = 0;
        for(int i = 0; i<n-1; i++){
            sum = max(sum, arr[i]+arr[i+1]);
        }
        
        return sum;
    }
};

/*
Notes:
TC: O(n) | SC: O(1)

- Pure greedy approach that if we take more than 2 elements in the subarray, we would decrease the min elements
and our sum decreases, which we don't want. 
We want to maximize our sum , which can be only done if we take the adjacent elements as these would be only case to
maximize the sum by maximizing the smallest and 2nd smallest element.
*/

