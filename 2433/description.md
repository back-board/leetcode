# Problem 2433
## Summary
Find original array to make the given xor result array

## Approach
for a ^ b = c
a ^ c = b is true.

just need to xor reversely.

because this problem is quite easy and there is no big calculation, runtime measurement of leetcode is not precise. my change from reserve vector and push_back to assign vector and fill it significantly affected to runtime in percentage( 5.13% -> 75.44% ). it might not only because my change, but possibly because how busy the machines at that time.
