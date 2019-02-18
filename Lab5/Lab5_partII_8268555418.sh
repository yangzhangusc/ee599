#EE599
#Lab5_partII_regx
#Yang Zhang zhan256@usc.edu

#Q1 reference https://www.jianshu.com/p/47d7db7958dc
grep -E "^(0+|0*1((10*1)|(01*0))*10*)$" Lab5_partII_Q1_input.txt >output1.txt

#Q2
grep -E '(((\bred\b)((.*\b)|(.*\b.*\b)|())[pick up,pickup,pick-up](\btruck\b))|([pick up,pickup,pick-up](\btruck\b)((.*\b)|(.*\b.*\b)|())(\bred\b)))(.*([$][0-9]*))' Lab5_partII_Q2_input.txt>output2.txt

#Q3
grep -E '^((((0[1-9])|(1[0-9])|(2[0-9])|(3[0-1]))[-]([A-Z][a-z][a-z])[-][0-9][0-9][0-9][0-9])|(((0[1-9])|(1[0-9])|(2[0-9])|(3[0-1]))[.]([A-Z][a-z][a-z])[.][0-9][0-9][0-9][0-9])|(((0[1-9])|(1[0-9])|(2[0-9])|(3[0-1]))[/]([A-Z][a-z][a-z])[/][0-9][0-9][0-9][0-9]))$'  Lab5_partII_Q3_input.txt > output3.txt

#Q4



