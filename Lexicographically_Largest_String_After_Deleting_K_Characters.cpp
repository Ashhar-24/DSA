/*
Problem: Lexicographically Largest String After Deleting K Characters
URL: https://www.geeksforgeeks.org/problems/lexicographically-largest-string-after-deleting-k-characters/1
Difficulty: Medium
Timestamp: 10:27 pm, 24 Jun 2025
*/

class Solution {
  public:
    string maxSubseq(string& s, int k) {
        int n = s.size();
        string ans;
        ans.push_back(s[0]);
        
        for(int i = 1; i<n; i++){
            while(k>0 && !ans.empty() && ans.back()<s[i]){
                ans.pop_back();
                k--;
            }
            ans.push_back(s[i]);
        }
            while(k>0 && !ans.empty()){
                ans.pop_back();
                k--;
            }
        return ans;
    }
};

/*
Notes:
- TC: O(n) | SC: O(n)
(The key observation is that each character is pushed exactly once into ans and popped at most once (due to k--), which gives:
⏱ Total time spent in all inner loop executions combined = O(n) )

- We push the char into our `ans` variable (which we are using as a stack, to avoid space) until the current char is smaller than the available last char.
- If the current char (s[i]), is greater then we keep on popping the elements till either `k` finishes (or) the char gets smaller to the last char.
- A greedy approach is what we are applying.


*/

