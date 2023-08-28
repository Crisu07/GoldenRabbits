# GoldenRabbits
GoldenRabbits calculator to estimate how much rabbits there are after 10 years, coded in C++

## Rabbit Rules
- New-born rabbits take one month to mature
- One pair of mature rabbits will have a pair of baby rabbits after one month
- Mature rabbits will continue to producec a new pair of baby rabbits every month
- Rabbits will never die

Figure out how many rabbits there will be by the end of 10 years.

- At start of month 0, receive the baby rabbits so 1 pair of rabbits
- At the start of month 1, the baby rabbits are grown and the female becomes pregnant. But still have only 1 pair of rabbits.
- At the start of month 2, the first pair give birth to 1 pair of rabbits, so now have 2 pairs of rabbits. The first pair (the adults) immediately become pregnant again.
- At the start of month 3, the second pair is now mature and the first pair give birth again to 1 pair of rabbits. This gives 3 pairs of rabbits.
- At the start of month 4, the first pair gives birth to a new pair, the second pair gives birth to a new pair, and the third pair are all grown up and ready to start family life. So now have 5 pairs of rabbits.

## 3 Problems to Solve (shortened from assignment)
- Write the goldRabbits(int n) function that throws an exception if interget overflows. Exception will throw a string that indicates the input number (n) which cause the overflow.
- Need to create a new Class called BigInt that will allow calculating goldRabbits(120), or even goldRabbits(2000)
- Modify the function goldRabbits so that it can also calculate goldRabbits(2000) before we all die.