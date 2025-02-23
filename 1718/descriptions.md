# Problem 1718
## Summary
return "largest" valid sequence
valid sequece is:
- 1 occurs once 
- 2 ~ n: 
  - occurs twice
  - distance between occurrence is same with n

## Approach
- backtracking
- exit criteria: no more numbers to fill left
- recursion through index, take largest number available
- if recursion cannot reach the status there is no number left, then reverse it's choices.

## Wrong approaches I did.
loop through numbers not indexes -> this doesn't guarantee largest sequence
