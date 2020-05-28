//  Given an array of integers, find two numbers such that they add up to a specific number.
//  The function should return indices of two numbs index1 and index2, where index1 should be lesser than index2.


//  For problems like this, we are going to undergo the following problem:
//  STEP - 1 =>
//  Create an empty unordered_map
//  STEP - 2 =>
//  Iterate through each element of the vector and :-
//    STEP - 3 => if (target - the current element) exists in the hasmap,
//                then return the current index along with the index of the value (target - current element)
//                We are using hashmap as hash[element_value] = index
//    STEP - 4 => if (target - the current element) does not exist in the hashamp,
//                we add the element in the hashmap.

#include <bits/stdc++.h>

using namespace std;

vector<int> twoSum(vector<int> &nums, int target) {
  unordered_map<int, int> hash;
  for(int i = 0; i < nums.size(); ++i) {
    if(hash[target - nums[i]] != has.end()) {
      return {hash[target - nums[i]] + 1, i + 1};
    } else {
      hash[nums[i]] = i;
    }
  }
  return {};
}
