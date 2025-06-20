/*
Problem: Group Balls by Sequence
URL: https://www.geeksforgeeks.org/problems/group-balls-by-sequence/1
Difficulty: Easy
Timestamp: 08:16 am, 20 Jun 2025
*/

class Solution {
  public:
    bool validgroup(vector<int> &arr, int k) {
        int n = arr.size();
        if(n%k!=0) return 0;
        
        // TC: O(maxVal*k) | SC: O(maxVal+k)
        int N = 1e5+k+1;
        vector<int>freq(N,0);
        for(int& x: arr)freq[x]++;
        
        for(int val = 0; val<N; val++){
            int cnt = freq[val];
            if(cnt>0){
                for(int i=1; i<k; i++){
                    if(freq[val+i]<cnt) return 0;
                    freq[val+i] -= cnt;
                }
                freq[val] = 0;
            }
        }
        
        // TC: O(n*k*logn) | SC: O(n)
        // map<int,int>mp;
        // for(int& x: arr)mp[x]++;
        
        // for(auto& x : mp){
        //     int val = x.first, cnt = x.second;
        //     if(cnt>0){
        //         for(int i=1; i<k; i++){
        //             if(mp[val+i]<cnt) return 0;
        //             mp[val+i] -= cnt;
        //         }
        //         mp[val] = 0;
        //     }
        // }
        
        return 1;
    }
};

/*
Notes:
- Given the max range of arr[i], we declare the frequency array for more
faster lookup, as compared to ordered_map (uses red black tree and lookup time is O(logn)).

- Earlier logic of sorting and then forming k-groups didn't work, as this approach didn't take into account of the
presence of duplicate elements.

- Current approach makes groups greedily and updates the frequency after forming the group.
*/

