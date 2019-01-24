#EE599
#problem2

X=input('Enter X: ')
Y=input('Enter Y: ')
sum=[0]*(Y)
j=1
i=1
leftX=X
while j<=Y:
  if(leftX<=(j+i-1)):
    sum[j-1]+=leftX
    break
    
  else:
    sum[j-1]+=j+i-1
  leftX=leftX-(j+i-1)
  
  if(j<Y):
    j+=1
  else:
    j=1
    i+=1
  
print sum
