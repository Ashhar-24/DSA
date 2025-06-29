/*
Problem: Split Array Largest Sum
URL: https://www.geeksforgeeks.org/problems/split-array-largest-sum--141634/1
Difficulty: Easy
Timestamp: 12:28 pm, 29 Jun 2025
*/

class Solution {
  public:
    int count(vector<int>arr, int maxSum){
        int n = arr.size();
        int cnt = 1, sum = 0;
        for(int i=0; i<n; i++){
            if(arr[i]+sum <= maxSum)sum += arr[i];
            else{
                sum = arr[i];
                cnt++;
            }
        }
        return cnt;
    }
    int splitArray(vector<int>& arr, int k) {
        // code here
        int low = *max_element(arr.begin(), arr.end()), 
            high = accumulate(arr.begin(), arr.end(),0);
        while(low<=high){
            int mid = (low+high)/2;
            if(count(arr,mid)>k)low = mid + 1;
            else high = mid - 1;
        }
        return low;
    }
};

/*
Notes:
- TC: O(n*logn) | SC: O(1)

- Similar to classical Book Allocation Problem.
*/

