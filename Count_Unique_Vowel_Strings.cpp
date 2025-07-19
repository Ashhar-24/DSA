/*
Problem: Count Unique Vowel Strings
URL: https://www.geeksforgeeks.org/problems/count-unique-vowel-strings/1
Difficulty: Medium
Timestamp: 03:55 pm, 19 Jul 2025
*/

class Solution {
  public:
    int per(int n){
        int ans = 1;
        while(n>1){
            ans *= n;
            n--;
        }
        return ans;
    }
    int vowelCount(string& s) {
        unordered_map<char,int>mp;
        unordered_set<char> st = {'a', 'e', 'i', 'o', 'u'};
        for(char& c: s){
            if(st.find(c)!=st.end())mp[c]++;
        }
        
        int ans = 1;
        for(auto& x : mp){
            ans *= x.second;
        }
        
        int size = mp.size();
        
        return size == 0 ? 0 : ans * per(size);
    }
};

/*
Notes:
- TC: O(n) | SC: O(n)

- We use the concept of PnC, where we need to construct all the possible permutated strings using all the vowels
present in string `s`.

- So, before generating all the permutations, we count the number of possible strings that can be formed using the 
occurrences of the vowels using simple multiplication.
Then for each string in order to generate all the permutations, we simply multiply by n!, where n is the size of the string/map of vowels.
*/

