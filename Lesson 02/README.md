# Lesson 02 — Function Templates and Vectors

Lesson 01 used functions, arrays, and pointers to work with data. This lesson adds a function template that works with more than one type, then introduces `std::vector`: a collection that manages its own storage as elements are added or removed.

The 12 files are separate, runnable programs. Work through them in order so that the difference between a vector's elements and its available storage becomes clear before you study growth and reallocation.

## Learning Outcomes

After working through the examples, you should be able to:

- explain how a function template uses a type parameter and why the arguments in `largerOf(T, T)` must lead to one type for `T`;
- create an empty vector, initialize one with values, copy one, and construct one from a valid iterator range;
- traverse a vector by index, range-based loop, and iterator;
- explain why an index commonly uses `std::size_t` rather than `int`, and why unsigned subtraction needs care;
- add elements with `push_back()`, `insert()`, and `emplace_back()`, and explain what it means to construct an object;
- distinguish `[]`, `at()`, `front()`, and `back()`;
- use `sort()` and `reverse()` from `<algorithm>`;
- distinguish `size()` from `capacity()` and explain why a vector may allocate more space than it currently needs;
- distinguish `reserve()` from `resize()`, explain what `shrink_to_fit()` requests, and identify results that depend on the C++ library implementation; and
- predict how inserting or erasing in the middle shifts elements and can invalidate earlier iterators or references.

## Use the Examples as Experiments

For every file, use the same cycle as Lesson 01:

1. **Read:** Find the main idea in the opening comment and trace the code from `main()`.
2. **Predict:** Write down the values or relationships you expect to see.
3. **Run:** Compile and execute the unchanged program.
4. **Compare:** Mark what your prediction got right and what surprised you.
5. **Change:** Complete at least one `TRY THIS` task in the source file.
6. **Explain:** Describe why the change produced its result.
7. **Restore:** Undo experimental changes before moving to the next file.

For capacity and memory-address examples, predict relationships rather than exact numbers or addresses. Your C++ library chooses its own capacity growth strategy.

## Compile and Run

Open one `.cpp` file in your IDE and use its compile and run controls. Each file has its own `main()` function, so run one example at a time rather than adding all 12 files to one project.

## Learning Path

| File | Main idea | What to expect from the unchanged program |
| --- | --- | --- |
| [`01_function_template.cpp`](01_function_template.cpp) | One function template for several types | The larger values are `25`, `7.5`, `Z`, and `Banana`. Both arguments in each call have the same type. |
| [`02_vector_basics.cpp`](02_vector_basics.cpp) | Indexing, `push_back()`, and `size()` | The original values are `10 20 30`; adding `40` makes four elements. |
| [`03_vector_initialization.cpp`](03_vector_initialization.cpp) | Empty, value, fill, copy, and range construction | The range copy contains the first three values: `10 20 30`. The five-element fill vector contains five zeros. |
| [`04_vector_traversal.cpp`](04_vector_traversal.cpp) | Index, range-based, and iterator loops; `std::size_t` | All three methods visit `10 20 30 40 50` in order. |
| [`05_vector_insert_elements.cpp`](05_vector_insert_elements.cpp) | `push_back()`, `insert()`, and `emplace_back()` | The final fruit order is `Apple`, `Grapes`, `Banana`, `Orange`, `Mango`. |
| [`06_vector_access_modify.cpp`](06_vector_access_modify.cpp) | `[]`, `at()`, `front()`, and `back()` | The final values are `100 200 300 40 500`. |
| [`07_vector_algorithms.cpp`](07_vector_algorithms.cpp) | `sort()`, `reverse()`, `clear()`, and `empty()` | Sorting produces `1 2 3 5 8`; reversing produces `8 5 3 2 1`; clearing leaves size `0` and prints `Is empty? true`. |
| [`08_vector_size_capacity.cpp`](08_vector_size_capacity.cpp) | Size, capacity, and reallocation | Values grow from `10` through `100`; size increases on every addition, while capacity changes only when more storage is needed. |
| [`09_vector_reserve.cpp`](09_vector_reserve.cpp) | Compare `reserve()` with `resize()`, then exceed reserved capacity | `reserve(5)` creates no elements; a separate vector resized to five contains `0 0 0 0 0`. The first vector then adds 12 values and prints each observed capacity increase. |
| [`10_vector_shrink_to_fit.cpp`](10_vector_shrink_to_fit.cpp) | Request less unused capacity | Size stays `3` and values stay `10 20 30`; the capacity after the request may vary. |
| [`11_vector_insert_erase.cpp`](11_vector_insert_erase.cpp) | Shifting elements during insert and erase | Inserting `25` produces `10 20 25 30 40 50`; erasing index `3` then produces `10 20 25 40 50`. |
| [`12_student_scores.cpp`](12_student_scores.cpp) | Combine vector operations in a small application | The five scores average `86.2`; sorting reveals a lowest score of `74` and highest of `96`. An empty list is reported without calculating an average. |

## From Arrays to Vectors

Lesson 01 used fixed-size arrays and also showed that arrays allocated with `new[]` need a matching `delete[]`. A vector provides indexed access while managing its own storage.

| Question | Fixed-size array from Lesson 01 | Vector in Lesson 02 |
| --- | --- | --- |
| Can I add another element? | Its size is fixed after creation. | `push_back()` adds an element, growing storage when needed. |
| How do I access an element? | Use a valid index such as `values[0]`. | Use a valid index such as `values[0]`, or use `at()` for a checked access. |
| Who manages storage? | A local array ends with its scope; an array created with `new[]` needs `delete[]`. | The vector manages and releases its storage. |

