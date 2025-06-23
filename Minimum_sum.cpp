/*
Problem: Minimum sum
URL: https://www.geeksforgeeks.org/problems/minimum-sum4058/1
Difficulty: Medium
Timestamp: 12:27 pm, 23 Jun 2025
*/

class Solution {
  public:
    string add(string&a, string&b){
        int i = a.size()-1, j = b.size()-1, carry = 0;
        string ans ="";
        while(i>=0 && j>=0){
            int sum = carry + (a[i]-'0') + (b[j] - '0');
            ans+=to_string(sum%10);
            carry = sum/10;
            i--, j--;
        }
        while(i>=0){
            int sum = carry + (a[i]-'0');
            ans+=to_string(sum%10);
            carry = sum/10;
            i--;
        }
        while(j>=0){
            int sum = carry + (b[j] - '0');
            ans+=to_string(sum%10);
            carry = sum/10;
            j--;
        }
        ans+=to_string(carry);
        
        while(!ans.empty() && ans.back()=='0'){
            ans.pop_back(); i--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    string minSum(vector<int> &arr) {
        // code here
        int n = arr.size();
        string a="",b="";
        
        // TC: O(n) | SC: O(n)
        vector<int>freq(10,0);
        for(int&x : arr)freq[x]++;
        
        bool first=1; // to alternate numbers while assigning
        for(int i=0; i<10; i++){
            if(freq[i]==0)continue;
            while(freq[i]--){
                if(first){
                    a.push_back(char(i+'0'));
                    first=0;
                }
                else{
                    b.push_back(char(i+'0'));
                    first=1;
                }
            }
        }
        
        // // Forming the nos using sorting 
        // TC: O(nlogn) | SC: O(n)
        // sort(arr.begin(), arr.end());
        // int i = 0;
        // while(i<n){
        //     a += to_string(arr[i]);
        //     i+=2;
        // }
        // i = 1;
        // while(i<n){
        //     b += to_string(arr[i]);
        //     i+=2;
        // }
        
        return add(a,b);
    }
};

/*
Notes:
- Forming nos using Greedy approach, ie, smallest no occupies the MSB (leftmost digit) (or) the first digit, and
alternate the digits while forming the nos.

- Then as the numbers formed can overflow while adding, so added the nos in their string representation itself.
*/

