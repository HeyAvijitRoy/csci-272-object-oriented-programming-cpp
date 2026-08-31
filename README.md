# CSCI 272 — Object-Oriented Programming in C++

[![Language: C++](https://img.shields.io/badge/language-C%2B%2B-00599C?style=flat-square&logo=cplusplus&logoColor=white)](https://isocpp.org/)
[![Course: CSCI 272](https://img.shields.io/badge/course-CSCI%20272-243B53?style=flat-square)](https://avijitroy.com/teaching/)

Clear examples, guided experiments, and practice activities for learning object-oriented programming in C++.

**[Start with Lesson 01](Lesson%2001/README.md)** · **[Find the current syllabus](https://avijitroy.com/teaching/)** · **[Open Brightspace](https://brightspace.cuny.edu/)**

> Read the code. Predict what it will do. Run it. Change one thing. Explain the result.

## Course Snapshot

| | |
| --- | --- |
| **Course** | CSCI 272 — Object-Oriented Programming in C++ |
| **Institution** | John Jay College of Criminal Justice, CUNY |
| **Instructor** | Avijit Roy |
| **Department** | Mathematics and Computer Science |
| **Current syllabus** | Select CSCI 272 on the [teaching page](https://avijitroy.com/teaching/) |

This repository helps students move from procedural C++ toward clear, modular object-oriented design. The examples are intentionally focused so that each new idea can be traced, tested, and explained before it is used in a larger program.

> [!IMPORTANT]
> The current syllabus provides the official course outline and schedule. **Brightspace is the authority for weekly materials, announcements, assignments, due dates, submissions, grades, and schedule changes.**

## Start Here

1. Open the [Lesson 01 guide](Lesson%2001/README.md).
2. Choose the next example in the lesson's learning path.
3. Predict its output before compiling it.
4. Run the unchanged program and compare the result with your prediction.
5. Complete at least one `TRY THIS` task.
6. Explain what changed and why.

The goal is not to copy a finished program. The goal is to understand the decisions, trace the data, test an idea, and learn from the result.

## Lesson Catalog

| Lesson | Topics | Materials |
| --- | --- | --- |
| [Lesson 01](Lesson%2001/README.md) | Functions, arrays, and pointers | 17 runnable examples, guided modifications, expected behavior, checkpoint challenges, and reflection questions |

Each lesson directory has its own `README.md`. Read that guide before opening individual source files; it explains the sequence, prerequisites, expected results, and practice tasks.

## How the Materials Are Designed

Every lesson is built around active practice:

- **Focused examples:** each program introduces one main idea.
- **Prediction first:** decide what should happen before asking the compiler.
- **Safe experimentation:** make small changes and distinguish compiler errors from runtime behavior.
- **Visible expectations:** compare your observation with a stated result or relationship.
- **Explanation:** describe what the program did and why it did it.
- **Cumulative practice:** combine ideas only after the individual pieces are clear.

Examples may prioritize instructional clarity and step-by-step reasoning over production-level complexity. Later lessons will revisit earlier techniques in more modular designs.

## Course Topic Map

The repository will support practice with:

- functions, arrays, pointers, vectors, and strings;
- classes, objects, constructors, and destructors;
- encapsulation, composition, and separate interfaces and implementations;
- streams, stringstreams, text files, and CSV files;
- operator overloading and dynamic memory;
- inheritance, polymorphism, and class templates;
- searching, sorting, and exception handling; and
- rigorous programming and software-development practices.

## Repository Layout

```text
.
├── README.md
├── .gitignore
└── Lesson 01/
    ├── README.md
    ├── 01-functions-basics.cpp
    ├── 02-function-prototypes.cpp
    ├── ...
    └── 17-function-pointers-optional.cpp
```

Lesson folders may contain:

- a lesson guide;
- focused `.cpp` examples;
- `.h` files when interfaces and implementations are separated;
- tracing, debugging, and modification tasks; and
- practice prompts or sample input data.

## Compile and Run

**Embarcadero Dev-C++** is the primary IDE used in class. **OnlineGDB** is the recommended browser-based alternative. Visual Studio Code or another environment may also be used if a working C++ compiler and debugger are configured.

Each example is a separate program with its own `main()` function. Compile one example at a time unless a lesson explicitly introduces a multi-file program.

## Git and GitHub Practice

Use version control to record meaningful stages of your work:

- commit source code and documentation, not compiled binaries or IDE build folders;
- make small commits with descriptive messages;
- review `git status` before committing; and
- keep `.h` and `.cpp` files organized when interfaces and implementations are separated.

Do not publish graded assignment solutions. If an assignment uses GitHub, follow the repository-privacy and submission instructions posted on Brightspace.

## Academic Use

These materials are provided for learning and review in CSCI 272. Unless explicitly permitted, repository examples must not be submitted as completed homework, project, quiz, or exam solutions.

Students are responsible for understanding and explaining all code they submit.

## Useful Links

- [Teaching page and current syllabi](https://avijitroy.com/teaching/)
- [Brightspace](https://brightspace.cuny.edu/)
- [Embarcadero Dev-C++](https://www.embarcadero.com/free-tools/dev-cpp)
- [OnlineGDB](https://www.onlinegdb.com/)
- [cppreference.com](https://en.cppreference.com/w/)

## About This Repository

This repository is independently maintained by Avijit Roy as a supplemental teaching resource. It may be updated throughout each term and is not an official publication of John Jay College or CUNY.

© Avijit Roy
