/*
Problem: Coin Piles
URL: https://www.geeksforgeeks.org/problems/coin-piles5152/1
Difficulty: Medium
Timestamp: 06:53 pm, 18 Jun 2025
*/

class Solution {
  public:
    int minimumCoins(vector<int>& arr, int k) {
        int n = arr.size();
        
        sort(arr.begin(), arr.end());
        
        vector<int>pref(n);
        pref[0] = arr[0];
        for(int i = 1; i<n; i++) pref[i] = pref[i-1] + arr[i];
        
        int ans = INT_MAX, sumLeft = 0;
        
        for(int i = 0; i<n; i++){
            if(i>0) sumLeft = pref[i-1];
            int ind = upper_bound(arr.begin(), arr.end(), arr[i]+k) - arr.begin();
            int no_ele = n - ind;
            int sum = pref[n-1] - pref[ind-1];
            int sumRight = sum - ((arr[i]+k)*no_ele);
            ans = min(ans, sumLeft+sumRight);
        }
        
        return ans;
        
    }
};

/*
Notes:
- TC: O(nlogn), SC: O(n)

- Since the question asked us to find the minimum coins to remove so that the condition met,
we "sorted" the array, as this would ensure that the difference is easy calculated.
- This would've been solved using "Two-pointers" if there wasn't given that we could remove the entire pile.
This change in the question, where we can remove an entire pile makes the question to think more.
- So, for each number "arr[i]", we use the upper bound and check till where we can get "arr[i]+k", then using the 
logic of prefix sum, we calculate the no of coins to be removed.
- And since, we need to store the min coins to be removed, we approach this greedily and check for each number.

(Logic for using "sumLeft" is that if we are at an index (element "x"), we keep this "x" as the base and then calculate the range.
So obviously the nos, beyond "x + k", will also be out of bound for the elements smaller to x, and since we 
cannot increase the elements we can only decrease, we are bound to remove these elements, hence we take them
in our "sumLeft")
*/

