import numpy as np

def iterative_policy(): 

    print("this works")

    # create a 2D array for the state grid [rows][columns]
    stategrid = np.zeros((4,4))

    for iter in range(0, 10): 
        for state in stategrid: 
            # check going right
            print (state, "right")

            # check going left
            print (" \tleft")

            # check going up 
            print ("\t up")
            
            # check going down 
            print("\t down\n")


    print(stategrid)



# RUNNING
# to run:
# 1. check to see if python3 is installed with 
#      python3 --version
# 2. run command `python3 iterative_policy.py` 
iterative_policy()