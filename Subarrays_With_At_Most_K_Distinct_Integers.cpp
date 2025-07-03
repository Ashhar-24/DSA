/*
Problem: Subarrays With At Most K Distinct Integers
URL: https://www.geeksforgeeks.org/problems/subarrays-with-at-most-k-distinct-integers/1
Difficulty: Easy
Timestamp: 12:17 am, 04 Jul 2025
*/

class Solution {
  public:
    int countAtMostK(vector<int> &nums, int k) {
        int n = nums.size();
        
        unordered_map<int,int>mp;
        int i = 0, j = 0, cnt = 0;
        
        while(j<n){
            mp[nums[j]]++;
            
            while(mp.size()>k){
                mp[nums[i]]--;
                if(mp[nums[i]]==0)mp.erase(nums[i]);
                i++;
            }
            
            cnt += (j - i + 1);
            j++;
        }
        return cnt;
    }
};

/*
Notes:
TC: O(n) | SC: O(n)

- Counting the number of subarrays having atmost k-distinct elements.
- Shrink the window when the count of distinct elements exceeds k.
*/

