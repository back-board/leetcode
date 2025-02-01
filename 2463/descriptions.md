# Problem 2463
## Summary
return minimum distance required to fix all robots with factories of limited capacities.

## Approach
Need to use DP, cause 100 robots & 100 factories will need O(N!) with brute-force method.
It was ambiguous how to configure caching at the first time.
Designing caching was almost all parts.

### caching method
- 2 directional vector which will store the final minimum distance value.
- given distance value's range is in long long range, but because I choose one of exit policy's return value for recursive function as LLONG_MAX ( which will mean it is not available to fix all robots ), 
and I didn't want to change variable type in middle of calculation, it caching value range become unsigned long long. In addition there is no distance smaller than zero exists.
- most tricky part was indexes of caching.
because I started with sorting both robots and factories in ascending order,
distance always become smaller when the factory takes robots not in mixed order, but in consecutive way. (it is not economic choosing factory choose not consecutive robots but separate ones )
therefore, 2 indexes for caching are choosen as factory index and robot index.

### important points
- DP
- exit policy
- need to deal large integer

Maybe need to improve the solution, cause this solution only beats 53.40% in time complexity
