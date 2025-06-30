/*
Problem: Max min Height
URL: https://www.geeksforgeeks.org/problems/max-min-height--170647/1
Difficulty: Hard
Timestamp: 05:13 pm, 30 Jun 2025
*/

using ll = long long;

class Solution {
  public:
    bool count(vector<int>arr, int h, int w, int k){
        int n = arr.size();
        vector<int>water(n+1, 0);    // difference array
        int days = 0, currSum = 0;
        for(int i = 0; i<n; i++){
            currSum += water[i];
            int currHeight = arr[i] + currSum;
            if(currHeight<h){
                int req = h - currHeight;
                days += req;
                if(days>k)return 0;
                currSum += req;
                water[i] += req;
                if(i+w<=n)water[i+w] -= req;
            }
        }
        return 1;
    }
    
    int maxMinHeight(vector<int> &arr, int k, int w) {
        ll low = *min_element(arr.begin(),arr.end()),
            high = low + k;
            
        
        while(low<=high){
            ll mid = (low+high)/2;
            if(count(arr, mid, w, k))low = mid + 1;
            else high = mid - 1;
        }
        return int(high);
    }
};

/*
Notes:
Application of Difference Array while implementing the BS on Answer.
*/

