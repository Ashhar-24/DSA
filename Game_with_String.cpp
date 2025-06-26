/*
Problem: Game with String
URL: https://www.geeksforgeeks.org/problems/game-with-string4100/1
Difficulty: Medium
Timestamp: 12:19 am, 27 Jun 2025
*/

class Solution {
  public:
    int minValue(string &s, int k) {
        vector<int>freq(26,0);
        for(char c: s)freq[c-'a']++;
        
        priority_queue<int>pq;
        for(int x: freq){
            if(x!=0)pq.push(x);
        }
        
        while(k--){
            int top = pq.top();
            pq.pop();
            pq.push(top-1);
        }
        
        int sum = 0;
        while(!pq.empty()){
            sum += (pq.top()*pq.top());
            pq.pop();
        }

        return sum;
    }
};

/*
Notes:
TC: O(n+k) | SC: O(1)

- At every step we decrease that value which is the greatest as we need to take sum of the squares of each value. Hence greedily reducing the largest value till k>0. 
*/

