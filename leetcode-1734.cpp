/*
1734. Decode XORed Permutation

There is an integer array perm that is a permutation of the first n positive integers, where n is always odd.

It was encoded into another integer array encoded of length n - 1, such that encoded[i] = perm[i] XOR perm[i + 1]. For example, if perm = [1,3,2], then encoded = [2,1].

Given the encoded array, return the original array perm. It is guaranteed that the answer exists and is unique.

Example 1:

Input: encoded = [3,1]
Output: [1,2,3]
Explanation: If perm = [1,2,3], then encoded = [1 XOR 2,2 XOR 3] = [3,1]
Example 2:

Input: encoded = [6,5,4,6]
Output: [2,4,1,5,3] 
*/

/*
Find Xor of 1 to N
---------------------------------------------------------------------
First try to find last number
modify encoded to such that
encoded[i] = encode[i] ^ encode[i+1]^..encoded[last]
then find xor of encoded
last_element = xor(1..n) ^ xor(encoded)
---------------------------------------------------------------------
for rest of the elements
a[i] = encoded[i] ^ last_element
*/

class Solution {
public:
    int FindXor(int n){
        int res = n%4;
        if(res == 0){
           return n; 
        }else if(res == 2){
            return n+1;
        }else if(res == 1){
            return 1;
        }
        
        return 0;
    }
    
    vector<int> decode(vector<int>& encoded) {
        size_t ar = encoded.size();
        int val = FindXor(ar+1);
        std::vector<int> ans(ar+1,0);
        std::vector<int> temp_st(ar,0);
        
        int xor_enc = 0;
        for(size_t i=0;i<ar;i++){
            xor_enc = xor_enc ^ encoded[i];
            temp_st[i] = xor_enc;
        }
        
        for(size_t i=ar-1;i>0;i--){
            temp_st[i] = xor_enc ^temp_st[i-1];
        }
        
        temp_st[0] = xor_enc;
        xor_enc = 0;
        for(size_t i=0;i<ar;i++){
            xor_enc = xor_enc ^ temp_st[i];
        }
        
        ans[ar] = xor_enc^val;
        for(size_t i=0;i<ar;i++){
            ans[i] = temp_st[i]^ ans[ar];
        }
        
        return ans;
        
    }
};
