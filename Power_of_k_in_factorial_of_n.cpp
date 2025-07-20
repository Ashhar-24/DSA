/*
Problem: Power of k in factorial of n
URL: https://www.geeksforgeeks.org/problems/power-of-k-in-n-where-k-may-be-non-prime4206/1
Difficulty: Medium
Timestamp: 12:15 am, 21 Jul 2025
*/

class Solution {
  public:
    unordered_map<int,int> splitKInPrimeFactors(int k){
        unordered_map<int,int>mp;           // storing primes and their power-count
        
        for(int i = 2 ; i*i<=k; i++){
            while(k%i==0){
                mp[i]++;
                k /= i;
            }
        }
        if(k>1)mp[k]++;     // k itself is a prime
        return mp;
    }
    
    int legendre(int n, int p){     // counts the power of prime p in n!
                                    // cnt = floor(n/p) + floor(n/p^2) + floor(n/p^3) +...
        int cnt = 0;
        
        for(long long i = p; i<=n; i*=p){
            cnt += n/i;
        }
        return cnt;
    }
    
    int maxKPower(int n, int k) {
        auto primeAndCnt = splitKInPrimeFactors(k);
        
        int ans = INT_MAX;
        
        for(auto x: primeAndCnt){
            int p = x.first, cnt = x.second;
            ans = min(ans, legendre(n,p)/cnt);      // dividing by cnt as k is expressed in terms of primes
        }
        
        return ans;
    }
};

/*
Notes:
- TC: O(k + m*log(n)) | SC: O(m)
m : distinct prime factors

- If we were just given to find the max power of prime k in n!, we would have used the Legendre's Theorem, which is as follows:
Given a n, we need to find the count of powers of prime p in n!, and it is given by:
cnt = floor(n/p) + floor(n/p^2) + floor(n/p^3) + ....

- Here the change is that instead of prime p, we are given a random number k, but in order to solve this, we make use of the Legendre's Algo.

- We first break `k` into into powers of it's prime and map the prime no with it's power. We do this because we have to use legendre's algorithm.

- Then for each prime factor of k, we count power of it in n! and then divide by it's count in k, ie if the prime p has
power 'e' in k, then the count returned
by legendre's algo must be divided by `e` as, we would need `e` p's to make one k.

- In order to get the maximum power of k, we take the min from all the above step....as this would ensure that we are taking `k`.
*/

