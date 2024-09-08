# Problem 725
## Summary
Split linlked list evenly as possible as can to k parts.

## Approach
because maximum possible number of nodes in a linked list( 1000 ) is not that big, I choose brute forcemethod. (Is there another way, anyway?)

1. Find the length of linked list (N)
2. Parts linked list to k parts
2.1 first n parts ( N % k ) will have 1 more size --> ( N / k + 1 )
2.2 left will have N / k size


