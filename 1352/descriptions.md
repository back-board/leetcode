# Problem 1352
## Summary
ProductOfNumbers(): initialization
add(int n) : add n at the end of storage
getProduct(int k): return product of last k

## Approach
need a stroage to store values.
in my case, I stored accumulated product of values.
track count of items added.
for special calculation I also stored lastProduct in separate variable
- accumulated product will calculate new value for add with this special variable.

need to special treatment to deal with zero!
- track the last position of zero

add(int n): store accumulated product(lastProduct)
- if n == 0 => set lastProduct = 1, update zero's position
- else calculate lastProduct

getProduct:
- if k >= current - lastzero: always 0
- if k == current : return lastProduct 
- if k < current - lastzero: lastProduct / product[current - k - 1 ]

## important points

