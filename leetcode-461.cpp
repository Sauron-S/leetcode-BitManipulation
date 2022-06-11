/*
461. Hamming Distance

The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Given two integers x and y, return the Hamming distance between them.

Example 1:

Input: x = 1, y = 4
Output: 2
Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
       ↑   ↑
The above arrows point to positions where the corresponding bits are different.
Example 2:

Input: x = 3, y = 1
Output: 1
*/

#include<bits/stdc++>

class Solution {
public:
    int hammingDistance(int x, int y) {
        int k = x^y;
        int count = 0;
        while(k){
            k = k &(k-1);
            ++count;
        }
        
        return count;
    }
};
