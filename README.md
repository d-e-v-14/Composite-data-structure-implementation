# Composite-Data-Structure-Implementation

# Interval Merger

## Overview
The **Interval Merger** is a composite data structure implementation that maintains a set of non-overlapping intervals. When a new interval is added, it merges with existing intervals if there is an overlap, ensuring that the stored intervals remain sorted and non-overlapping.This algorithm is based on binary search trees. Whenever a new node is added, it is either allotted to left branch or the right branch, based on whether it satisfies the condition or not.

## Features
- **Efficient Interval Merging:** Ensures that overlapping intervals are merged automatically.
- **Optimized Retrieval:** Provides a sorted list of non-overlapping intervals.
- **Balanced Time Complexity:** Uses balanced trees or sorted lists for efficient insertion and merging.

## Operations
### `addIntervals(start, end)`
- Adds a new interval `[start, end]`.
- If it overlaps with existing intervals, without merging them into one.
- Maintains the set of intervals in sorted .
- **Time Complexity:** `O(log n)` for insertion using balanced trees.

### `addMergedIntervals(start, end)`
- Adds a new interval `[start, end]`.
- If it overlaps with existing intervals, merging them into one.
- Maintains the set of intervals in sorted and Non-Overlapping manner .
- **Time Complexity:** `O(log n)` for insertion and merging using balanced trees.

### `printtree()`
- Returns the current set of non-overlapping/overlapping, merged intervals in ascending order.
- **Time Complexity:** `O(n)` for retrieval.

### `createNode(start, end)`
- Adds a new node and assigns a new interval for addIntervals and addMergedIntervals functions `[start, end]`.
- **Time Complexity:** `O(1)` for creation of node.

### `overlap_bool(interval 1, interval 2)`
-Returns true if two intervals overlap or not based on their start and end values
- **Time Complexity:** `O(1)` for checking if the intervals overlap.
### `mergedIntervals(Interval pointer a, interval 2)`
- Modifies the pointer a for use in program without creating a new variable assignment.
- **Time Complexity:** `O(1)` merging two nodes using balanced trees.

### `Tabspace(level)`
- Indents the given tree while printing, for better understanding.
- **Time Complexity:** `O(1)` for insertion and merging using balanced trees or sorted lists.

## Example Usage
```python
intervals = IntervalMerger()
intervals.addInterval(1, 5)
intervals.addInterval(6, 8)
intervals.addInterval(4, 7)
print(intervals.getIntervals())  # Output: [[1, 8]]
```

## Complexity Analysis
- **Time Complexity(Main Tasks):**
  - `addInterval()`: `O(log n)` (using balanced trees or sorted lists).
  - `addMergedInterval()`: `O(log n)` (using balanced trees or sorted lists).
  - `getIntervals()`: `O(n)` (retrieving all intervals).
- **Space Complexity:** `O(n)` (storing non-overlapping intervals).

## Applications
- **Database Range Queries:** Efficiently manage non-overlapping data ranges.
- **Event Scheduling:** Merge overlapping time slots.
- **Memory Management:** Allocate and merge memory blocks efficiently.
- **Network Routing:** Manage IP address ranges.

## Future Enhancements
- Support for **deleting** an interval.
- Implement **optimized merging** using segment trees.
- Extend to **2D interval merging** for applications in computational geometry.

---
Developed with efficiency and simplicity in mind! Also included a menu driven program for better testing and enhanced understanding!

