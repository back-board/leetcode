# Problem 3211
## Summary
Typical DP problem
Need to define proper cache structure
Need to define good exit condition

### Approach
make a vector<string> cache with size of 18 x 2
2 is for the first character to start with.

current solution find two returns at the root level and than join to make final result.
maybe this part can be optimized... will think about it.

at each level, 
get the length and starting character as parameter.

if starting charcter is 1 then it combines all sublevel results, because it will valid all time, due to valid sublevel result.
if starting character is 0 then it combines only sublevel results staring with 1, because it becomes invalid if current charater is 0 and sublevel result start with 0.
