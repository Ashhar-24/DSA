/*
Problem: 3443. Maximum Manhattan Distance After K Changes
URL: https://leetcode.com/problems/maximum-manhattan-distance-after-k-changes/solutions/6362270/exploring-all-possible-directions-greedy/?envType=daily-question&envId=2025-06-20
Difficulty: Medium
Timestamp: 08:31 am, 20 Jun 2025
*/

class Solution {
public:

    int dist(string& s){
        int x = 0, y = 0;
        int ans = 0;
        for(char c: s){
            if(c=='E')x++;
            if(c=='W')x--;
            if(c=='N')y++;
            if(c=='S') y--;
            ans = max(ans, abs(x)+abs(y));
        }
        return ans;
    }

    int maxDistance(string s, int k) {
        string temp = s;
        int x = k, ans=0;

        // EN
        for(char &c: temp){     // using '&c' as the 'for-each' loop creates a copy and won't change the char when required.
            if(x>0 && c=='W') c='E',x--;
            if(x>0 && c=='S') c= 'N',x--;
        }
        ans= max(ans, dist(temp));

        // NW
        temp=s; x=k;
        for(char &c: temp){
            if(x>0 && c=='S') c='N',x--;
            if(x>0 && c=='E') c='W',x--;
        }
        ans= max(ans, dist(temp));

        // WS
        temp=s; x=k;
        for(char &c: temp){
            if(x>0 && c=='E') c='W',x--;
            if(x>0 && c=='N') c='S',x--;
        }
        ans= max(ans, dist(temp));

        // SE
        temp=s; x=k;
        for(char &c: temp){
            if(x>0 && c=='N') c='S',x--;
            if(x>0 && c=='W') c= 'E',x--;
        }
        ans= max(ans, dist(temp));

        return ans;
    }
};

/*
Notes:
Detailed explanation:
https://leetcode.com/problems/maximum-manhattan-distance-after-k-changes/solutions/6362270/exploring-all-possible-directions-greedy/?envType=daily-question&envId=2025-06-20
*/

