# Expression No. 7 Calculator

A console program in C++ that calculates a piecewise function for every value of `x` in a given range with a given step. The program is menu-driven, checks all user input and prints the results as a table.

## Formula

$$
y =
\begin{cases}
\displaystyle\sum_{i=0}^{n+3} \sum_{j=0}^{n} (i + x - j)^2, & x < -2 \\[2ex]
\displaystyle\prod_{j=1}^{n} (7x - j) - 6x \sum_{j=0}^{n} \frac{j+2}{j^2}, & x \ge -2
\end{cases}
$$

> **Note.** In the second branch the term with `j = 0` has a zero denominator, so it is undefined. The program starts this sum from `j = 1`.

## Input data

| Parameter | Meaning | Type | Constraint | Default |
|---|---|---|---|---|
| `start` | Start of the interval | real number | any number | 8 |
| `end` | End of the interval | real number | greater than `start` | `start + 10` |
| `step` | Step between values of `x` | real number | greater than 0 | 2 |
| `n` | Upper limit in the sums and the product | integer | greater than 1 | 4 |

The program reads a whole line and accepts it only if it contains a single number. Text, empty lines and extra symbols (for example `3abc` or `2.5` for `n`) are rejected. After 5 wrong attempts the default value is used and the program tells the user about it.

## Features

- Menu with four options: enter data, calculate, clear data, exit.
- Input check for every parameter, with clear messages.
- Calculation of `y` for every `x` from `start` to `end` with the given `step`.
- Results in a table with two decimal places.
- Protection against calculation before the data is entered.

## How to use

On start the program shows a welcome screen and the main menu:

| Option | Action |
|---|---|
| `1` | Enter `start`, `end`, `step` and `n`, then see a summary |
| `2` | Calculate and print the table |
| `3` | Clear the entered data |
| `4` | Exit |

### Example

Input: `start = -3`, `end = -1`, `step = 1`, `n = 2`.

```
|=========================================|
| Calculation results                     |
|=========================================|
|        x        |           y           |
|_________________|_______________________|
|           -3.00 |                105.00 |
|           -2.00 |                288.00 |
|           -1.00 |                 96.00 |
|_________________|_______________________|
```

Check for `x = -3` (first branch): the sum over `i = 0..5` and `j = 0..2` gives 50 + 29 + 14 + 5 + 2 + 5 = 105.

## Project structure

```
.
├── src/        C++ source code
├── docs/       Use Case diagram, Activity diagram, IDEF0 diagrams
├── .gitignore
└── README.md
```

## Build and run

Any C++ compiler with C++11 support works. Example with g++:

```
g++ -o calculator src/main.cpp
./calculator
```

On Windows the file is `calculator.exe`. The project can also be opened and built in Visual Studio.

## Documentation

Diagrams and the interface wireframe are in the `docs/` folder.

## Current limitations and plans

- All the code is in `main`. Splitting it into functions and adding exception handling is planned.
- `x` grows by adding `step` each time, so with a very small step (for example 0.1) the last value of `x` may be skipped because of rounding errors.
- Unit tests are planned.
