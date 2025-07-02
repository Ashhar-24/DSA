/*
Problem: Longest Substring with K Uniques
URL: https://www.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1
Difficulty: Easy
Timestamp: 03:22 am, 03 Jul 2025
*/

class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        int n = s.size();
        
        unordered_map<int,int>mp;
        int i = 0, j = 0;
        
        int len = 0;
        
        while(j<n){
            mp[s[j]]++;
            while(mp.size()>k){
                mp[s[i]]--;
                if(mp[s[i]]==0){
                    mp.erase(s[i]);
                }
                i++;
            }
            if(mp.size()==k)len = max(len, j - i + 1);
            j++;
        }
        return len == 0 ? -1 : len;
    }
};

/*
Notes:
TC: O(n) | SC: O(n)

- Standard Sliding window and hashing question.
- Shrink the window when no of distinct characters are > k, else when the the distinct elements ==k, update the len.
*/

