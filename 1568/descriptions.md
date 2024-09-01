# Problem 1568
## Summary
find the minimum number of vertex to remove make there is not only one island.
means it's ok there is two islands or no island.

## Approach
reference: https://en.wikipedia.org/wiki/Biconnected_component

1. Need to cluster island first.
2. if there is no or more than one island just return 0.
3. if there is onely one cluster.
3.1. if the cluster has less than three vertexes, then need to remove all vetexes to satisfy the requirement.
3.2. else check there is vertexes can divide graph to more than one.
3.2.1. if yes, removing any of cut vertexes will divide a cluster to two, you just need to remove 1.
3.2.2. if no, removing two vertexes will always divide a cluster to two. return 2.

### important points
1. clustering.
2. way to decide the biconnected component.
3. need to exlucde edge cases of small number of vertexes construct the only island.
