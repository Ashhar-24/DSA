/*
Problem: 3085. Minimum Deletions to Make String K-Special
URL: https://leetcode.com/problems/minimum-deletions-to-make-string-k-special/
Difficulty: Medium
Timestamp: 10:55 pm, 21 Jun 2025
*/

class Solution {
public:
    int minimumDeletions(string word, int k) {
        int n = word.size();
        vector<int>freq(26,0);
        for(char& c: word)freq[c-'a']++;

        int ans = INT_MAX;
        sort(freq.begin(), freq.end());
        int l = 0;
        while(l<26 && freq[l]==0)l++;

        int pref = 0;
        for(int i=l; i<26; i++){
            int b = freq[i], cnt = 0;
            for(int j = 25; j>i; j--){
                if(freq[j] > (b+k))cnt += (freq[j] - (b+k));
            }
            cnt += pref;    // as we move ahead, we need to remove the smaller ones
            ans = min(ans, cnt);
            pref += freq[i];
        }

        // for(int i=0; i<26; i++){
        //     if(freq[i]!=0){
        //         int b = freq[i];
        //         int cnt = 0;
        //         for(int j=0; j<26; j++){
        //             if(i==j)continue;
        //             else if(freq[j]!=0){
        //                 if(freq[j] < b)cnt+= freq[j];
        //                 else if(freq[j] > (b+k)) 
        //                     cnt += max(0, freq[j]-  ( b+k));
        //             }
        //         }
        //         ans = min(ans, cnt);
        //     }
        // }

        return ans;
    }
};

/*
Notes:
TC: O(n) | SC: O(26)

For more detailed explanation, check:
https://shorturl.at/J7gWO
*/

