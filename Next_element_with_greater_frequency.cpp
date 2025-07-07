/*
Problem: Next element with greater frequency
URL: https://www.geeksforgeeks.org/problems/next-element-with-greater-frequency--170637/1
Difficulty: Medium
Timestamp: 01:29 am, 08 Jul 2025
*/

class Solution {
  public:
    vector<int> findGreater(vector<int>& arr) {
        int n = arr.size();
        vector<int>ans(n,-1);
        
        unordered_map<int,int>mp;
        for(int& x: arr)mp[x]++;
        
        stack<int>st;
        
        for(int i = n-1; i>=0; i--){
            while(!st.empty() && mp[arr[i]]>=mp[st.top()]){
                st.pop();
            }
            if(!st.empty() && arr[i]!=st.top())ans[i] = st.top();
            st.push(arr[i]);
        }
        return ans;
    }
};

/*
Notes:
- TC: O(n) | SC: O(n)

- Use a Hashmap to store all the frequencies.
- Then we use a stack and traverse from right to left, and keep popping from the stack till we get a element that has a 
greater (strictly) frequency than the current element.
*/

