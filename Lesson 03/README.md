# Lesson 03 — Strings

This lesson uses `std::string` to store and work with text. The 14 examples are separate programs. Start with creating and reading strings, then move through traversal, searching, modification, conversion, and standard algorithms. The final program brings several ideas together.

## Learning Outcomes

After working through the examples, you should be able to:

- create, display, combine, and compare strings;
- explain why `cin >>` reads one word while `getline()` reads a whole line;
- use `length()`, `size()`, `empty()`, and valid indexes to inspect text;
- traverse a string by index or range-based loop, and explain why a `char&` can change the stored character;
- explain case-sensitive comparison and build a comparison that ignores letter case;
- extract text with `substr()` and search with `find()`, `find_first_of()`, and `find_last_of()`;
- use the starting-position argument of `find()` to locate repeated matches;
- modify text with character assignment, `replace()`, and `insert()`;
- convert numeric text with `stoi()` or `stod()`;
- check whether a numeric conversion used the whole input string; and
- use `begin()`, `end()`, and `std::count()` to count characters.

## Use the Examples as Experiments

For each file: read its opening comment, predict its output, run the unchanged program, complete at least one `TRY THIS` task, and explain what changed. Restore your experiment before moving to the next file.

Open one `.cpp` file in your IDE and use its compile and run controls. Each file has its own `main()`, so run one example at a time.

## Learning Path

| File | Main idea | What to look for |
| --- | --- | --- |
| [`01_string_basics.cpp`](01_string_basics.cpp) | Create, display, index, and change a string | Index `0` selects the first character; assigning through a valid index changes the string. |
| [`02_string_input.cpp`](02_string_input.cpp) | Read a word or a whole line | `cin >>` stops at whitespace; `getline(cin >> ws, quote)` reads the full quote after earlier formatted input. |
| [`03_string_concatenation.cpp`](03_string_concatenation.cpp) | Combine text with `+` and `+=` | A space must be added explicitly between names. |
| [`04_string_length_and_indexing.cpp`](04_string_length_and_indexing.cpp) | Find length and valid indexes | `length()` and `size()` agree; check `empty()` before accessing first or last character. |
| [`05_string_traversal.cpp`](05_string_traversal.cpp) | Visit characters by index or range-based loop | Changing a copied `char` leaves the string alone; changing a `char&` updates it. |
| [`06_string_comparison.cpp`](06_string_comparison.cpp) | Equality and ordering | `apple` comes before `banana`; `Hello` and `hello` are different. |
| [`07_case_insensitive_comparison.cpp`](07_case_insensitive_comparison.cpp) | Compare characters after lowercasing | The helper treats `Hello` and `HELLO` as equal while ordinary `==` does not. |
| [`08_substring_and_find.cpp`](08_substring_and_find.cpp) | Extract and search text | `substr(4, 5)` gives `quick`; `find()` returns a starting index or `string::npos`. |
| [`09_repeated_find.cpp`](09_repeated_find.cpp) | Find more than one match | Search again from a later position; advancing one character allows overlapping matches. |
| [`10_string_modification.cpp`](10_string_modification.cpp) | Uppercase, replace, and insert | Trace the string after each change; later indexes refer to the current string. |
| [`11_string_to_number.cpp`](11_string_to_number.cpp) | Convert numeric text | `"10" + "20"` gives `1020`; adding the converted integers gives `30`. `stoi("12cats")` consumes only the numeric prefix. |
| [`12_find_first_and_last.cpp`](12_find_first_and_last.cpp) | Find any character from a set | Search for the first and last vowel, checking for `string::npos` before indexing. |
| [`13_string_algorithms.cpp`](13_string_algorithms.cpp) | Iterator range and `std::count()` | `end()` is one position past the last character; `count()` examines the whole range. |
| [`14_text_analyzer.cpp`](14_text_analyzer.cpp) | Combine the lesson ideas | Enter a sentence, count a character, locate vowels, and search for a word. |

## Ideas to Keep Separate

**Index versus length:** A nonempty string of length `n` has valid indexes `0` through `n - 1`. An empty string has no valid character index.

**What a `char` counts:** These examples use basic English text, where one printed letter is usually one `char`. In UTF-8 text, an accented letter or emoji may use several bytes. `std::string::size()` counts stored `char` elements, not necessarily the number of visible symbols.

**Unchecked versus checked access:** `text[index]` requires a valid index. An invalid `[]` access has undefined behavior: **DO NOT RUN** that experiment. `text.at(index)` checks the index and throws `std::out_of_range` if it is invalid. Both forms need a guard when you expect the string might be empty or short.

**One word versus one line:** `cin >> name` stops at whitespace. `getline(cin, sentence)` reads through the newline. After `cin >>`, a pending newline can make a following `getline()` return immediately; the examples use `cin >> ws` to skip leading whitespace before reading the line. That also removes any leading spaces the user enters.

The analyzer uses `cin.ignore(..., '\n')` after reading one character so a later `getline()` can accept an empty line or preserve leading spaces. Each approach serves a different input goal.

**Search result versus character:** `find()` and the other search functions return a position. If they find no match, they return `string::npos`. Check the result before using it as an index.

**Substring versus whole word:** `find("cat")` also matches the letters inside `"catalog"`. The analyzer demonstrates substring search; it does not check word boundaries.

**First match versus repeated matches:** `find(target)` starts at the beginning. `find(target, start)` starts at `start`. In `09`, starting one character after the previous match finds overlapping occurrences; moving by the target's length skips overlaps. Check for `npos` before advancing.

**Text versus number:** `+` joins strings but adds numbers. `stoi()` and `stod()` convert suitable numeric text; invalid or out-of-range text can throw an exception. A valid numeric prefix can be converted even when nonnumeric text follows, so use the optional consumed-character position when you need the whole string to be numeric.

**Iterator endpoints:** `begin()` identifies the first character of a nonempty string. `end()` marks the position just after the last character and must never be dereferenced. An empty string has `begin() == end()`, so counting the empty range is safe, while asking for its first or last character is not.

**Case handling:** Ordinary string comparison is case-sensitive. The helper in `07` uses `tolower()` safely on character values converted to `unsigned char`. It is a basic character-by-character demonstration, not a full language-aware comparison.

## Checkpoint Challenges

1. Change `14_text_analyzer.cpp` to count spaces with `std::count()`. Predict the count before running.
2. Ask for two search words. Use `find()` to report which appears first, and handle either word being absent.
3. Write a small program that reads a full name, reports its length, and prints its first and last characters only when the name is not empty.
4. For `"aaaa"`, compare the match positions of `"aa"` when you advance by one character and when you advance by the target length.

## Reflection Check

1. Why can `cin >>` and `getline()` produce different results for the same input?
2. Why is the last valid index one less than `length()`?
3. What does `string::npos` mean, and when must you check for it?
4. Why do `"10" + "20"` and `stoi("10") + stoi("20")` differ?
5. Why must `end()` not be dereferenced directly?
6. Why can `stoi("12cats")` return a number even though the whole string is not numeric?
7. How do a copied `char` and a `char&` behave differently in a range-based loop?
