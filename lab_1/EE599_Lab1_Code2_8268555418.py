# EE599
# Author: Yang Zhang
# Lab1 - Code2
# Description:
#Generate specific number of random integers 
#between(and including)two limits.



infile=open("input_code2.txt","r")
outfile=open("output_code2.txt","w")
all_para=infile.readlines()
seed=int(all_para[0])
count=int(all_para[1])
low_limit=int(all_para[2])
up_limit=int(all_para[3])
m=[]
import random
random.seed(seed)
for i in range(count):
  m.append(random.randint(low_limit,up_limit))
m=list(set(m))
m.sort()
i=0
Num=5
outfile.write('counter integers\n')
while i<len(m):
  k=0
  outfile.write('%i: '%(i+1))
  if i+Num<len(m):
    n=list(m[i:i+Num])
  else:
    n=list(m[i:])
  for j in n:
    outfile.write('%i' %(j))
    k=k+1
    i=i+1
    if (k%Num==0) | (i==len(m)):
      outfile.write('\n')
    else:
      outfile.write(',')
infile.close()
outfile.close()
