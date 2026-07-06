# Module09 - ex02: PmergeMe

## Project Overview

This exercise requires you to implement the **Ford-Johnson sorting algorithm** (also known as merge-insert sort) in C++. The goal is to sort a large sequence of positive integers while **minimizing the number of comparisons**.

The project name `PmergeMe` stands for "Pair Merge Sort" - a reference to how the algorithm pairs and merges elements efficiently.

---

## What You Need to Know

### 1. **Sorting Algorithms & Optimization**

#### Ford-Johnson Algorithm (Merge-Insert Sort)
- A hybrid sorting algorithm that combines **merge sort** and **insertion sort**
- **Minimizes the number of comparisons** needed to sort elements
- Theoretically optimal for minimizing comparisons
- Strategy:
  1. Pair up elements and compare them
  2. Recursively sort the "winners" (larger elements of each pair)
  3. Use binary insertion to insert the "loser" elements (smaller elements) into the sorted list
  4. This approach reduces total comparisons

#### Why This Algorithm?
- `std::sort` minimizes runtime but not necessarily comparisons
- Ford-Johnson is mathematically proven to minimize comparisons
- Useful in scenarios where comparison is expensive (e.g., custom objects, I/O operations)

### 2. **C++ Containers**

You must use **two different containers**:

#### std::vector
- Dynamic array-like container
- Fast random access O(1)
- Slow insertion/deletion in middle O(n)
- Use for one implementation

#### std::deque (Double-Ended Queue)
- Allows efficient insertion/deletion at both ends O(1)
- Random access O(1)
- Better for frequent insertions
- Use for the other implementation

#### std::list
- Doubly-linked list
- Efficient insertion/deletion anywhere O(1)
- Slow random access O(n)
- Optional but useful for Ford-Johnson

### 3. **C++ Templates**

Your class should use templates to work with any numeric type:

```cpp
template <typename T>
class PmergeMe {
    // Implementation
};
```

This allows sorting `int`, `long`, `float`, `double`, etc.

### 4. **Input/Output Requirements**

#### Input Format
```bash
./a.out 3 5 8 2 1 9
./a.out `seq 1 3000 | tr '\n' ' '`  // Large sequence
```

#### Output Format
```
Before: 3 5 8 2 1 9
After:  1 2 3 5 8 9
Time to process a range of 6 elements with std::vector: 0.00023 ms
Time to process a range of 6 elements with std::deque : 0.00019 ms
```

#### Error Handling
- Print error if arguments are not positive integers
- Print error if duplicate values are passed
- Handle negative numbers appropriately

### 5. **Performance Analysis**

#### What to Measure
1. **Execution time** in milliseconds
2. **Number of comparisons** (optional but recommended)
3. Compare between `std::vector` and `std::deque`

#### Tools
- `std::chrono::high_resolution_clock` for precise timing
- `std::chrono::microseconds` or `std::chrono::milliseconds` for time units

```cpp
#include <chrono>

auto start = std::chrono::high_resolution_clock::now();
// Sort operation
auto end = std::chrono::high_resolution_clock::now();
auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
```

### 6. **Key Algorithm Steps**

**Ford-Johnson Algorithm:**

1. **Base Case**: If 1 or 2 elements, sort directly
2. **Pairing Phase**: 
   - Pair consecutive elements: (a[0], a[1]), (a[2], a[3]), ...
   - Compare each pair, keep larger elements in one list
3. **Recursive Phase**:
   - Recursively sort the list of larger elements
4. **Insertion Phase**:
   - Use **binary search** to find insertion position for each smaller element
   - Insert smaller elements into the sorted list

### 7. **Complexity Analysis**

#### Time Complexity
- **Best/Average/Worst**: O(n log n) like merge sort
- **Comparisons**: Theoretically ~0.12 * n * log2(n) comparisons (very optimal)

#### Space Complexity
- O(n) for additional storage during sorting

---

## Implementation Checklist

### Required
- [ ] Implement `PmergeMe` class with templates
- [ ] Use `std::vector` for one implementation
- [ ] Use `std::deque` for another implementation
- [ ] Implement Ford-Johnson algorithm (or equivalent optimized sorting)
- [ ] Parse command-line arguments (positive integers only)
- [ ] Display "Before" and "After" sequences
- [ ] Measure and display execution time for both containers
- [ ] Proper error handling

