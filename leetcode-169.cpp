/*
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2
*/

/*Solution using Boyer Morre's Voting Problem*/

#include <bits/stdc++>

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority = nums[0];
        int count =1;
        for(size_t i=1,e=nums.size();i<e;i++){
            if(majority == nums[i]){
                ++count;
            }else{
                if(!--count){
                    majority = nums[i];
                    count =1;
                }
            }
        }
        
        return majority;
    }
};
