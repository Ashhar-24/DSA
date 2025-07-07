/*
Problem: Next Greater Element in Circular Array
URL: https://www.geeksforgeeks.org/problems/next-greater-element/1
Difficulty: Medium
Timestamp: 08:51 pm, 07 Jul 2025
*/

class Solution {
  public:
    vector<int> nextLargerElement(vector<int> &arr) {
        int n = arr.size();
        stack<int>stk;
        
        vector<int>ans(n,-1);
        
        for(int i = (2*n-1); i>=0; i--){
            int curr = arr[i%n];
            
            while(!stk.empty() && stk.top() <= curr){
                stk.pop();
            }
            
            if(i<n && !stk.empty())ans[i] = stk.top();
            
            stk.push(curr);
            
        }
        
        return ans;
    }
};

/*
Notes:
TC: O(n) | SC: O(n)

- For circular array we traverse from i = 2n-1 till i = 0. We use (%) so that the element is within the bound.
- We keep popping the element from the stack, until the top element > curr.
If it is this would be the NGE.

- We then push the current element into the stack to make it a candidate for the NGE. (A greedy method)
*/

