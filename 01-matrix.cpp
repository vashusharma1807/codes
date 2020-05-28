//  QUESTION :-
//  Given a matrix of only 0 and 1, find the distance of nearest 0 for each cell.
//  The distance between two adjacent cells is 1.
//  (We receive input as vector of vectors and return the output as vector of vectors)

//  SOLUTION :-

//  STEP - 1 =>
//  We first create a queue of a pair of integers.

//  STEP - 2 =>
//  We iterate through all the elements of the matrix(vector of vectors) :

//    STEP - 3 =>
//    If our element is 0, we add the index of it into the queue

//    STEP - 4 =>
//    If our element is 1, we change the value of the matrix for the element to numeric_limits<int>::max()

//    (After these 4 steps, we have our matrix as a matrix of 0s and infinities)

//  STEP - 5 =>
//  We now create an auxilliary vector of pairs of integers ( vector<pair<int, int>> ) which contains elements that help us to move through the matrix.
//  ( Example: dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}} )
//  ( The first element allows us to go one row back, the second allows to go one row ahead, the third allows to go one column behind and the fourth allows to go one column ahead.)


//  STEP - 6 =>
//  While queue has any element in it, we perform the following :-
//  (Remember, that our queue contains the index of the 0 elements)

//    STEP - 7 =>
//    We extract the front element from the queue and pop it from the queue.

//    STEP - 8 =>
//    We run another loop through our auxilliary vector, and :-

//        STEP - 9 =>
//        (Keep in mind that our auxilliary vector's element is of the form (row, column))
//        (Also, our extracted element is of the form (row, column))
//        We take the first part from the auxilliary element and the extracted queue element, this is our row index which we have to examine.
//        We take the second part from the auxilliary element and the extracted queue element, this is our column index which we have to examine.

//        STEP - 10 =>
//        If the row index is less than 0 or it is greater than the matrix size OR
//        if the column index is less than 0 or greather than the matrix size OR
//        if the value of element at this row and column index is less than or equal to the value of the element at the extracted queue element + 1,
//        WE CONTINUE AND DO NOTHING

//        STEP - 10 =>
//        Otherwise, we add the analysed row index and column index in the queue AND
//        Change the value of the element at the analysed row index and column index to value at extracted row and column index + 1

//  STEP - 11 =>
//  Return the matrix

#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
  queue<pair<int, int>> queue;
  for(int i = 0; i < matrix.size(); ++i) {
    for(int j = 0; j < matrix[i].size(); ++j) {
      if(matrix[i][j] == 0) {
        queue.emplace(i, j);
      } else {
        matrix[i][j] = numeric_limits<int>::max();
      }
    }
  }

  const vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  while(!queue.empty()) {
    auto cell = queue.front();
    for(const auto& dir : dirs) {
      auto i = cell.first + dir.first;
      auto j = cell.second + dir.second;
      if(i < 0 || i >= matrix.size() || j < 0 || j >= matrix.size() || matrix[i][j] <= matrix[cell.first][cell.second] + 1) {
        continue;
      }
      queue.emplace(i, j);
      matrix[i][j] = matrix[cell.first][cell.second] + 1;
    }
  }

  return matrix;
}


//  ANOTHER DP SOLUTION AVAILABLE