Neither kind of `[]` access checks whether an index is valid. A vector's capacity may exceed its size, but only indexes below `size()` refer to elements.

## Ideas to Keep Separate

**Size versus capacity:** `size()` counts elements you may access. `capacity()` counts how many elements the vector can hold before it needs more storage.

**Reserve versus resize:** `reserve(5)` requests room for at least five elements but leaves the size unchanged. It does not make indexes `0` through `4` valid. Starting from an empty `vector<int>`, `resize(5)` creates five elements initialized to `0`, making those indexes valid. The resulting capacity may be greater than five.

**Growth versus a guaranteed factor:** A library may grow capacity from `5` to `10` to `20` so that several later `push_back()` calls reuse the new space. This reduces repeated moves or copies. The C++ standard does not require doubling, so use the program's printed capacity values to describe what happened on your system.

**Constructing an object:** To construct an object is to create it and initialize it. In `fruits.emplace_back("Mango")`, the vector uses `"Mango"` to construct a new `string` at the end. `emplace_back()` is useful for objects, but it does not prevent the vector from moving existing elements if storage must grow.

**Index types:** `int` can be negative. `std::size_t` is an unsigned type used for sizes; it cannot represent a negative index. Using an `int` with `size()` can cause signed-to-unsigned conversions. Check that a vector is not empty before calculating `size() - 1`.

## Recommended Try-It Tasks

Complete at least one source-file task for every example assigned in class. This is a recommended path through the lesson:

1. In `01`, change the integer inputs, then explain why `largerOf(10, 5.5)` cannot deduce one `T` from those two argument types. Restore the working call afterward.
2. In `02`, add two values with `push_back()` and predict the new size before running.
3. In `03`, change the range endpoint from `begin() + 3` to `begin() + 2`; explain why the endpoint itself is excluded.
4. In `04`, compare a range loop that copies each `int` with one that uses `int&` to change the original elements.
5. In `05`, insert a fruit at index `2`, then use the printed indexes to explain which existing fruits shifted.
6. In `06`, change one valid element using `at()`. Explain what an invalid `at()` index would do without running an out-of-bounds `[]` access.
7. In `07`, reverse the original unsorted vector without sorting first. Explain why reversal is not sorting.
8. In `08`, note when capacity and the underlying memory address change as values are added. Do not keep using an old pointer after reallocation.
9. In `09`, compare the empty vector after `reserve(5)` with the five values after `resize(5)`. Then compare `reserve(5)` with `reserve(20)` while adding the same number of elements.
10. In `10`, compare values before and after `shrink_to_fit()`. Explain which properties stayed the same even if capacity changed.
11. In `11`, insert at the beginning and erase from the middle. Trace the index and value of each shifted element.
12. In `12`, add another score and calculate the new average before running the program. Then follow its empty-list task and explain why the program skips the average and minimum/maximum.

## Checkpoint Challenges

These tasks combine ideas without providing finished code.

### Checkpoint A — Vector Report

Create a vector containing `8, 3, 10, 5`. Write functions to print its values, calculate its sum and average, and display the sorted order. Pass the vector by `const` reference to functions that only read it.

Expected result:

```text
Values: 8 3 10 5
Sum: 26
Average: 6.5
Sorted: 3 5 8 10
```

### Checkpoint B — Growth Diary

Start with an empty vector, call `reserve(3)`, then add six values with `push_back()`. After each addition, print the values, size, and capacity. Mark every step at which capacity changes. Explain why your output does not have to match another student's exact capacity values.

Expected relationships: the size runs from `1` to `6`, every printed value remains in order, and capacity is always at least size.

### Checkpoint C — Score Update

Start with the five scores from `12_student_scores.cpp`. Add a function that counts scores of `60` or higher. Insert a score of `55`, print the updated list, and recalculate the count and average. Predict the result before running.

Expected results: six scores, five passing scores, and an average of `81`.

## Safety Rules for Vector Experiments

An invalid index can be more serious than a wrong answer. Follow these rules while experimenting:

- Access only existing elements: valid indexes are `0` through `size() - 1` when the vector is not empty. `reserve()` does not make new indexes valid; `resize()` can create them.
- Do not run an out-of-bounds `[]` access. It has undefined behavior, so there is no reliable result to observe.
- `at()` checks its index and throws `std::out_of_range` for an invalid one; an uncaught exception stops the program.
- Call `front()` or `back()` only when the vector is not empty.
- After an insertion, erasure, or reallocation, do not assume an earlier iterator, pointer, or reference still identifies the same element. Obtain a fresh one.
- Avoid subtracting from an unsigned zero: check `empty()` before using `size() - 1`.

For unsafe cases, explain the problem and correct the code without executing the invalid operation.

## Reflection Check

Before considering the lesson complete, answer these questions without running the programs:

1. How does the compiler choose `T` for a call to `largerOf()`?
2. How is a vector with three elements different from a vector with capacity for three elements? Which operation, `reserve()` or `resize()`, creates elements?
3. What does `std::size_t` represent, and what can happen when a negative `int` is compared with a vector's size?
4. What does it mean to construct a `string` in a vector?
5. Why can adding one element cause every existing element to move?
6. Why is doubling capacity common but not a promise of `std::vector`?
7. Why can an iterator saved before `insert()` or `erase()` become unsafe to use afterward?
8. Which two operations in this lesson use `<algorithm>` rather than a vector member function?

If an answer is unclear, return to the smallest example that demonstrates it and repeat the predict-run-change-explain cycle.
