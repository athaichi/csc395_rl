#include <stdio.h>


int main () {

  float grid[4][4] = {0.0f};
  float prev_grid[4][4] = {0.0f}; 
  float gamma = 1.0f;
  float delta;
  int iteration = 0;
  float up, down, left, right = 0.0f; 

  while (iteration < 11) {
  // fill the array

    // printing
      printf("\nIteration %d:\n ", iteration);
      iteration++;
    
    // rows
  for (int i = 0; i < 4; i++) {

    printf("\n"); 

    // columns
    for (int j = 0; j < 4; j++) {

      // terminal cases?
      if ((i==0 && j==0) || (i==3 && j==3)){
        left = right = up = down = 0.0f;
      } else {

      // go left?
      if (j == 0) {
       left = 0.25 * (-1 + (gamma*prev_grid[i][j])); 
      } else {
        left = 0.25 * (-1 + (gamma*prev_grid[i][j-1])); 
      }

      // go right?
      if (j == 3) {
        right = 0.25 * (-1 + (gamma*prev_grid[i][j]));
      } else {
        right = 0.25 * (-1 + (gamma*prev_grid[i][j+1])); 
      }

      // go up?
      if (i == 0) {
        up = 0.25 * (-1 + (gamma*prev_grid[i][j]));
      } else {
        up = 0.25 * (-1 + (gamma*prev_grid[i-1][j])); 
      }

      // go down?
      if (i == 3) {
        down = 0.25 * (-1 + (gamma*prev_grid[i][j]));
      } else {
        down = 0.25 * (-1 + (gamma*prev_grid[i+1][j])); 
      }
      }

      grid[i][j] = left + right + up + down; 

      // print the array value
      printf("%f ", grid[i][j]);
      
    } // columns
  } // rows

  // move array values
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      prev_grid[i][j] = grid[i][j];
    }
  }


  } // while
  printf("\n"); 
  return 0; 
}
