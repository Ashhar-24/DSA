/*
Problem: 3330. Find the Original Typed String I
URL: https://leetcode.com/problems/find-the-original-typed-string-i/?envType=daily-question&envId=2025-07-01
Difficulty: Easy
Timestamp: 06:55 pm, 01 Jul 2025
*/

class Solution {
public:
    int possibleStringCount(string word) {
        int n = word.size();

        int cnt = 1;
        int i = 0, j = 0;

        while(j<n-1){
            if(word[j]==word[j+1]){
                while(word[i]==word[j])j++;
                // cout<< (j-i-1)<<endl;
                cnt += (j-i-1);
            }
            else{
                j++;
            }
            i = j;
        }
        return cnt;
    }
};

/*
Notes:
Application of two pointers
*/

