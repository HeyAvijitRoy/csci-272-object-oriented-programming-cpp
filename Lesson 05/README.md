# CSCI 272 - Lesson 05: Streams and Input/Output

Instructor: Avijit Roy

Teaching page: https://avijitroy.com/teaching/

This lesson explains how streams read, format, and write data, and how a program recovers when input fails. Review strings, pointers, classes, and function templates first.

## Learning Outcomes

After completing the examples, you should be able to:

- distinguish `cin`, `cout`, `cerr`, and `clog`;
- format numbers and columns without changing stored values;
- use `put()`, `write()`, `get()`, and `getline()`;
- read formatted values from an `istringstream`;
- trace leftover letters, spaces, and newlines across repeated reads;
- explain requested counts, `gcount()`, and partial reads; and
- distinguish error flags from pending input and recover using `clear()` and `ignore()`.

## Use the Examples as Experiments

Read the opening comments, predict the result, run the unchanged program, change one thing, and explain what happened. Each `.cpp` file has its own `main()`: compile and run one file at a time using your IDE. Restart the program between separate experiments; repeated reads inside a loop are different from launching the program again.

## Learning Path

| File | Main idea | Expected behavior and experiment |
| --- | --- | --- |
| [01_standard_streams.cpp](01_standard_streams.cpp) | Standard input, output, errors, and logs | `25` succeeds; `hello` fails conversion; `-5` fails age validation. Compare the two error cases. |
| [02_formatting_output.cpp](02_formatting_output.cpp) | Precision, width, fill, alignment, and number bases | Pi prints as `3.1` with precision 2, then `3.14` with `fixed`. Change the GPA and column widths. |
| [03_card_pointer_alias.cpp](03_card_pointer_alias.cpp) | Optional review of objects, pointers, and `typedef` | Object and pointer access display the same card. Change a member through the pointer and display it through the object. |
| [04_stream_output.cpp](04_stream_output.cpp) | Formatted output versus `put()` and `write()` | Writing seven characters of `3.141593` prints `3.14159`. Try counts 3, 5, and 8. |
| [05_stringstream_input.cpp](05_stringstream_input.cpp) | Extract typed values from text | `Alice 30` parses; `Bob twenty` and `Bob Smith 22` fail. Explain which extraction fails. |
| [06_get_and_getline.cpp](06_get_and_getline.cpp) | Read a character, discard the rest of its line, then read a name | Enter `A`, then `Alice Johnson`. Remove the cleanup and predict why the name becomes empty. |
| [07_unformatted_io.cpp](07_unformatted_io.cpp) | Counted reads and partial reads from a fixed string | Reads 20 letters, then the remaining 6; the second read sets EOF and failure flags. Change the first count to 10 and predict the second count. |
| [07a_leftover_input.cpp](07a_leftover_input.cpp) | Three keyboard reads, visible whitespace, and a word test | `Alice` + Enter supplies all three reads: `Al`, `ic`, `e\n`. Follow the experiments below. |
| [07b_input_method_comparison.cpp](07b_input_method_comparison.cpp) | Compare four methods with the same pending newline | `>> char` skips it, `get()` consumes it, `getline()` returns an empty line, and `read(2)` includes it in the count. |
| [08_stream_error_recovery.cpp](08_stream_error_recovery.cpp) | Detect failure, clear flags, discard invalid input, retry | Enter `abc`, then `25`; compare flags before failure, after failure, and after recovery. |
| [09_student_registration.cpp](09_student_registration.cpp) | Combine classes, templates, validation, and formatting | Read a full name, age, and GPA; retry invalid input and print a formatted record. Try GPA `4.5`, then `3.876`. |

## Code 07 Keyboard Experiments

Use `07a_leftover_input.cpp`. Its default setting keeps leftover input. The program requests **two characters per round**, three times, then reads a word. It prints newline as `[\n]` and space as `[space]`.

1. Enter `Alice` + Enter at round 1. All three reads finish from that line: `[A][l]`, `[i][c]`, `[e][\n]`. Enter `Bob` + Enter at the word test. The final `get()` displays `[\n]`.
2. Restart. Enter `AB` + Enter, then `C` + Enter, then `D` + Enter. Reads produce `[A][B]`, `[\n][C]`, `[\n][D]`. The pending newline supplies one of the two requested characters in rounds 2 and 3. Enter `Bob` + Enter for the word test.
3. Restart. Enter `Alice Johnson` + Enter. The reads consume `Al`, `ic`, and `e `; `cin >> test` immediately consumes the leftover word `Johnson`.
4. Set `discardRemainingLine` to `true`, rebuild, and restart. Enter `Alice`, `Carol`, and `David` on separate lines. Each round reads two letters and discards the rest of its line. Compare with entering just `A` + Enter each round, where `read()` itself consumes the newline.

In a typical line-based terminal, a newly typed `C` still needs Enter before the program receives it. A pending newline counts toward a read; it does not submit new keyboard input. Console behavior can vary, so record your environment's observations. See [the keyboard experiment](07a_leftover_input.cpp) for the complete code and [the input-method comparison](07b_input_method_comparison.cpp) for a repeatable trace without keyboard timing.

## Ideas to Keep Separate

**Formatted versus unformatted input:** `cin >> test` skips leading whitespace and reads one word. `get()` reads one character, including a newline. `read()` requests a count of characters, including whitespace, and may span several lines while waiting for that count. `getline()` reads through a newline, consumes it, and does not store it in the string.

**Flags versus characters:** `clear()` resets error flags. `ignore(..., '\n')` discards through a newline. Successful character reads do not need `clear()`. Do not discard another line if your read has already consumed its newline.

**Counts versus strings:** `read()` does not add a null terminator. Write only the characters actually extracted with `write(buffer, count)`; do not print the raw buffer as a C-style string. Save `gcount()` immediately after the operation being measured. Keep every read/write count within the available array or character data.

**Formatting versus stored values:** `fixed`, precision, fill, and alignment persist until changed; `setw()` applies to the next formatted field. Width is a minimum and does not truncate long text.

**Conversion versus full validation:** Examples 08 and 09 accept numeric prefixes such as `25abc` as `25` and discard the suffix. Example 08 checks extraction only; example 09 also checks age and GPA ranges. Validating the entire line is a later stringstream exercise.

**Recovery versus retrying forever:** End-of-file and serious I/O errors stop the recovery examples. Do not run a retry loop with its `clear()` or `ignore()` removed: it can repeatedly fail and flood the console. Predict that behavior or investigate with a single attempt.

## Checkpoint Challenges

1. Trace the pending input after each two-character read of `Alice Johnson\n`. Which operation consumes the space? Which consumes the final newline?
2. Modify the word test to use `getline()` and predict its result after each experiment. Preserve the cleanup comparison.
3. Add a second student record to the integrated example. Explain how each numerical input leaves the stream ready for the next full name.
4. Extend the stringstream example to reject a valid numeric prefix followed by unwanted text. Then add a student ID to `09_student_registration.cpp` and reject `123abc` when an integer ID is required.
5. Extend the registration example to store three students in an array or vector and print a formatted report. Use full names, validate numerical input, and display each GPA with two decimal places. File storage is not required.

## Reflection Check

1. Why can the second prompt finish before you type anything new?
2. Why does a pending newline satisfy `get()` but not `cin >> test`?
3. Why can `read(buffer, 2)` need another line even after you press Enter?
4. Why does `clear()` alone fail to fix invalid numerical input?
5. Why is `gcount()` important after a short read?
6. Why can the displayed GPA change while its stored value stays the same?
