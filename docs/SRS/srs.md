# Software Requirements Specification

**Product:** Function calculator 

**Author:** Zhotetskyi V. V., group KN-226e, NTU “KhPI”

**User story:** US-5 (#23), Sprint 4

**Version:** 1, November 2026



## 1. Purpose

This document defines the expected functionality of the Function Table Calculator. The customer relies on it for acceptance, while the developer uses it for building and testing the software. Every requirement is assigned an identifier and a verification method.

The product requirements mirror the user stories in the GitHub Product Backlog. Since each functional requirement below corresponds to a specific user story, both this document and the Scrum board share identical numbering.

### 1.1 Definitions

| Term | Meaning |
| --- | --- |
| x | the argument of the function |
| y | the value of the function of variant 7 for one x |
| x_start, x_end, step | the first value of x, the last value of x and the step between two values of x |
| n | the upper limit of the counters in the formula, a whole number |
| Result table | the list of pairs x and y for every x from start to end |
| User story | a requirement written as “As a …, I want …, so that …” |
| Story points (SP) | the relative size of a user story: 1, 2, 3, 5, etc |
| Priority | Low, Medium or High |


### 1.2 System overview

The Function Calculator is a console program in C++. It calculates the function for every x from the start value to the end value with the given step:

```
y = Σ (i = 0..n+3) Σ (j = 0..n) (i + x - j)²,                      if x < -2
y = Π (j = 1..n) (7x - j) - 6x * Σ (j = 0..n) ((j + 2) / j²),      if x ≥ -2
```

The formula is given with j = 0 in the second sum. The term with j = 0 has a zero denominator, so the program starts this sum from j = 1. This is a deviation from the formula, and it is the only one.

### 1.3 References

1. IEEE Std 830-1998. Recommended Practice for Software Requirements Specifications.
2. Melnyk K. Methodical recommendation to Software Engineering laboratory practice. NTU “KhPI”, 2026.
3. Zhotetskyi V. V reports of laboratory works 1–3, folder `docs/modeling`,  `docs\coding`, `docs\planing`.
4. Repository of the project on GitHub: https://github.com/VladislavZhovtetskiy/SETestRepository
5. Scrum board of the project on Github: https://github.com/users/VladislavZhovtetskiy/projects/15

## 2. Overall description

### 2.1 Product perspective

This software operates as an independent, self-contained application. It functions on its own and is not integrated into any larger system.

| Interface | Description |
| --- | --- |
| System interfaces | None: the application operates independently as a standalone tool |
| User interfaces | An English-language console text menu where the user selects an action by entering its corresponding number and pressing Enter |
| Hardware interfaces | Standard keyboard input and monitor output handled via the terminal, with no direct hardware access. |
| Software interfaces | The C++ standard library |
| Communication interfaces | None: the program operates completely offline without network connectivity |
| Memory constraints | Minimal memory footprint: the application processes only the active data and outputs the table line by line |

### 2.2 Design constraints

**Operations.** The user starts the program, works in the main menu and leaves it with "Exit".

**Site adaptation requirements.** No installation or manual setup is needed to run the software.


### 2.3 Product functions

- Read and validate each input value entered from the keyboard.
- Calculate y for every x and show the result in console.
- Show the main menu.
- Leave the program with the "Exit" option.

### 2.4 User characteristics

The application is intended for students, teachers, and external users. Students and teachers understand the formula, neither math nor programming skills are necessary because the software performs all calculation on its own. Basic console is sufficient, and the program provides clear explanations for all values and errors.

### 2.5 Constraints, assumptions and dependencies

- n is a whole number greater than 1.
- Numbers are typed with a dot: 6.7, not 6,7.
- A C++14 or newer compiler is needed to build the program.
- The results are double precision numbers, shown with two decimal places.

## 3. Specific requirements

### 3.1 External interface requirements

| ID | Interface | Requirement |
| --- | --- | --- |
| EI-1 | Console | The program reads from the standard input and output |
| EI-2 | Hardware Interface | Standard keyboard for line-by-line input and monitor for console text output; no direct hardware access is required. |
| EI-3 | Software Interface | Relies solely on the C++14 or higher Standard Library without third-party dependencies, external databases.|
| EI-4 | Communication Interface | The application is completely self-contained and operates offline without network access. |

### 3.2 Functional requirements

Each functional requirement maps directly to a user story from the GitHub Scrum board: US-2 and US-3.

#### US-2: Design the calculator console interface (#5)

As a user, I want to navigate a clear console menu and receive helpful prompts and messages, so that I can easily control the program and understand every step.

Priority: High. Estimate: 2 SP. Status: Done

| ID | Requirement | Verification |
| --- | --- | --- |
| FR-1.1 | Upon startup, the application displays a welcome screen and presents the main menu with four numbered options: 1 (Enter data), 2 (Calculate), 3 (Clear data), and 4 (Exit). | Manual console check |
| FR-1.2 | If the user enters an invalid menu option: non-numeric text, empty line, or a number outside 1–4, the program displays a clear error message and reprints the menu. | Manual console check |
| FR-1.3 | Selecting option 3 resets all previously entered input parameters: start, end, step, n, and notifies the user that the data has been cleared. | Manual console check |
| FR-1.4 | Selecting option 2 before entering, or after clearing, input data is blocked; the program displays a warning instructing the user to enter data first. | Manual console check |
| FR-1.5 | Selecting option 4 terminates the application cleanly with exit code 0. | Manual console check |


#### US-3: Develop the piecewise expression over an interval (#22)

As a user, I want to input validated interval parameters and compute the piecewise function into a formatted table, so that I can analyze the results accurately without program crashes.

Priority: High. Estimate: 3 SP. Status: Done.

| ID | Requirement | Verification |
| --- | --- | --- |
| FR-2.1 | Selecting option 1 prompts the user sequentially for start, end, step, and n, reading an entire input line for each parameter. | Manual console check |
| FR-2.2 | Each input line must contain exactly one valid number; empty lines, alphabetic text, and trailing symbols (such as 3abc) are rejected with an explanatory message. | Manual console check |
| FR-2.3 | The parameter start accepts any valid real number. | Manual console check |
| FR-2.4 | The parameter end must be a real number strictly greater than start; values less than or equal to start are rejected. | Manual console check |
| FR-2.5 | The parameter step must be a real number strictly greater than 0; zero or negative values are rejected. | Manual console check |
| FR-2.6 | The parameter n must be an integer greater than 1; floating-point numbers (e.g., 2.5) or integers ≤ 1 are rejected. | Manual console check |
| FR-2.7 | If the user fails to enter a valid value within 5 consecutive attempts for any parameter, the program automatically assigns a fallback default and notifies the user. | Manual console check |
| FR-2.8 | Once all four parameters are accepted, the program displays a summary of the active input values before returning to the main menu. | Manual console check |
| FR-2.9 | Selecting option 2 with valid data evaluates y for every x starting from start up to end by adding step on each iteration, using the piecewise formula defined in Section 1.2. | Reference check: for start = -3, end = -1, step = 1, n = 2, outputs y = 105.00, 288.00, and 96.00  |
| FR-2.10 | The results are printed in a bordered ASCII table with two columns, formatting all numerical values to two decimal places. | Manual console check |




### 3.3 Logical database requirements

The program does not use a database or external storage files. While running, it holds only the active session parameters in RAM:

| Field | Type | Meaning |
| --- | --- | --- |
| x_start | double | the start of x |
| x_end | double | the end of x |
| step | double | the step |
| n | int | the upper limit of the formula |

### 3.4 Software system attributes


| ID | Attribute | Requirement | Verification |
| --- | --- | --- | --- |
| QA-1.1 | Reliability | Identical input sequences always produce identical mathematical outputs, and malformed user input never terminates the program unexpectedly. | Boundary and invalid input testing |
| QA-1.2 | Usability | The interface guides the user with clear prompts, rejects invalid entries with explanations, and falls back to safe default values after 5 failed attempts. | Manual console walkthrough |
| QA-1.3 | Availability | The calculator runs locally as a standalone executable with zero dependency on external servers or internet connectivity. | Architectural inspection |
| QA-1.4 | Security | The software collects, transmits, or stores no personal user data; all session data is discarded upon exit or reset. | Source code review |
| QA-1.5 | Portability | Written in standard C++14, allowing compilation and execution across Windows, Linux, and macOS using `g++` or MSVC without code changes. | Cross-compiler build check |
| QA-1.6 | Maintainability | Supported by architectural documentation to facilitate future modularization into functions. | Documentation review |
| QA-1.7 | Testability | Deterministic console output and documented reference values allow straightforward verification and future unit testing. | Reference calculation check |


### 3.5 Environment characteristics

**Hardware.** Any standard desktop or laptop capable of running a C++ console executable.

**Peripherals.** Standard keyboard and display monitor, no other devices are required.

## 4. Traceability

### 4.1 Requirements traceability

Each requirement is linked to the user story it comes from, to the way it is verified, and to the sprint in which it was delivered.

| Requirement | User story | Verification | Sprint | Status |
|---|---|---|---|---|
| FR-1.1–FR-1.5 | US-2 (#5) | Manual console check | 2 | Done |
| FR-2.1–FR-2.8, FR-2.10 | US-3 (#22) | Manual console check | 2 | Done |
| FR-2.9 | US-3 (#22) | Reference check: 105.00, 288.00, 96.00 | 2 | Done |
| QA-1.1 | US-3 (#22) | Boundary and invalid input testing | 2 | Done |
| QA-1.3–QA-1.7 | US-4 (#10) | Architectural inspection, code review | 3 | Done |
| EI-1–EI-4 | US-2 (#5) | Architectural inspection | 2 | Done |
| SRS document | US-5 (#23) | Document review | 4 | In progress |
| Refactoring, exception handling, unit tests | US-6 (#27) | Unit tests (planned) | 5 | Product Backlog |

### 4.2 Backlog overview

Story points are assigned to user stories only. The table shows the planned and completed work per sprint.

| User story | GitHub issue | Tasks | Priority | SP | Sprint | Status |
|---|---|---|---|---|---|---|
| US-1 | #1 (#2, #3, #4) | Workflow and use-case models | Medium | 3 | 1 | Done |
| US-2 | #5 (#6, #8) | Console screens, interface messages |
