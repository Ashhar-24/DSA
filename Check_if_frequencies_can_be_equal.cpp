/*
Problem: Check if frequencies can be equal
URL: https://www.geeksforgeeks.org/problems/check-frequencies4211/1
Difficulty: Medium
Timestamp: 11:32 pm, 25 Jun 2025
*/

class Solution {
  public:
    bool sameFreq(string& s) {
        vector<int>freq(26,0);
        for(char c: s)freq[c-'a']++;
    
        unordered_map<int,int>mp;
        for(int x: freq){
            if(x>0)mp[x]++;
        }
        
        if(mp.size()==1)return 1;
        
        if(mp.size()==2){
            auto it = mp.begin();
            int freq1 = it->first, count1 = it->second;
            ++it;
            int freq2 = it->first, count2 = it->second;
 
            if ((freq1 == 1 && count1 == 1) || (freq2 == 1 && count2 == 1)) {
                return true;
            }

            if (abs(freq1 - freq2) == 1 &&
                ((count1 == 1 && freq1 > freq2) || 
                (count2 == 1 && freq2 > freq1))) {
                    
                return true;
            }
        }
        
        return 0;
    }
};

/*
Notes:
-Observation based hashing question.
*/

