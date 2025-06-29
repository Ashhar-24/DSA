/*
Problem: Counting elements in two arrays
URL: https://www.geeksforgeeks.org/problems/counting-elements-in-two-arrays/1
Difficulty: Easy
Timestamp: 11:55 am, 29 Jun 2025
*/

class Solution {
  public:
    vector<int> countLessEq(vector<int>& a, vector<int>& b) {
        sort(b.begin(), b.end());
        vector<int>ans;
        for(int& x: a){
            int i = upper_bound(b.begin(), b.end(), x) - b.begin();
            ans.push_back(i);
        }
        return ans;
    }
};

/*
Notes:
- TC: O(n*log(m)) | SC: O(1)

- Classical upper bound application to count the number of elements <= x, for every x in 1st array.
*/

