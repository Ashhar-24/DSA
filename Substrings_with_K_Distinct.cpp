/*
Problem: Substrings with K Distinct
URL: https://www.geeksforgeeks.org/problems/count-number-of-substrings4528/1
Difficulty: Medium
Timestamp: 01:36 am, 01 Jul 2025
*/

class Solution {
  public:
    int atmost(string&s, int k){
        int n = s.size();
        
        int cnt = 0;
        int i = 0, j = 0;
        unordered_map<char,int>mp;
        while(j<n){
            mp[s[j]]++;
            
            while(mp.size()>k){
                mp[s[i]]--;
                if(mp[s[i]]==0)mp.erase(s[i]);
                i++;
            }
            cnt += j - i + 1;
            j++;
        }
        return cnt;
    }
    
    int countSubstr(string& s, int k) {
        // code here.
        return atmost(s,k) - atmost(s,k-1);
    }
};

/*
Notes:
- Use of inclusion-exclusion principle is the crux of this question.
*/

