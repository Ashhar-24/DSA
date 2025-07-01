/*
Problem: Longest subarray with Atmost two distinct integers
URL: https://www.geeksforgeeks.org/problems/fruit-into-baskets-1663137462/1
Difficulty: Easy
Timestamp: 01:53 am, 02 Jul 2025
*/

class Solution {
  public:
    int totalElements(vector<int> &arr) {
        int n = arr.size();
        
        unordered_map<int,int>mp;
        int i = 0, j = 0, len = 0;
        
        while(j<n){
            mp[arr[j]]++;
            
            while(i<j && mp.size()>2){
                mp[arr[i]]--;
                if(mp[arr[i]]==0)mp.erase(arr[i]);
                i++;
            }
            
            len = max(len, j - i + 1);
            
            j++;
        }
        
        return len;
    }
};

/*
Notes:
TC: O(n) | SC: O(n)

- Standard sliding window using hashmap.
- We add the element into the map, and then check if the size of the map exceed 2, if yes, we shrink the window.

- After shrinking/checking, we update our length of the window.
*/

