/*
Problem: Police and Thieves
URL: https://www.geeksforgeeks.org/problems/police-and-thieves--141631/1
Difficulty: Medium
Timestamp: 03:34 pm, 22 Jun 2025
*/

class Solution {
  public:
    int catchThieves(vector<char> &arr, int k) {
        int n = arr.size();
        int cnt = 0;
        
        // TC: O(n) | SC: O(1)
        int i = 0, j = 0;
        while(i<n && j<n){
            while(arr[i]!='P' && i<n)i++;
            while(arr[j]!='T' && j<n)j++;
            
            if(i<n && j<n && abs(i-j)<=k){
                cnt++;
                i++;j++;
            }
            else if(j<n && j<i)j++;
            else if(i<n && i<j)i++;
        }
        
        // TC: O(n*k) | SC: O(n)
        // vector<int>vis(n,0);
        // for(int i = 0; i<n; i++){
        //     if(arr[i]=='P'){
        //         int mini = max(0, i-k);
        //         int maxi = min(n-1, i+k);
        //         for(int j=mini; j<=maxi; j++){
        //             if(arr[j] == 'T' && !vis[j]){
        //                 vis[j] = 1;
        //                 cnt++;
        //                 break;
        //             }
        //         }
        //     }
            
        // }
        
        return cnt;
    }
};

/*
Notes:
- We use the greedy approach, ie, for a policemen, we find the first thief that lies in it's range and increase our count.

- Local Best = Global Best:
	If we try to pair a policeman with the nearest thief (within range), that’s the most efficient use 	of that policeman. Waiting or skipping that thief might mean no one catches them later, wasting a 	chance.

- Avoiding Conflicts Early:
	If you try to look ahead or match far-off thieves, we might end up “stealing” a thief that another 	closer policeman could have caught — leading to fewer total catches overall.

That’s greedy: always making the locally optimal decision (catch the nearest available thief) in hopes of getting the global optimum (max number of catches).

- To implement this, we use Two-pointer, where `i` represent the `Police` and `j` thief.
We increase them until both do not point to their representatives.
Then if they lie in the range, we increment both.
Otherwise depending upon their position, we try to bring them into the range.
*/

