# Problem 2364
## Summary
problem description itself is concise.
no additional explanation required.

## Approach
1. find count of indexes having same difference ( nums[i] - i )
2. calculate total number of combinations array
3. subtract number of combinations from same difference count when the count is larger than 1.


### important points
1. based on (j - i != nums[j] - nums[i]) is the same as (nums[i] - i != nums[j] - j), count values at hashmap.
2. need to know how to calculate number of combinations.

