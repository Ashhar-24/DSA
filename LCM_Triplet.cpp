/*
Problem: LCM Triplet
URL: https://www.geeksforgeeks.org/problems/lcm-triplet1501/1
Difficulty: Medium
Timestamp: 07:34 pm, 19 Jul 2025
*/

class Solution {
  public:
    int lcmTriplets(int n) {
        if(n<3) return n;
        
        if(n%2==1) return n*(n-1)*(n-2);
        
        if(__gcd(n, n-3)==1) return n*(n-1)*(n-3);
        
        return (n-1)*(n-2)*(n-3);
    }
};

/*
Notes:
- TC: O(log(n)) | SC: O(1)

- We need to maximize the LCM, ie
LCM * gcd = a * b,
if gcd == 1, then we get the max LCM, ie we get max LCM, if the two numbers are co-prime.

- So with observation, if `n` is odd, then simply n*n-1*n-2, will give the answer, as two consecutive odd numbers (n, n-2) are always co-prime.

- Else, when n is even, then this will not give the max LCM, as n and n-2 will have 2 as common factor and will reduce the LCM. 

- Hence, we check whether n and (n-3) are co-prime or not (as n and n-2 are not co-prime). If they are co-prime, we 
return n*n-1*n-3 as the answer.

- Else, we simply return n-1*n-2*n-3, as now n-1 and n-3 will be consecutive odds and hence co-prime.
*/

