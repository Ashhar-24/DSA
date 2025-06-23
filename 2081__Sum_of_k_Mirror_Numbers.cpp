/*
Problem: 2081. Sum of k-Mirror Numbers
URL: https://leetcode.com/problems/sum-of-k-mirror-numbers/?envType=daily-question&envId=2025-06-23
Difficulty: Hard
Timestamp: 05:12 pm, 23 Jun 2025
*/

using ll = long long;
class Solution {
public:
    bool isPalik(ll num, int k){
        string s = "";
        while(num){
            s.push_back(char(num%k + '0'));
            num/=k;
        }
        int l = 0, r = s.size()-1;
        while(l<=r){
            if(s[l++]!=s[r--])return 0;
        }
        return 1;
    }

    long long kMirror(int k, int n) {
        ll sum = 0;
        int cnt = 0;

        int L = 1;  // length of the palindromic number
        while(cnt<n){
            int halfL = (L+1)/2;
            ll min_no = pow(10,halfL-1), max_no = pow(10, halfL)-1;
            
            for(int i = min_no; i<=max_no && cnt<n; i++){
                string a = to_string(i);
                string b = a;
                reverse(b.begin(), b.end());
                if(L&1){
                    a += b.substr(1);
                }
                else{
                    a += b;
                }
                if(isPalik(stoll(a),k)){
                    cout<<a<<" ";
                    sum += stoll(a);
                    cnt++;
                }
            }
            L++;
        }
        return sum;
    }
};

/*
Notes:
TC: O(n*L) | SC: O(L) (n: no of palidromes generated, L: length of palindrome)

- As we are required to find the numbers that are both palindrome in base-10 and in base-k, to simplify the approach (as brute force will TLE),
we first generate (enumerate) the base-10 palindromes and then check whether it is a base-k palindrome, if yes, we add it to our `sum` variable.

- In order to generate base-10 palindromes, we define the length of the palindrome first, and then generate
them starting with `length 1` palindrome.

- If the length is odd, say 5, then the 1st-three numbers are unique, and the last digits are equal to 1st two digits in reverse manner.
So, in order to generate all length 5 palindromes, we use all the 3 digits numbers, and then form them and check,
if any one of them is a base-k palindrome or not.

*/

