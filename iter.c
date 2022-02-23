#include <stdio.h>

void
printgrid(float * arr) {
    int row = 0; 
    int place = row * 4; 

    // iterate through each row
    for (int i = 0; i < 4; i++) {
        
        // print one row
        printf("%f, %f, %f, %f\n", 
                arr[place], arr[place + 1], arr[place + 2], arr[place + 3]); 
        
        //update place and row (ie index into the array)
        row++; 
        place = row * 4; 
    }
}

float * 
iter(float * arr, float delta, float gamma) {

    float left, right, up, down = 0;  

    /*
    Quick guide: 
        left  = i - 1
        right = i + 1
        up    = i - 4
        down  = i + 4
    */

    // iterate through the grid
    for (int i = 0; i < 16; i++) {

        // get row value (this is multiple of 4)
        int row = i - (i % 4);

        // if we aren't on the left edge of grid
        if (i - 1 >= row) {
            left = (gamma * arr[i - 1] - 1);
        }

        // if we're not on the right edge of the grid
        if (i + 1 <= row + 3) {
            right = (gamma * arr[i + 1] - 1);
        }

        // if we're not at the top of the grid
        if (i - 4 > -1) {
            up = (gamma * arr[i - 4] - 1);
        }

        // if we're not at the bottom of the grid
        if (i + 4 < 16) {
            down = (gamma * arr[i + 1] - 1);
        }

        arr[i] = 0.25 * (left + right + up + down); 

        // termnal states remain at 0
        if (i == 0 || i == 15) {
            arr[i] = 0.0f; 
        }
        
    }

    printgrid(arr); 

    return arr; 
}

int 
main () {

    /*     Set Up     */
    // create an array with 16 elements: 
    //   each group of four represents a row in the grid
    float grid[16] = {0.0f,0.0f,0.0f,0.0f, 0.0f,0.0f,0.0f,0.0f, 0.0f,0.0f,0.0f,0.0f, 0.0f,0.0f,0.0f,0.0f}; 
    float * gridptr = grid; 

    // create other useful variables: 
    float gamma = 1.0f; 
    float delta = 0.0f; 
    int iteration = 1; 

    /*      Run and Print     */
    // check if we can stop printing 
    //if (delta != gamma) {
    while (iteration < 5) {
        printf("Iterations %d:\n ", iteration); 
        // run iter on the current grid
        iter(gridptr, delta, gamma); 

        iteration++; 
        //delta += 0.25;
    }

    // finish
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