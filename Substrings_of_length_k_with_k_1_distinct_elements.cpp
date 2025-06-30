/*
Problem: Substrings of length k with k-1 distinct elements
URL: https://www.geeksforgeeks.org/problems/substrings-of-length-k-with-k-1-distinct-elements/1
Difficulty: Easy
Timestamp: 01:33 am, 01 Jul 2025
*/

class Solution {
  public:
    int substrCount(string &s, int k) {
        int n = s.size();
        
        int i = 0, j = 0;
        unordered_map<char,int>mp;
        int cnt = 0;
        
        while(j<n){
            mp[s[j]]++;
            
            while(j - i + 1 >k){
                mp[s[i]]--;
                if(mp[s[i]]==0)mp.erase(s[i]);
                i++;
            }
            if(mp.size()==k-1 && j-i+1 == k) cnt++;
            j++;
        }
        return cnt;
    }
};

/*
Notes:
A classical sliding window/two - pointer question and usage of hashing.

-NOTE: We shrink the window only when the size increase more than k, and not when the size of map >= k.
*/

