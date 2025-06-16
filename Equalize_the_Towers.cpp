/*
Problem: Equalize the Towers
URL: https://www.geeksforgeeks.org/problems/equalize-the-towers2804/1
*/

class Solution {
  public:
    int cal(vector<int>& height, vector<int>&cost, int h){
        int cnt = 0;
        for(int i = 0; i<height.size(); i++){
            cnt += abs(height[i]-h)*cost[i];
        }
        return cnt;
    }
    int minCost(vector<int>& heights, vector<int>& cost) {
        int low = *min_element(heights.begin(), heights.end()),
            high = *max_element(heights.begin(), heights.end());
            
        while(low<=high){
            int mid = (low+high)/2;
            int a = cal(heights, cost, mid-1);
            int b = cal(heights, cost, mid);
            int c = cal(heights, cost, mid+1);
            
            if(b<=a && b <= c) return b;
            if(a>=b && b>=c) low = mid + 1;
            else if(b>=a && c>=b) high = mid - 1;
        }
        return -1;
    }
};
