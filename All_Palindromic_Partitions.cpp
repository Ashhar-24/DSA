/*
Problem: All Palindromic Partitions
URL: https://www.geeksforgeeks.org/problems/find-all-possible-palindromic-partitions-of-a-string/1
Difficulty: Medium
Timestamp: 11:58 pm, 18 Jun 2025
*/

class Solution {
  public:
    bool isPali(string s){
        int i = 0, j = s.size()-1;
        while(i<j){
            if(s[i++]!=s[j--]) return 0;
        }
        return 1;
    }
    void solve(int ind, string& s, vector<string>&curr, vector<vector<string>>&ans){
        if(ind==s.size()){
            ans.push_back(curr);
            return;
        }
        string temp= "";
        for(int i=ind; i<s.size(); i++){
            temp+=s[i];
            if(isPali(temp)){
                curr.push_back(temp);
                solve(i+1,s,curr,ans);
                curr.pop_back();
            }
        }
    }
    
    vector<vector<string>> palinParts(string &s) {
        vector<vector<string>> ans;
        vector<string>curr;
        solve(0,s,curr,ans);
        
        return ans;
        
    }
};

/*
Notes:
- Recursion + BackTracking 
*/

