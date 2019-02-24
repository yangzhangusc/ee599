
# EE599-Lab6
# DO NOT CHANGE THE FIRST 10 LINES
# DO NOT INCLUDE ANY OTHER PACKAGE
import random
import os
import time
PARAM = {"seed":26, "size":30, \
        "unsortedFile":"input.txt", "sortedFile":"output.txt", \
        "range": [0, 100], "alg":"bubbleSort"}

# TASKS: 
# Seed your random generator with PARAM["seed"]
# Generate PARAM["size"] integers in range PARAM["range"]
# Write the random integers in PARAM["unsortedFile"]
# Don't forget to close the file (potential bug here!)
# Each integer should be in a separate line
# Compile your C++ code (use "os" package)
# Start a timer
# Run your C++ code with the correct arguments
# Print your timer (in sec) in a single line, that's the only thing you should print
# Write you code below: 
seed=PARAM["seed"]
size=PARAM["size"]
low_limit=PARAM["range"][0]
high_limit=PARAM["range"][1]
infile=open(PARAM["unsortedFile"],"w+")
number=[]
for i in range(size):
  number.append(random.randint(low_limit,high_limit))
  infile.write('%i\n'%number[i])
infile.close()
#print ('./test PARAM["unsortedFile"] PARAM["sortedFile"] 30 PARAM["alg"]')
os.system('g++ -std=c++17 main.cpp sort.cpp -o test')
start=time.time()
os.system('./test '+PARAM["unsortedFile"]+" "+PARAM["sortedFile"]+" "+str(PARAM["size"])+" "+PARAM["alg"])
end=time.time()
print (end-start)




