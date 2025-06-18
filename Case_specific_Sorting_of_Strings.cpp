/*
Problem: Case-specific Sorting of Strings
URL: https://www.geeksforgeeks.org/problems/case-specific-sorting-of-strings4845/1
Difficulty: Easy
Timestamp: 12:34 am, 19 Jun 2025
*/

class Solution {
  public:
    string caseSort(string& s) {
        int n = s.size();
        
        vector<int>cap(26,0), small(26,0);
        for(char c: s){
            if(c>='A' && c<='Z')cap[c-'A']++;
            else small[c-'a']++;
        }
        
        int x = 0, y = 0;

        for(int i=0; i<n; i++){
            if(s[i]>='A' && s[i]<='Z'){
                while(cap[x]==0)x++;
                s[i] = char('A' + x);
                cap[x]--;
            }
            else{
                while(small[y]==0)y++;
                s[i] = char('a' + y);
                small[y]--;
            }
        }
        return s;
        
    }
};

/*
Notes:
TC : O(n + 26) ~ O(n)
SC : O(26) ~ O(1)

- Store the frequency of upper and lower case separately in a frequency array.
- Then using two-pointers, one pointer at cap-case freq. array and the other at small-case freq. array, we traverse the given string.
- Then if the current character is capital, we change it to the sorted wise capital letter.
- Else if it is small case, we change it to the sorted wise small letter.
*/

