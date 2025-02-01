# Problem 827
## Summary
find max size of islands when one dot can be flipped from 0 to 1.
as a simplest way, solution needs to be executed in 2-step of grouping and find size.
there may be better solution in time complexity. this is just a simplest approach that came my mind immediately after reading the problem.

## Approach
- cluster 1s in array
  * need to number each cluster
  - find 1
  - mark each position as cluster number
  - grow through it's neighbor( both BFS or DFS available )
  - store the size of cluster
- calculate max size with flip
  - look around neighbors' island group
  - without duplicated group add size of each group ( need to add 1 to the final size to reflect flip )
  - calculate maximum available size

### important points
