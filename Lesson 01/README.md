# Lesson 01 — Functions, Arrays, and Pointers

This lesson reviews three ideas that later object-oriented programs depend on: dividing work into functions, organizing related values in arrays, and using addresses through pointers.

The files are small on purpose. Each program isolates one idea so that you can predict, run, change, and explain it before combining ideas in larger programs.

## Learning Outcomes

After working through the core examples, you should be able to:

- identify a function's return type, name, parameters, arguments, and returned value;
- explain why a declaration must be visible before a function call;
- distinguish local scope from other scopes;
- use default arguments and overloaded functions appropriately;
- predict whether pass by value or pass by reference can change an original variable;
- declare, initialize, access, and traverse a fixed-size array;
- pass an array and its size to a function;
- distinguish a value, its address, a pointer, and a dereferenced pointer;
- explain the relationship between arrays and pointer arithmetic;
- allocate and release one value or an array with `new`, `delete`, and `delete[]`; and
- pass a pointer to a function while checking for `nullptr`.

Examples 16 and 17 are optional extensions. Complete the core sequence first.

## Use the Examples as Experiments

For every file, use this cycle:

1. **Read:** Find the main idea in the opening comment and trace the code from `main()`.
2. **Predict:** Write down the output or compiler behavior before running anything.
3. **Run:** Compile and execute the unchanged program.
4. **Compare:** Mark each part of your prediction as correct or incorrect.
5. **Change:** Complete at least one `TRY THIS` task in the source file.
6. **Explain:** In one or two sentences, explain why your change produced its result.
7. **Restore:** Undo experimental changes before moving to the next file.

Seeing a different result is useful when you can explain the difference. Do not rush directly to the expected result.

## Compile and Run

In Dev-C++, open one `.cpp` file, compile it, and run it as a console program. Each file is a separate program with its own `main()` function, so do not add all 17 files to one project.

## Core Learning Path

The exact hexadecimal memory addresses will vary between runs and computers. Focus on which addresses are equal or different.

| File | Main idea | What to expect from the unchanged program |
| --- | --- | --- |
| [`01-functions-basics.cpp`](01-functions-basics.cpp) | Parameters, arguments, and return values | `10 / 5` produces `Result: 2`. |
| [`02-function-prototypes.cpp`](02-function-prototypes.cpp) | Declaration before use | The prototype lets `main()` call a function whose definition appears later; the result is `20`. |
| [`03-function-scope.cpp`](03-function-scope.cpp) | Local scope | The function prints `20`, while `main()` still prints its own value, `10`. |
| [`04-default-arguments.cpp`](04-default-arguments.cpp) | An omitted argument uses a declared default | The greetings use `Student`, `Alex`, and `Maria` in that order. |
| [`05-function-overloading.cpp`](05-function-overloading.cpp) | The compiler selects a function from its parameter list | The three calls select the two-`int`, three-`int`, and two-`double` versions and produce `15`, `12`, and `6.2`. |
| [`06-pass-by-value.cpp`](06-pass-by-value.cpp) | A function changes a copy | The function's copy changes to `100`; the original value in `main()` remains `10`. |
| [`07-pass-by-reference.cpp`](07-pass-by-reference.cpp) | A reference names the original object | `value` becomes `100`, then `101`; `x` and `y` exchange values. |
| [`08-arrays-basics.cpp`](08-arrays-basics.cpp) | Indexing and traversal | Indexes `0` through `5` display the six stored values. |
| [`09-arrays-and-functions.cpp`](09-arrays-and-functions.cpp) | An array is processed with a separate size | The program prints all values, then reports maximum `27` and minimum `8`. |
| [`10-pointers-basics.cpp`](10-pointers-basics.cpp) | Address-of and dereference operators | `pointer` equals `&number`, `*pointer` equals `15`, and `&pointer` is a different address. |
| [`11-pointers-modify-values.cpp`](11-pointers-modify-values.cpp) | Two expressions access one object | `number` and `*pointer` change together: first `10`, then `50`, then `100`. |
| [`12-pointers-and-arrays.cpp`](12-pointers-and-arrays.cpp) | Index notation and pointer arithmetic | Both loops print `10 20 30 40 50`; element addresses progress through contiguous memory. |
| [`13-dynamic-memory.cpp`](13-dynamic-memory.cpp) | One dynamically allocated integer | The program prints value `25`, releases its memory, and sets the pointer to `nullptr`. |
| [`14-dynamic-arrays.cpp`](14-dynamic-arrays.cpp) | Runtime-sized dynamic array | For size `4`, the generated values are `10 20 30 40`; non-positive or invalid input is rejected. |
| [`15-pointer-function-parameters.cpp`](15-pointer-function-parameters.cpp) | A function receives an address | The function follows the address of `number` and changes its value from `10` to `100`. |

