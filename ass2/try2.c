/*
 * This code details a program that solves a simple gridworld problem. 
 *    There is a 4x4 gric with overlapping terminal states in the top left and 
 *    bottom right corner. The goal of the program is to find the optimal policy 
 *    to reach the terminal state using the Bellman Equation. 
 * 
 *    This program is in response to Professor Fernanda Eliott's CSC395: RL and MAS 
 *    class. You can find out more about the assignment and the class by visiting our 
 *    class website here: https://eliott-fernanda.cs.grinnell.edu/home/395_rlandmas/ 
 * 
 * Authors: Lanea Rohan and Arsema Berhane
 * Date: Feb 24, 2022
*/

#include <stdio.h>

int main () {

  // create the grids to use for the Bellman Equation
  float grid[4][4] = {0.0f};
  float prev_grid[4][4] = {0.0f}; 

  // set up other helpful variables
  float gamma = 1.0f;  // discount value
  float delta = 10.0f;
  float sumdelta = 0; 
  float theta = 0.001f; 
  int iteration = 0;

  // separate the Bellman equation into smaller chunks
  float up, down, left, right = 0.0f; 

  // print the first iteration (empty grid)
  printf("\nIteration %d:\n", iteration); 
  iteration++; 

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      printf("%f ", grid[i][j]); 
    }
    printf("\n"); 
  }

  // keep going until we reach the optimum policy
  while (delta >= theta) {
  //while (iteration < ) {

    // printing
      printf("\nIteration %d:\n ", iteration);
      iteration++;

    // reset delta and sumdelta to be 0
    delta = 0.0f; 
    sumdelta = 0.0f; 
    
    // rows
    for (int i = 0; i < 4; i++) {

      // make the output pretty
      printf("\n"); 

      // columns
      for (int j = 0; j < 4; j++) {

        // are we in the terminal state?
        if ((i==0 && j==0) || (i==3 && j==3)){ // if yes, leave as 0
          left = right = up = down = 0.0f;
        } else {  // if no, then calculate the state value

          // can we go left?
          if (j == 0) { // no, use our current state
            left = 0.25 * (-1 + (gamma*prev_grid[i][j])); 
          } else { // yes, use the state one state to the left
            left = 0.25 * (-1 + (gamma*prev_grid[i][j-1])); 
          }

          // can we go right?
          if (j == 3) { // no, use our current state
            right = 0.25 * (-1 + (gamma*prev_grid[i][j]));
          } else { // yes, use the state one to the right
            right = 0.25 * (-1 + (gamma*prev_grid[i][j+1])); 
          }

          // can we go up?
          if (i == 0) { // no, use our current state
            up = 0.25 * (-1 + (gamma*prev_grid[i][j]));
          } else { // yes, use the state above us
            up = 0.25 * (-1 + (gamma*prev_grid[i-1][j])); 
          }

          // can we go down?
          if (i == 3) { // no, use our current state
            down = 0.25 * (-1 + (gamma*prev_grid[i][j]));
          } else { // yes, use the state below us
            down = 0.25 * (-1 + (gamma*prev_grid[i+1][j])); 
          }
          
        } // end else 

        // calculate the state value
        grid[i][j] = left + right + up + down; 

        // find delta of this particular state and add it to our sum
        // is the difference in calculated state smaller than delta (0)?
        if (delta >= (prev_grid[i][j] - grid[i][j])) { // if yes, add 0 to sumdelta
          sumdelta += delta; 
        } else { // if no, the difference to sumdelta
          sumdelta += (prev_grid[i][j] - grid[i][j]);  
        }
        
        // print the state value
        printf("%f ", grid[i][j]);

        if (iteration >= 120) {
          printf("left is: %f |", left); 
          printf("right is: %f |", right);
          printf("up is: %f |", up);
          printf("down is: %f \n", down);
        }
        
      } // columns
    } // rows

    // finished with one full iteration: 
    //   now we move state values into prev_array to use next iteration
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        prev_grid[i][j] = grid[i][j];
      }
    }

    // sum all delta values and divide by number of states evaluated, 
    //   this is our true delta
    delta = sumdelta / 16;

    //keep a clean terminal window
    printf("\n");

  } // while
  
  // keep a clean terminal window
  printf("\n"); 
  
  return 0; 
}

// Instructions to run: 
/*

1. Make sure you have clang installed: 
    clang -v
   If nothing appears/a message saying command unrecognized, you will need to 
       install clang

2. If you have clang installed, then run the following to compile this code:
   clang -o iter iter.c

3. Finally, to run, write:
    ./iter

*/