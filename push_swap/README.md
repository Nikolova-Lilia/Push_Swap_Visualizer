Project - Push_swap

Rules:

• You have 2 stacks named a and b.

• At the beginning:

◦ The stack a contains a random amount of negative and/or positive numbers

which cannot be duplicated.

◦ The stack b is empty.

• The goal is to sort in ascending order numbers into stack a. To do so you have the

following operations at your disposal:

sa (swap a): Swap the first 2 elements at the top of stack a.

Do nothing if there is only one or no elements.

sb (swap b): Swap the first 2 elements at the top of stack b.

Do nothing if there is only one or no elements.

ss : sa and sb at the same time.

pa (push a): Take the first element at the top of b and put it at the top of a.

Do nothing if b is empty.

pb (push b): Take the first element at the top of a and put it at the top of b.

Do nothing if a is empty.

ra (rotate a): Shift up all elements of stack a by 1.

The first element becomes the last one.

rb (rotate b): Shift up all elements of stack b by 1.

The first element becomes the last one.

rr : ra and rb at the same time.

rra (reverse rotate a): Shift down all elements of stack a by 1.

The last element becomes the first one.

rrb (reverse rotate b): Shift down all elements of stack b by 1.

The last element becomes the first one.

rrr : rra and rrb at the same time.


Solution:

The program works as it will push all numbers from stack a, to stack b until only 3 numbers left. 

While pushing it will check every posible combination to find the one with least moves needed 

and will push that one first. All numbers in stack b, will be arranged in descending order.

For the 3 numbers left in stack a, it will check if they are in any way in descending order,

if so it will swap the numbers. Then will start pushing back the numbers from stack b (at this point

they are now all sorted in stack b in descending order) to stack a. finally it will check if the order

in stack a is correct and the minimum number is on top, if no will rotate to get it on top.





![image](https://github.com/Nikolova-Lilia/Push_Swap/assets/147531481/60d9ad1d-0a2d-41e3-b110-9dbe052640fb)





