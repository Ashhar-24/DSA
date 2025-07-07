/*
Problem: Maximum Sum Combination
URL: https://www.geeksforgeeks.org/problems/maximum-sum-combination/1
Difficulty: Medium
Timestamp: 02:17 pm, 07 Jul 2025
*/

class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        int n = a.size();
        vector<int>ans;
        
        priority_queue<pair<int, pair<int,int>>>pq;
        set<pair<int,int>>vis;
        
        // sort(a.begin(),a.end(), greater<>);
        sort(a.rbegin(), a.rend());
        sort(b.rbegin(), b.rend());
        
        pq.push({a[0]+b[0], {0,0}});
        vis.insert({0,0});
        
        while(ans.size()<k){
            auto top = pq.top();
            pq.pop();
            
            int currSum = top.first;
            int i = top.second.first;
            int j = top.second.second;
            
            ans.push_back(currSum);
            
            if(i+1 < n && vis.find({i+1,j})==vis.end()){
                pq.push({a[i+1]+b[j], {i+1,j}});
                vis.insert({i+1,j});
            }
            if(j+1<n && vis.find({i, j+1})==vis.end()){
                pq.push({a[i]+b[j+1], {i,j+1}});
                vis.insert({i, j+1});
            }
        }
        return ans;
    }
};

/*
Notes:
- TC: O(n*logn) + O(k*logk) | SC: O(k)

// Good for revision of Set & Heap

- We sort both the arrays in decreasing order and then follow a Greedy approach of adding the pairs 
(i,j+1) and (i+1,j) into the heap.

- This would ensure that the maximum pair remains at the top of the heap and we push the value into our answer.

- We also maintain a set of pairs, to keep track of the visited pairs and so that we dont take the same pair again.

Using this approach, we brought down the O(n²) solution to O(k*logk), ie the pair formation. 
*/

