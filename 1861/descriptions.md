# Problem 1861
## Summary
print final layout after rotating box.
there is only gravity, no other power exists.

## Approach
1. create result vector and fill all position as empty.
2. in original box, horizontally count number of stones until met obstacle or wall.
3. if met obstacle at (y, x), put it to result vector at the rotated position ( x, n - 1 - y ). when n is the number of rows. 
4. fill counted stones up on objstacle ( from x - 1 to x - 1 - count , n - 1 - y ).
5. repeat 2 ~ 4 until met wall.


### important points
don't need to consider horizontal power affecting.
the position (y, x) goes to ( x, n - 1 - y ) in rotated box.

