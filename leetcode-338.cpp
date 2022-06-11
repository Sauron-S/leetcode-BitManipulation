/*
338. Counting Bits

Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.

 

Example 1:

Input: n = 2
Output: [0,1,1]
Explanation:
0 --> 0
1 --> 1
2 --> 10
Example 2:

Input: n = 5
Output: [0,1,1,2,1,2]
Explanation:
0 --> 0
1 --> 1
2 --> 10
3 --> 11
4 --> 100
5 --> 101
*/

/*Solution : No. of bits in i 
i == 2^k then F(n) = 1
i !=2^k then F(n) = 1+ F(n-ref) where ref = last value <i which is complete power of 2  
*/

#include<bits/stdc++>
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1,0);
        int ref = 0;
        for(int i = 1;i<=n;i++){
            if((i & i-1) == 0){
                ref = i;
                ans[i] =1;
            }else{
                ans[i] = 1+ans[i-ref];
            }
        }
        
        return ans;
    }
};
