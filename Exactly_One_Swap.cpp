/*
Problem: Exactly One Swap
URL: https://www.geeksforgeeks.org/problems/exactly-one-swap--170637/1

Notes:
- As we traverse from left to right, count how many strings are possible by traversing over the hashmap and update the frequency of the current character.
- Check if the given string has a duplicate char or not, if there is, then increase the answer by 1. (as by swapping the identical chars, we will get the same string that is given and if multiple duplicate chars is present, 
the answer will still get increased by 1, as we need distinct strings in our answer, hence just increasing by 1.)
*/

class Solution {
  public:
    int countStrings(string &s) {
        // code here
        int n = s.size();
        vector<int>freq(26,0);
        int ans = 0;
        
        for(int i=n-1; i>=0; i--){
            if(i==n-1){
                freq[s[i]-'a']++;
                continue;
            }
            int cnt = 0;
            for(int j=0; j<26; j++){
                if(j != (int)(s[i]-'a'))cnt += freq[j];
            }
            ans += cnt;
            freq[s[i]-'a']++;
        }
        
        int cnt = 0;
        for(int& x: freq){
            if(x!=0)cnt++;
        }
        if(cnt!=n)ans++;
        
        return ans;
    }
};
