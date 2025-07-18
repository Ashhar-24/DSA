/*
Problem: 2163. Minimum Difference in Sums After Removal of Elements
URL: https://leetcode.com/problems/minimum-difference-in-sums-after-removal-of-elements/
Difficulty: Hard
Timestamp: 08:25 pm, 18 Jul 2025
*/

class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int m = nums.size();
        int n = m/3;

        priority_queue<int, vector<int>, greater<int>>right;
        priority_queue<int>left;

        vector<long long>temp(m);

        // right to left
        long long currSum = 0;
        for(int i = m - 1; i>= n; i--){
            currSum += nums[i];
            right.push(nums[i]);
            
            if(right.size()>n){
                currSum -= right.top();
                right.pop();
            }
            if(right.size()==n)temp[i] = currSum;
        }
        
        // left to right
        currSum = 0;
        long long ans = LLONG_MAX;
        for(int i=0; i<m-n; i++){
            currSum += nums[i];
            left.push(nums[i]);

            if(left.size()>n){
                currSum -= left.top();
                left.pop();
            }
            if(left.size()==n){
                ans = min(ans, currSum - temp[i+1]);
            }
        }

        return ans;
    }
};

/*
Notes:
- TC: O(nlogn) | SC: O(n)

- In order to partition the array, we first calculate the SUMsecond and try to maximize the rightSum using heap.
And store the answer in an array `temp`.

- Then we traverse from left to right, and calculate the min sum of n elements.

- This greedy approach helps to efficiently calculate the minimum difference possible by ignoring the
subsequence of `n` length, as our focus is now to select the `n` length subsequence with max and min sum.
*/