## Optional Extensions

| File | Main idea | What to expect from the unchanged program |
| --- | --- | --- |
| [`16-advanced-pointer-examples.cpp`](16-advanced-pointer-examples.cpp) | Changing a pointer versus changing a copy of it | The local copy reaches `77` inside the first function, but the caller's pointer still reaches `15`; the pointer-to-pointer and reference-to-pointer examples redirect the caller's pointers to `77`. |
| [`17-function-pointers-optional.cpp`](17-function-pointers-optional.cpp) | Storing and calling a function address | The indirect calls print `2, 2` and `10, 20`. |

These extensions are previews, not assumed prerequisites for the next lesson. Ask for help if the additional `*`, `&`, or function-pointer syntax obscures the core idea.

## Required Try-It Tasks

Complete at least one source-file task for every example assigned in class. The following tasks form a recommended path:

1. In `01`, test integer-looking values that produce a fractional result, such as `7 / 2`. Explain why the result is `3.5`, not `3`.
2. In `02`, temporarily remove the prototype and record the compiler's message. Restore it and explain what information the prototype supplies.
3. In `03`, test one out-of-scope name at a time. These are intentional compile-time experiments; restore the working code afterward.
4. In `04`, add a second parameter with a default value and call the function with zero, one, and two explicit arguments.
5. In `05`, add a three-`double` overload. Then explain why changing only a return type cannot create a valid overload.
6. In `06` and `07`, print the relevant addresses. Use them to explain the difference between a copy and a reference.
7. In `08`, calculate and print the sum of the six elements without writing six separate addition statements.
8. In `09`, implement `calculateSum()` and `calculateAverage()`. Test them with the existing values before changing the array.
9. In `10`, draw three boxes labeled `number`, `pointer`, and `&pointer`. Put the correct value or address relationship in each box.
10. In `11`, add a second pointer to `number`, modify the value through it, and predict all three displayed values.
11. In `12`, match each `numbers[i]` expression with its equivalent `*(numbers + i)` expression.
12. In `13`, explain why `delete` must occur exactly once and why dereferencing the pointer afterward would be invalid. Do not perform the invalid dereference.
13. In `14`, replace the generated values with user input, then calculate their total.
14. In `15`, write a pointer-based function that swaps two integers. Check both pointers for `nullptr` before dereferencing them.
15. In `16` or `17`, complete the challenge in the source only after you can explain examples `10` through `15` without guessing.

## Checkpoint Challenges

These tasks combine ideas without providing finished code.

### Checkpoint A — Array Report

Create a program with an array containing `12, 7, 19, 4, 11`. Write separate functions to display the array, calculate its sum, find its minimum, and find its maximum.

Expected result:

```text
Values: 12 7 19 4 11
Sum: 53
Minimum: 4
Maximum: 19
```

### Checkpoint B — Reference and Pointer Comparison

Start with two variables containing `8` and `3`. Write one swap function using references and a second swap function using pointers. Reset the variables between tests so that both functions receive the same starting values.

Expected behavior: each function changes the original variables, so the displayed pair becomes `3 8`. Your explanation must describe how each function reaches the originals.

### Checkpoint C — Dynamic Score List

Ask the user for a positive number of scores. Dynamically allocate an array, read the scores, calculate their average in a function, release the array with `delete[]`, and set the pointer to `nullptr`.

Test case:

```text
Number of scores: 4
Scores: 70 80 90 100
Average: 85
```

Also test `0` and a negative size. The program should reject both without allocating an array.

## Safety Rules for Pointer Experiments

Some incorrect pointer programs compile but have **undefined behavior**. Undefined behavior has no reliable expected output: a program might crash, print an accidental value, corrupt data, or appear to work.

Do not deliberately:

- access an array outside indexes `0` through `size - 1`;
- dereference `nullptr`;
- dereference a pointer after `delete` or `delete[]`;
- use `delete` twice on the same allocation; or
- pair `new[]` with `delete` instead of `delete[]`.

For these cases, explain the violation and correct the code without running the invalid operation.

## Reflection Check

Before considering the lesson complete, answer these questions without running the programs:

1. When should a parameter be passed by value rather than by reference?
2. Why does an array-processing function also need the array size?
3. What is the difference between `pointer`, `*pointer`, and `&pointer`?
4. Why does changing `*pointer` also change the variable to which it points?
5. Why must a dynamic array be released with `delete[]`?
6. Which examples are most directly preparing you to work with objects later, and why?

If you cannot yet explain an answer, return to the smallest example that demonstrates it and repeat the predict-run-change-explain cycle.
