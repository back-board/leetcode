# Problem 2349
## Summary
design container service
need to create three functions - initializer, change, find

## Approach
combination of unordered_map and priority_queue

### variables
1. unordered_map<int, priority_queue<int, std::vector<int>, std::greater<int>>> containers 
  - map holds priority queue which stores the stored indexes of container
2. unordered_map<int, int> registrations
  - current status of registration pair ( index, container number )

### methods
- change
  - update registrations value as (index, number)
  - push new index to containers[number]

- find
  - find a top from containers[number]
  - check current status by registrations[index] == number
    - return index if true
    - pop the value if false ( new container took that index now )

## important points
