//  QUESTION :-
//  We have two special characters. The first character can be represented by one bit 0.
//  The second character can be represented by two bits (10 or 11).
//  Now given a string reppresented by several bits. Return whether the last character must be a one-bit character or not.
//  The given string will always end with a zero.

//  We get input as vector of integers and we are supposed to output a boolean.

//SOLUTION :-

//  STEP - 1 =>
//  Create a variable which will keep check of the parity of the numbers we encounter.

//  STEP - 2 =>
//  Start looping from the end - 1 position till the beginning :

//    STEP - 3 =>
//    If the current element is a '1' bit, we perform " parity ^= bits[i] "

//    STEP - 4 =>
//    If the current element is not a '1' bit, we do nothing.

//  STEP - 5 =>
//  Finally we return " parity == 0 "

#include <bits/stdc++.h>
using namespace std;

bool isOneBitCharacter(vector<int>& bits) {
  auto parity = 0;
  for(int i = static_cast<int>(bits.size()) - 2; i >=0 && bits[i]; --i) {
    parity ^= bits[i];
  }
  return parity == 0;
}
