/*
Problem: K closest elements
URL: https://www.geeksforgeeks.org/problems/k-closest-elements3619/1
*/

class Solution {
  public:
    vector<int> printKClosest(vector<int> arr, int k, int x) {
        int n = arr.size();
        vector<pair<int,int>> diff;
        
        for(int val: arr){
            if(val == x) continue;
            int temp = abs(val-x);
            diff.push_back({temp, val});
        }
        
        sort(diff.begin(), diff.end(), [&](pair<int,int>a, pair<int,int>b){
            return a.first == b.first ? a.second > b.second : a.first < b.first;
        });
        
        vector<int>ans(k);
        for(int i=0; i<k; i++)ans[i] = diff[i].second;
        
        
        return ans;
    }
};      