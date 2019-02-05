#EE599
#Lab 4
#Author: Yang Zhang emali:zhan256@usc.edu

#Lab4Part2
#Debugging process:
I read "[32, 56) 'arr' <== Memory access at offset 56 overflows this variable" and discover that the code try to access the illegal location of memory. So I reviewed the code about "arr[]".Finally I found that the print function and quick sort function wrongly try to access arr[n], which is not claimed. The last value of arr[] is supposed to be arr[n-1], not arr[n].

#Lab4Part4
#Description:
To sort Fib pancake, Fistly I find Fib pancake from the top, every time I find one, I flip the pancakes above the Fib pancake, and then Fib the pancakes including the Fib pancake. By this way, I could assure the non-Fib pancakes remain their original order.

Secondly, for the top Fib pancakes, I do the sorting as what I do in lab3.
Finally, to decode,traversing each specific pancake pile, I check the first pancake to figure out whether this pile contains Fib or not. If it does, I add up to the odd-Fib pancakes.Then I do the mod operation in the main().

#Citations:
To write my code line 6 to line 28, I used the algorithms of checking perfect square number in the website :https://blog.csdn.net/puqutogether/article/details/42098609

