# Problem 2698
## Summary
find all sum of numbers under specified condition
- punishment number definition:
  when i * i = n,
  n can be splited to numbers whose sum is n

for example:
- 1 * 1 = 1 & 1 = 1
- 9 * 9 = 81 & 8 + 1 = 9
- 10 * 10 = 100 & 10 + 0 = 100

## Approach
- global cache: need to share calculated values between trials
- strip calculation don't need
  - splited parts of square whose value is larget than i
  - if any of splits satisfies condition, then don't need to calculate another split.

## important points

