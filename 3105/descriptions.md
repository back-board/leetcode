# Problem 3105
## Summary
find length of longest subarray which is strictly increasing or descreasing
easy level, and looks like easy, too.
because of this reason, I might disturbed.

## Approach
I don't want to be consider edges, I separated cases for length 1 and 2.
for longer cases,
check current diffrence. ( which is d in code )
compare with last difference. ( which is diff in code )

by the values of differences update lenth and move left to last or right
update diff as d
last as right
maxLength as maximum value of maxLength & l

## important points

