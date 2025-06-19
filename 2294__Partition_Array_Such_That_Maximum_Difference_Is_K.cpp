/*
Problem: 2294. Partition Array Such That Maximum Difference Is K
URL: https://leetcode.com/problems/partition-array-such-that-maximum-difference-is-k/?envType=daily-question&envId=2025-06-19
Difficulty: Easy
Timestamp: 12:47 am, 20 Jun 2025
*/

class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        // int cnt = 0;
        // int i = 0;
        // while(i<n){
        //     i = upper_bound(nums.begin()+i,nums.end(),nums[i]+k) - nums.begin();
        //     cnt++;
        // }

        // Linearly doing the same
        int cnt = 1;
        int start = nums[0];
        for(int i = 0; i<n; i++){
            if(nums[i]-start > k){
                cnt++; 
                start = nums[i];
            }
        }
        return cnt;
    }
};

/*
Notes:
Could be solved in the two ways shown.

- Sorting is important to ensure that we form the min no of subsequences having the difference between the max 
and min element in that subsequence <=k.

- First approach: Using Upper bound successively to find the next starting point of the subsequence.

- Second approach: Counting the number of subsequences using single traversal.
*/