### Optional (Recommended)
- [ ] Display number of comparisons
- [ ] Handle very large sequences (thousands of elements)
- [ ] Reject duplicate values
- [ ] Use `std::list` for comparison

---

## Example Usage

```bash
# Simple example
$ ./a.out 3 5 8 2 1 9
Before: 3 5 8 2 1 9
After:  1 2 3 5 8 9
Time to process a range of 6 elements with std::vector: 0.00023 ms
Time to process a range of 6 elements with std::deque : 0.00019 ms

# Large sequence
$ ./a.out `seq 1 1000 | tr '\n' ' '`
Before: 1000 999 998 ... 2 1
After:  1 2 3 ... 998 999 1000
Time to process a range of 1000 elements with std::vector: 0.45 ms
Time to process a range of 1000 elements with std::deque : 0.42 ms

# Error cases
$ ./a.out 3 abc 5
Error: abc is not a valid positive integer

$ ./a.out 3 -5 8
Error: -5 is not a positive integer

$ ./a.out 3 5 3 8
Error: Duplicate value 3
```

---

## Algorithm Pseudocode

```
FordJohnson(array):
    if length <= 1:
        return array
    
    # Pairing Phase
    winners = []
    losers = []
    
    for i = 0; i < length; i += 2:
        if i + 1 < length:
            if array[i] < array[i+1]:
                winners.append(array[i+1])
                losers.append(array[i])
            else:
                winners.append(array[i])
                losers.append(array[i+1])
        else:
            # Odd element left unpaired
            losers.append(array[i])
    
    # Recursive Phase
    sortedWinners = FordJohnson(winners)
    
    # Insertion Phase
    result = sortedWinners
    for loser in losers:
        # Use binary search to find position
        position = binarySearch(result, loser)
        result.insert(position, loser)
    
    return result
```

---

## Content to Implement

### PmergeMe.hpp
- Template class declaration
- Constructor, destructor, copy constructor, assignment operator
- `sort()` method that takes a vector of values
- Private helper methods:
  - `mergeInsertSort()` - main algorithm
  - `binarySearch()` - for insertion
  - Possibly comparison counter

### PmergeMe.cpp
- Implement all methods
- Ford-Johnson algorithm logic
- Binary search implementation
- Comparison tracking (optional)

### main.cpp
- Parse command-line arguments
- Validate input (positive integers, no duplicates)
- Create `PmergeMe` instances for both containers
- Measure time and comparisons
- Display results

---

## Study Resources

### Topics to Review
1. **Sorting Algorithms**: Merge sort, insertion sort, binary search
2. **C++ Templates**: Class templates, template methods
3. **STL Containers**: `std::vector`, `std::deque`, iterators
4. **Algorithm Optimization**: Minimizing comparisons, time complexity analysis
5. **Performance Measurement**: `std::chrono`
6. **Binary Search**: Implementation and use cases

### Key Differences Between Containers
| Aspect | vector | deque |
|--------|--------|-------|
| Random Access | O(1) | O(1) |
| Push Back | O(1) amortized | O(1) amortized |
| Push Front | O(n) | O(1) |
| Pop Back | O(1) | O(1) |
| Pop Front | O(n) | O(1) |
| Insert Middle | O(n) | O(n) |

---

## Common Pitfalls to Avoid

1. ❌ Not handling the case where there's an odd number of elements
2. ❌ Not validating input (accepting negative numbers or non-integers)
3. ❌ Allowing duplicate values without error
4. ❌ Inefficient binary search (should be O(log n))
5. ❌ Not measuring time accurately (use high-resolution clock)
6. ❌ Forgetting to implement for both containers
7. ❌ Memory leaks in recursive algorithm
8. ❌ Not handling edge cases (empty array, single element, two elements)

---

## Next Steps

1. Start with `PmergeMe.hpp` - design the class template
2. Implement basic constructors and destructors
3. Implement binary search helper
4. Implement Ford-Johnson algorithm step by step
5. Add timing measurements
6. Test with different container types
7. Test with edge cases
8. Optimize if needed

Good luck with your implementation! 🚀
