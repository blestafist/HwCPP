# Code Style Guide — pestit (C++ / SchoolHomeworkCPP)

This guide consolidates conventions observed in approximately 300 `.cpp`, `.h`, and `.c`
files and in repository history from February through October 2026. It defines one default
style for new code. Historical styles and task-specific exceptions are documented for context;
they are not competing choices for new code.

**Use the conventions in the newest files as the project baseline**, especially
`PestitFiles/2026/27 tasks/**` from September–October 2026. Older areas such as `CPPIntro`,
`LeetCode`, and early `SideTasks` use obsolete conventions. See
[Style history](#18-style-history-and-obsolete-conventions) for details.

When editing existing legacy files, preserve their naming and structure unless the task calls
for a refactor. New code and substantial refactors follow the rules below. Explicit assignment
requirements take precedence over this guide.

## Contents

1. [General rules and file formatting](#1-general-rules-and-file-formatting)
2. [Indentation and braces](#2-indentation-and-braces)
3. [Whitespace](#3-whitespace)
4. [Single-line blocks and branching](#4-single-line-blocks-and-branching)
5. [Include order](#5-include-order)
6. [Configuration and constants](#6-configuration-and-constants)
7. [Naming](#7-naming)
8. [Types, loops, and initialization](#8-types-loops-and-initialization)
9. [Functions, templates, and lambdas](#9-functions-templates-and-lambdas)
10. [Input, output, and files](#10-input-output-and-files)
11. [The `main` function](#11-the-main-function)
12. [Blank lines](#12-blank-lines)
13. [Comments](#13-comments)
14. [Algorithm-writing conventions](#14-algorithm-writing-conventions)
15. [STL and manual implementations](#15-stl-and-manual-implementations)
16. [File and directory organization](#16-file-and-directory-organization)
17. [Git and commit messages](#17-git-and-commit-messages)
18. [Style history and obsolete conventions](#18-style-history-and-obsolete-conventions)
19. [Known pitfalls](#19-known-pitfalls)
20. [Canonical examples](#20-canonical-examples)

---

## 1. General rules and file formatting

| Property | Convention |
|---|---|
| Language | C++, primarily C++17 (`std::gcd`, structured bindings, fold expressions, `std::optional`). Pure C is used only in `CRoadMap`. |
| Compilation | Standalone files are commonly compiled with `g++ File.cpp -o out`; there is no CMake convention. `.gitignore` excludes `*.bin`, `*.o`, `build/`, `.vscode/`, and `private/`. |
| Encoding | UTF-8. Polish characters and the arrow `→` are permitted in strings. |
| Line endings | LF. CRLF is not used in the repository. |
| Final newline | Every source file ends with a newline. |
| Trailing whitespace | Do not leave trailing spaces. Occasional existing instances are accidental. |
| Line length | There is no hard limit. Aim for about 100 characters or fewer; longer lines are acceptable when they remain readable. Existing examples include the `Print` lambda (about 150 characters) and compact `std::cerr` error handling. |
| Classes and structs | Do not introduce classes or structs in this project style. Use free functions, templates, lambdas, and `enum class`. |
| Namespaces | Do not declare namespaces. Qualify standard-library names with `std::`. |
| `using namespace std;` | Do not use it in new code. It remains only in older school work such as `CPPIntro` and `LeetCode`. |
| `<bits/stdc++.h>` | Do not use it. It appeared briefly in older code. |
| Program per file | A standalone task file is self-contained and has its own `main`. Files under `Wrappers/Alghoritms/*` intentionally omit `main` because they are reusable algorithm templates. |

---

## 2. Indentation and braces

### Indentation

- Indent each level with **four spaces**. This is the dominant repository convention (274 of
  297 files in the original analysis).
- Do not use tabs in new code. Tabs occur in older school work (`CPPIntro`,
  `Matura2026/Task2,3`, and a few `SideTasks`), often because it was written on a school PC.
- Indent `switch` bodies, lambdas, and continued lines by four additional spaces per level.

### Braces: K&R

Put the opening brace on the same line as the declaration or control statement:

```cpp
int main () {
    for (size_t i = 0; i < n; ++i) {
        if (cond) {
            ...
        }
    }
}
```

- Always use K&R braces; do not put the opening brace on its own line. Allman braces occur
  only in the earliest files from February–March 2026.
- Always use braces for `if`, `for`, and `while`, including single-statement bodies:

  ```cpp
  if (!arr[i]) { continue; }  // correct
  if (arr.size() < 2) return; // incorrect: braces are missing
  ```

- Put exactly one blank line between function definitions.

### `else` and `else if`

Attach each `else` or `else if` to the preceding closing brace on the same line. Apply this
consistently to both single-line and multi-line branches:

```cpp
if (arr[mid] == target) {
    return mid;
} else if (arr[mid] > target) {
    left = mid - 1;
    continue;
} else {
    right = mid + 1;
    continue;
}
```

```cpp
if (i + 1 < roman.size() && values.at(roman[i + 1]) > current) {
    result -= current;
} else {
    result += current;
}
```

Do not put `else` on a detached line with a blank line between it and the preceding `}` (the
old `}\n\nelse {` pattern found in `Tasks.cpp::Silnia` and `LeetCode`).

---

## 3. Whitespace

| Context | Convention | Example |
|---|---|---|
| Control keywords | Space before `(` | `if (`, `for (`, `while (`, `switch (` |
| Function definitions | Space between the function name and `(` | `int main () {`, `void BubbleSort (int (&arr)[5]) {` |
| Function calls | No space between the function name and `(` | `Factorial(num - 1)`, `std::swap(a, b)`, `IsPrime(i)` |
| Object direct-initialization | Space before the constructor `(` | `std::ifstream inputFile (INPUT_FILE);`, `std::vector<size_t> cnt (50001, 0);` |
| Binary operators | Spaces on both sides | `a + b`, `i * i <= num`, `x = y` |
| Unary `++`, `--`, `!`, `*`, `&` | No space between the operator and operand | `++i`, `!arr[i]`, `*ptr` |
| Commas | One space after the comma | `f(a, b, c)` |
| `&` and `*` in types | Attach to the type | `std::string& str`, `const auto& i`, `int* ptr`, `auto&&... args` |
| Array references | Use `T (&arr)[len]` | `int (&arr)[20]`, `const T (&arr)[len]` |
| Non-empty brace initialization | Put spaces inside the braces | `{ 'I', 1 }`, `int arr[5] = { 12, 5, 17, 21, 9 }` |
| Empty initialization | Use `{}` or `= {}` | `int arr[20] = {};`, `bool helper[X][Y] {};` |
| Single-line blocks | Put a space just inside each brace | `{ return false; }` |
| Ternary operator | Spaces around `?` and `:` | `a < b ? b : a` |
| Templates | No space after `template` | `template<typename T, size_t len>` |

The space before `(` in a **definition** and its absence in a **call** are intentional. This
distinction became consistent in September 2026. Do not copy occasional older calls such as
`SelectionSort (arr)` or `std::gcd (i, nwdAll)`.

For long expressions:

- Continue stream-insertion chains on the next line, indented four spaces, with `<<` at the
  beginning of the continuation line:

  ```cpp
  std::cout << " | sum: "
      << sumRows[x];
  ```

- Keep the ternary operators at the end of their respective lines when a ternary expression is
  split across lines:

  ```cpp
  const bool shouldSwap = order == SortOrder::Descending ?
      arr[fastPtr] > arr[bestIndex] :
      arr[fastPtr] < arr[bestIndex];
  ```

- When a declaration of several variables must wrap, break after a comma and indent the
  continuation by four spaces. Do not vertically align names:

  ```cpp
  int evenCharsCounter = 0,
      sameCharsQuantityCounter = 0,
      wordsOnlyFromZeroes = 0;
  ```

---

## 4. Single-line blocks and branching

Short bodies use one-line blocks with braces. This is a characteristic convention of the
current project style:

```cpp
if (!inputFile) { std::cerr << "Error while opening input file!"; return 1; }
if (arr[i] == target) { return i; }
if (!swapped) { break; }
if (num % div == 0) { ++ctr; num /= div; } else { ++div; }
if (IsPrime(n)) { std::cout << n << ' '; ++ctr; }
```

Several short, closely related statements may share a line:

```cpp
arr[0] = false; arr[1] = false;
if (arr[mid] > target) { left = mid - 1; continue; }
```

Apply these rules:

- Keep a block on one line only when it contains **one to three short statements**, has no
  nested block, and remains easy to scan.
- Expand more complex logic into a multi-line block.
- Prefer guard clauses and early `return`, `continue`, or `break` over deep nesting:
  `if (!x) { continue; }`, `if (arr.size() <= 1) { return; }`.
- Put the recursion base case first:

  ```cpp
  if (curr == size) { return; }
  ```

- When a conditional simply selects between two return values, a ternary return is appropriate:
  `return b == 0 ? a : gcd(b, a % b);`.

---

## 5. Include order

Include only the headers that the file actually uses. Use angle brackets for standard headers,
with no blank lines inside the include block and exactly one blank line after it.

Use this deterministic order in new code:

1. I/O and text headers, in this order when needed: `<iostream>`, `<fstream>`, `<string>`.
2. Other standard utility, algorithm, numeric, and error headers in alphabetical order, such as
   `<algorithm>`, `<climits>`, `<cstddef>`, `<cstdlib>`, `<ctime>`, `<numeric>`, `<optional>`,
   `<stdexcept>`, and `<utility>`.
3. Container headers in alphabetical order: `<unordered_map>`, `<unordered_set>`, `<vector>`.

Examples:

```cpp
#include <iostream>
#include <fstream>
#include <string>
```

```cpp
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <utility>
#include <vector>
```

```cpp
#include <iostream>
#include <fstream>
#include <climits>
#include <numeric>
#include <unordered_map>
#include <vector>
```

The repository historically did not have a single include order: only 16 of 104 files with at
least three headers were alphabetized, and ordering varied between examples. The sequence above
is the unified rule for new code.

Additional rules:

- Use angle brackets for standard headers. A quoted standard header such as `"cstddef"` in
  `Tasks.cpp` is an old mistake.
- Use C++ header names: `<cstddef>`, `<cstdlib>`, `<ctime>`, `<climits>`, and `<cstdint>`;
  older school files may still use `<time.h>`, `<limits.h>`, or `<stdint.h>`.
- Prefer `<cstddef>` when `size_t` is needed. Existing wrapper comments sometimes say
  `// for size_t` beside `<cstdlib>`; treat that as a legacy annotation, not the include rule.
- Wrapper files under `Wrappers/Alghoritms/*` may explain a less obvious include at the end of
  the line. Keep such comments aligned when adjacent lines need alignment:

  ```cpp
  #include <optional> // for optional values return
  #include <cstdlib>  // legacy comment: for size_t
  ```

  Do not add explanatory include comments to ordinary task files.

---

## 6. Configuration and constants

Put file names and task parameters in a constants block immediately after the include block.
Use one rule for the block format:

- Use the `CONFIGURATION` banner for exam/Matura solutions or whenever there are at least two
  configurable task parameters in addition to the ordinary input/output file names.
- For a small standalone example with fewer than two configurable task parameters and no
  exam-template requirement, put the constants directly after the includes without a banner. A
  pair of input and output file names alone does not require a banner.
- Keep all file names, size limits, and task boundaries in this block. For a list of files, use
  an array such as `INPUT_FILE_NAMES`.

Small configuration block:

```cpp
const std::string INPUT_FILE = "input.txt";
const std::string OUTPUT_FILE = "zadanie2.txt";
```

Banner block:

```cpp
// =========================== CONFIGURATION ===========================

const std::string INPUT_FILE_NAME = "korpo_przyklad.txt";
const std::string OUTPUT_FILE_NAME = "wyniki4.txt";
const int MIN = 100;
const int MAX = 1000;

// =====================================================================
```

Banner requirements:

- Write `CONFIGURATION` in uppercase and surround it with `=` characters.
- Make the closing line exactly as long as the opening line.
- Leave one blank line after the opening banner and before the closing line.
- The banner is used in Matura tasks and in files with at least two configurable task parameters;
  repository examples include `Fibonacci.cpp`, `SemiprimeNum.cpp`, and
  `munchausenNumbers.cpp`.
- For several input files, use a name such as
  `const std::string INPUT_FILE_NAMES[3] = { ... };`.

Constant naming and storage:

- Use `UPPER_SNAKE_CASE`: `INPUT_FILE`, `OUTPUT_FILE_NAME`, `DIMENSIONS_X`, `POWERS_TABLE`.
- File-scope `const std::string`, `constexpr`, and `static constexpr` values are acceptable.
- Keep the standard-library-style lowercase spelling for the sentinel `npos`:
  `static constexpr size_t npos = -1;`.
- A one-off algorithm may use a direct numeric bound such as `1000001` rather than introducing
  a constant solely to name it.

---

## 7. Naming

### Naming conventions

| Entity | Convention | Examples |
|---|---|---|
| Main functions | **PascalCase** | `BubbleSort`, `IsPalindrome`, `SumASCIICode`, `LongestPrefixSuffix`, `FindString` |
| Predicates | Start with `Is`, `Has`, `Does`, or `Are` | `IsPrime`, `IsKaprekar`, `Has2PrimeDividers`, `DoesHave6Ones`, `AreZeroesMajority` |
| Counting/summing functions | Start with `Sum`, `Count`, or `Num` | `SumOfNeighbors`, `CountSwaps`, `NumOfPlaces` |
| Algorithm wrappers | Public name is the algorithm; recursive helper ends in `Rec` | `QuickSort` → `QuickSortRec` → `PartitionQuickSort` |
| Standard-style algorithms | Lowercase or snake_case, by analogy with standard-library naming | `gcd`, `lcd`, `gcd_it`, `to_bin`, `przestaw` |
| Lambdas | PascalCase or short lowercase | `Print`, `rev`, `countDigits` |
| Variables | **camelCase** | `inputFile`, `tempWord`, `maxWord`, `minValueIndex`, `bossForNobody` |
| Constants | `UPPER_SNAKE_CASE` | `INPUT_FILE`, `MIN` |
| Template parameters | `T` for a type; `size_t len` for an array size | `template<typename T, size_t len>` |
| Types, including `enum class` | PascalCase; enumerators are PascalCase | `SortOrder { Ascending, Descending }` |

### Common short names

- Indices: `i`, `j` for a nested index, `x` and `y` for matrices or a field, `nx` and `ny` for
  neighboring coordinates.
- Counters: `ctr` is most common in recent code; `counter`, `cnt`, or a descriptive `...Counter`
  are also used. Increment with `++ctr`.
- Results: `result` in functions, `res` for a short local name, `sum` for sums.
- Input temporaries: `tempWord`, `tempNum`, `tempStr`, `tempChar`, `temp`, `word`, `word1`,
  `word2`.
- Arrays: `arr`, `mainArr`, `helperArr`. Maps: `mp`, `domMap`, `frequency`, `words`.
- Numbers and strings: `num`, `str`, `str1`, `str2`; use `c` for a `char` when the meaning is
  clear.
- Moving/search indices: `fastPtr`, `ptr`, `searcher`, `shift` (start offset of a window),
  `fence` (the Quick Sort “fence”), `mid`, `left`, `right`, `first`, `last`, `piv`.
- Best index/value: `minIdx`, `minValueIndex`, `bestIndex`, `maxSum`, `max`, `min`.
- A value saved while shifting: `temp`, `savedValue`, `val`.
- Streams: `inputFile` and `outputFile`; for multiple streams use descriptive names such as
  `inputFileWords` and `inputFileNew`.

### Further naming rules

- Existing misspellings have become part of established file or symbol names:
  `Alghoritms`, `Erastofenes`, `Fibonnaci`, `neightboor`, `Task1-insetion`, and `Harshard`.
  Do not rename them merely to correct spelling when extending their existing file or directory.
  Spell new names correctly.
- Name functions with a verb or predicate: `GenerateAll`, `PrintErastofenes`, `ParseFile`,
  `SimulateNextGen`.
- Distinguish algorithm variants with suffixes (see [Section 16](#16-file-and-directory-organization)):
  `Legacy`, `Vector`, `STL`, `Full`, `Short`, `Optimised`, `Minimal`, `IWS`, and `_it`.
- Give an iterative counterpart of a recursive function the `_it` suffix, as in `gcd_it`.
- Polish names occur in school assignments (`przestaw`, `Silnia`, `wynik`). Write new
  identifiers in English.

---

## 8. Types, loops, and initialization

### Types

- Use `size_t` for indices and sizes, as in the codebase since April 2026. Older code often uses
  `int` for these values.
- Use `unsigned int` for non-negative sums and character-code totals where appropriate. Convert
  explicitly with `static_cast<unsigned int>(c)`. Do not use C-style casts such as `(int)x`.
- Use `unsigned long long` for large non-negative values such as powers and factorials; `long`
  or `unsigned long` has also been used for products of character codes (Task5).
- Initialize minimum values with `UINT_MAX` from `<climits>` or
  `std::numeric_limits<...>::max()`. A maximum may start at `0`, or at `-1` when that value
  represents “not found yet.”
- Use `bool` for sieve entries and flags such as `swapped` and `match`.
- Use `auto` in range-based loops and for complex types such as `std::chrono` values and lambdas.
  Spell simple types such as `int` and `size_t` explicitly.

### Loops

```cpp
for (size_t i = 0; i < arr.size(); ++i) { ... }       // index-based loop
for (char c : str) { ... }                            // each character
for (auto i : arr) { ... }                            // each value
for (const auto& i : arr) { ... }                     // each value by const reference
for (auto& [key, value] : map) { ... }                // structured binding
while (inputFile >> tempWord) { ... }                 // stream input
```

- Use prefix increment/decrement: `++i`, `--i`. Postfix `i++` remains in old code and is
  acceptable for map counters such as `arrays[key]++` when the expression value is unused; use
  prefix form for ordinary loop and counter increments.
- For unsigned values, prefer loop conditions that cannot underflow. Use `shift + 1 < len`
  instead of `shift < len - 1` when `len` may be zero.
- Use `i * i <= num` for square-root-bounded loops when this is safe for the input range; this
  avoids `<cmath>` for simple prime checks.
- Use steps such as `i += 2` for odd values and `i += 6` for a `6k ± 1` search.
- Declare the loop variable in the `for` statement.

### Initialization and declarations

```cpp
int arr[20] = {};                    // zero-initialized
bool helper[X][Y] {};                // zero-initialized
int sumRows[ROWS] = {};
std::vector<size_t> cnt (50001, 0);  // vector(size, value)
std::vector<unsigned int> arr = {};
int ctr = 0, div = 2;                // related values may share a declaration
unsigned int max = 0, min = UINT_MAX;
```

- Declare a variable close to its first use. A compact declaration block near the start of
  `main` is also normal for streams, counters, and input temporaries.
- Related variables of the same type may be declared on one line, separated by commas.

---

## 9. Functions, templates, and lambdas

### Function signatures

```cpp
bool IsPalindrome (const std::string& str) { // read-only string: const reference
    ...
}

void BubbleSort (std::vector<int>& arr) { // modified container: non-const reference
    ...
}

unsigned int SumASCIICode (const std::string& str) {
    ...
}

long fibonnaci (int n, long firstNum = 0, long secondNum = 1) { // accumulator parameters
    ...
}
```

- Put a space between a function name and `(` in a **definition**; function calls have no such
  space.
- Pass strings, vectors, and other large objects by reference; use a `const` reference when the
  function only reads the object. Pass simple types by value.
- Return results by value rather than through output parameters. The school exercise
  `Silnia(int num, int& wynik)` is a legacy exception.
- Represent “not found” with `npos` (`static constexpr size_t npos = -1;`) in small manual
  exercises. Use `std::optional<size_t>` / `std::nullopt` in reusable functions under
  `Wrappers/Alghoritms`.
- In functions, report invalid input with exceptions such as
  `throw std::invalid_argument("...: " + roman)` or `std::runtime_error`. In `main`, report an
  error with `std::cerr` and return `1`.

### Legacy C-style arrays: reference plus template

```cpp
template<typename T, size_t len>
void InsertionSort (T (&arr)[len]) { ... }

template<size_t len>
void ErastInit (bool (&arr)[len]) { ... }

void BubbleSort (int (&arr)[5]) { ... }
```

- Put a template declaration on its own line immediately above the function.
- Name the array-size template parameter `size_t len`.
- Pass a C-style array by reference so that its size remains available.
- For vector versions, use `std::vector<T>& arr` and get the size from `arr.size()`.

### Lambdas

The `Print` lambda uses a fold expression to write the same values to the console and an output
file. It appears in approximately 56 repository files:

```cpp
auto Print = [&] (auto&&... args) { (std::cout << ... << args) << "\n"; (outputFile << ... << args) << "\n"; };
Print("Ilość liczb: ", ctr);
Print(i, ": ", fibonacciNum, ": ", tempStr);
```

- Keep this small `Print` lambda on one line, capture by reference with `[&]`, and put a space
  between `]` and `(`. The long line is an accepted project-specific exception to the usual
  line-length preference.
- Call `Print();` to output an empty line.
- Define it in `main` after opening `outputFile`.
- Use lambdas for short helpers local to `main`, for example:
  `auto rev = [] (std::string s) -> std::string { ... };`.

### Function size and reuse

- One function should express one idea. `main` should primarily coordinate input/output and
  function calls.
- Put a single reusable check in its own helper function, for example `SumASCIICode`,
  `IsPalindrome`, or `IsInputValid`.
- If a helper must be repeated across separate task files, copy it consistently. For example,
  `ErastInit` and `ErastGen` were copied into Task2 and Task3; there is no shared-header
  convention in this repository.

---

## 10. Input, output, and files

### Opening files

```cpp
std::ifstream inputFile (INPUT_FILE);
if (!inputFile) { std::cerr << "Error while opening input file!"; return 1; }
```

- Check that the input file opened successfully. The error text
  `"Error while opening input file!"` is the established wording.
- Return `1` on failure. Older files used `-1`; do not copy that convention into new code.
- Open the output file after a blank line:
  `std::ofstream outputFile (OUTPUT_FILE);`.
- Check the output stream in Matura solutions and whenever the task requires robust file
  handling. The established wording is `"Error while opening output file!"`; some newer small
  exercises omit this check, but new code should include it when output-file creation is
  necessary for correct task behavior.
- Do not close streams manually; RAII closes them. Call `close()` only when early closure is
  necessary, as in `Wrapper-Matura.cpp` and the documented `inputFileNew.close()` case.

### Reading

```cpp
while (inputFile >> tempWord) { ... }        // words
while (inputFile >> word1 >> word2) { ... }  // pairs
while (inputFile >> temp) { arr.push_back(temp); } // numbers into a vector
```

- Read with `>>` in the loop condition. Do not use `.eof()` as the loop condition.
- Use `std::getline` to read complete lines.

### Writing

- Do not use `std::endl`; it flushes the stream and is absent from the current style. It appears
  96 times in older files, mostly from April–May, with a later exception in `Tasks.cpp`.
- Use `"\n"` for a string newline in output chains such as the `Print` lambda. Use character
  literals for individual characters, for example `<< ' '` or `<< '\n'`.
- The final answer is usually printed without a trailing newline; use a newline when output is
  intentionally line-oriented.
- Matura output labels may be in Polish, for example `"Ilość liczb: "`, `"Liczba par: "`, and
  `"Największa liczba w pliku: "`. Error messages are in English.
- The Unicode arrow `→` is used as an output separator when useful:
  `Print(maxWord, " → ", maxSum);`.
- When the same output goes to both the console and a file, use the `Print` lambda by default.
  If a task needs explicit stream handling, write the `std::cout` and `outputFile` statements
  consecutively, as in tasks from 16.10.

---

## 11. The `main` function

For file-processing tasks, use this order:

1. Open `inputFile` and check it.
2. Leave a blank line.
3. Open `outputFile` and check it when required by the task.
4. Leave a blank line.
5. Declare working variables: temporaries, counters, extrema, and containers.
6. Leave a blank line.
7. Define the `Print` lambda, if needed.
8. Process input in the main loop.
9. Leave a blank line.
10. Print results.
11. Leave a blank line, then return `0`.

```cpp
int main () {
    std::ifstream inputFile (INPUT_FILE);
    if (!inputFile) { std::cerr << "Error while opening input file!"; return 1; }

    std::ofstream outputFile (OUTPUT_FILE);

    std::string tempWord;
    size_t ctr = 0;

    while (inputFile >> tempWord) {
        if (IsPalindrome(tempWord)) { ++ctr; }
    }

    std::cout << "Ilość: " << ctr;

    return 0;
}
```

- Use the exact no-argument signature `int main () {` in this project style.
- `return 0;` at the end is the default. It is omitted in a few tiny existing examples
  (`BinarySearch`, `gcd + lcd`, `Matura2026/Task2`); new code should keep it.
- Small algorithm examples may provide test data as literals in `main`, such as
  `int arr[5] = { 12, 5, 17, 21, 9 };` or `std::string str2 = "ca"`, or generate it with
  `rand() % 10`.

---

## 12. Blank lines

- Put exactly one blank line between function definitions.
- Usually put a blank line before the final `return` in a function.
- Put a blank line after a declaration block and before the main loop.
- Separate logical blocks with a blank line, for example after a `while`/`for` block and before
  output.
- Put one blank line after the include block and around a configuration banner.
- Do not add blank lines inside small loop or branch bodies. Large bodies may be divided into
  logical blocks.
- Do not separate a guard such as `if (!x) { ... return ...; }` from the declaration or check it
  directly follows when they form one logical unit.

---

## 13. Comments

Keep comments minimal; code should explain itself. Repository history includes commits such as
“Remove comment for code clarity,” “Remove readability comment...,” “Clean code,” and
“No LLM used.”

Comment on:

1. **Why**, not what: explain underflow protection, an optimization, or a sentinel. For example:
   `// shift + 1 < len is equivalent to shift < len - 1 but safer for size_t (unsigned int)`.
2. Function complexity, beside the signature: `// O(n)`, `// O(log n)`.
3. The configuration banner (see [Section 6](#6-configuration-and-constants)).
4. Algorithm stages, with a short line above the relevant block:
   `// find index of the best element (min or max depending on order)`,
   `// swap if necessary`, `// comparing to a right neightboor`,
   `// now displaying answers`.
5. Important notices marked `// !`, for example
   `// ! QuickSort for Legacy Arrays (C)`.
6. Less obvious include purposes in reusable files under `Wrappers/Alghoritms/*`, when useful.
7. Detailed educational or reference implementations may have line-by-line explanations. For
   example, `Wrappers/Alghoritms/Sorting/InsertionSort/InsertionSortLegacy.cpp` has detailed
   Russian comments, while its `Vector` counterpart has none. Preserve that established
   distinction when editing those reference files; it is not the default for new code.

Comment formatting:

- Use `//`; block comments `/* ... */` are not part of the project style.
- Put one space after `//`.
- Use lowercase text without a period at the end. Write new comments in English; preserve
  Russian comments when editing educational legacy material that intentionally uses them.
- Separate an end-of-line comment from code by exactly one space.
- Temporary commented-out debug code may be useful while working, but remove it before finishing
  (for example, `// std::cout << "R: " ...` in `Matura2025.cpp`).

Do not comment obvious code, ordinary task-file includes, or merely repeat a function's name.

---

## 14. Algorithm-writing conventions

This section records recurring techniques by problem type. Use them where appropriate; task
requirements and correctness take precedence.

### 14.1. General techniques

- A problem may have two implementations: a manual and an STL version, or a legacy-array and a
  vector version. Common suffixes are `Legacy`, `Vector`, `STL`, `Short`, `Full`, and
  `Optimised`.
- Start with a simple solution and then optimize it when the comparison is useful (brute force
  to `O(n)`, or `IsPrimeV1` vs. `IsPrimeV2` measured with `std::chrono`).
- Prefer early `return`, `continue`, or `break` over unnecessary nesting.
- Use a `bool match` or `swapped` flag with `break` when it makes a scan clearer.
- Guard unsigned loops against underflow. Check `size() < 2` or `size() <= 1` before using
  `size() - 1`.
- Compute a midpoint as `left + ((right - left) / 2)` rather than `(left + right) / 2` to avoid
  overflow.
- Accumulate sums or products in a sufficiently wide type such as `unsigned long long`. Use an
  early exit when a bound proves the result invalid, for example
  `if (sum > original) { return false; }`.
- Keep a copy of a number when digit processing modifies it; common names are `cp`, `copy`, and
  `original`.
- Count frequencies with `std::unordered_map<K, int>` and `map[key]++`, an array such as
  `int cnt[10] {}`, or a vector such as `std::vector<size_t> cnt (N, 0)`.
- For maximum searches, pair a `max`/`maxSum` variable with a value such as `maxWord`. Initialize
  to `0` or `-1` when it represents “not seen yet”; initialize a minimum to `UINT_MAX`. Update
  together when needed: `if (curr > max) { max = curr; maxWord = ...; }`.

### 14.2. Digit processing

```cpp
while (num > 0) {
    int digit = num % 10;
    num /= 10;
}
```

- Convert a digit character to a number with `c - '0'`, and a digit value to a character with
  `'0' + d`.
- Put digit counting in a helper such as `NumOfPlaces`, or use a local `countDigits` lambda.
- Implement powers with a multiplication loop in `IntPower` or `Power`; for repeated powers, a
  `constexpr` table such as `POWERS_TABLE` in `munchausenNumbers.cpp` is appropriate.
- Count digit frequencies with `int digitsCount[10] {};` and expressions such as
  `digitsCount[cp % 10]++`.
- When comparing digits in reverse order, move the position with `--pos`.

### 14.3. Prime numbers

The basic test checks divisors from 2 through the square root:
`if (num < 2) { return false; }` followed by `for (i = 2; i * i <= num; ++i)`.

For a standalone optimized check, prefer the `6k ± 1` method:

```cpp
bool IsPrime (long num) {
    if (num == 2 || num == 3) { return true; }
    if (num % 2 == 0 || num % 3 == 0 || num < 2) { return false; }

    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) { return false; }
    }

    return true;
}
```

### 14.4. Sieve of Eratosthenes

- A stack array such as `bool arr[1000001];` has been used for task-sized bounds; keep the bound
  in `main` or in configuration.
- Split the work into two or three functions for initialization, sieving, and printing.
  `GenerateAll`/`ErastInit` initializes the entries (`arr[0] = false; arr[1] = false;` and
  remaining values `true`). `Erastofenes`/`ErastGen` uses an outer loop bounded by `i * i < len`,
  skips non-primes with `if (!arr[i]) { continue; }`, and marks multiples from `i * i` in steps
  of `i`. `PrintErastofenes` prints indices whose entries are true.
- Before indexing the sieve with input, check its range, for example
  `num >= 0 && num <= 1000000 && arr[num]`.
- Ensure the array length is at least 2 before writing `arr[0]` and `arr[1]`.

### 14.5. GCD and LCM

The project has recursive and iterative Euclidean implementations; suffix the iterative one
with `_it`. Calls use the no-space function-call convention:

```cpp
int gcd (int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int gcd_it (int a, int b) { while (b > 0) { int tmp = b; b = a % b; a = tmp; } return a; }
int lcd (int a, int b) { return (a / gcd(a, b)) * b; } // divide first to reduce overflow risk
```

- Use `std::gcd` from `<numeric>` when the assignment permits it.
- To compute the GCD of many values, accumulate it in a loop, for example
  `nwdAll = std::gcd(i, nwdAll)`.

### 14.6. Sorting

General conventions: use `std::swap` to exchange values, treat the left side as the sorted
portion when the algorithm naturally does so, and use `size_t` indices.

- **Selection sort:** use `minIdx`, `minValueIndex`, or `bestIndex`; search for the best index
  in the inner loop; swap only when `bestIndex != i`; use an unsigned-safe outer bound such as
  `shift + 1 < len`. Represent direction with
  `enum class SortOrder { Ascending, Descending };`, not a `bool` parameter.
- **Bubble sort:** use a pass bound such as `j < size - i - 1`, track `swapped`, and stop with
  `if (!swapped) { break; }`. Check `arr.size() < 2` before a loop that subtracts from the size.
- **Insertion sort:** save `arr[i]` in `temp`, `savedValue`, or `val`; initialize `ptr`,
  `searcher`, or `fastPtr` to `i`; while `ptr > 0 && arr[ptr - 1] > val`, shift right and
  decrement `ptr`; then insert the saved value.
- **Quick sort (Lomuto):** use the last element as the pivot and `fence = first - 1`; split the
  implementation into `PartitionQuickSort`, `QuickSortRec`, and a public `QuickSort` wrapper
  that checks `size() <= 1`. The `RandomPivot` variant uses `srand(time(NULL))` and swaps a
  randomly selected element to the end.

### 14.7. Searching

- **Binary search:** use `left`, `right`, and
  `mid = left + ((right - left) / 2)`, with `==`, `<`, and `>` cases. Return an index or a
  not-found value (`npos`/`std::nullopt`). Sort the input with `std::sort` first when the task
  does not already guarantee sorted input.
- **Linear search:** use a `for` loop and return as soon as
  `arr[i] == target`; return `std::nullopt` after the loop when the API uses an optional result.
- **Substring search:** a manual version uses an outer `shift` loop and an inner character loop
  with a `bool match` flag and `break`. The short STL version is
  `str1.find(str2) != std::string::npos`. A manual `substr` implementation should reserve
  capacity with `result.reserve(len)`.

### 14.8. Strings and words

- **Palindrome:** compare mirrored characters in a loop bounded by half the string length:
  `str[i] != str[size - i - 1]` means it is not a palindrome.
- **ASCII total:** use `for (char c : str) sum += static_cast<unsigned int>(c);`.
- **Reversed words:** a `rev` lambda may use `std::reverse`.
- **Prefix/suffix overlap:** loop downward from `min(size1, size2)` to the minimum allowed size
  and compare substrings.
- **Unique characters:** use `std::unordered_set<char>` and `.count()`.
- **Roman numerals or lookup tables:** use a file-scope
  `static const std::unordered_map<char, int>` and access it with `.at()` and `.count()`.

### 14.9. Recursion

- Put the base case first and return immediately.
- Pass accumulators as parameters for tail-style recursion, for example
  `fibonnaci(n - 1, secondNum, firstNum + secondNum)`.
- For indexed traversal, advance the index in the recursive call, for example
  `Recurr(arr, size, curr + 1)`.

### 14.10. Matura task organization

- Put each subtask in a separate file (`Task3_1.cpp`, `Task3_2.cpp`, or `1.cpp`, `2.cpp`, `3.cpp`),
  or use separate functions in one `main.cpp` when that better fits the assignment.
- Keep sample data files beside the solution, named like `..._przyklad.txt` for testing, along
  with the actual input file.
- Existing starter templates are `Wrapper-Matura.cpp` and `Minimal-Wrapper-Matura.cpp`.

---

## 15. STL and manual implementations

- If a lesson requires “no STL,” or the purpose is to learn the algorithm, implement it manually.
  An STL counterpart may be kept beside it for comparison, as with `IsAutobiographicSTL`.
- Common standard-library facilities include `std::swap`, `std::sort`, `std::count`,
  `std::reverse`, `std::min`/`std::max`, `std::gcd`, `std::to_string`, `std::stoi`,
  `std::accumulate`, `std::numeric_limits`, `std::unordered_map`, `std::unordered_set`,
  `std::vector`, and `std::array`.
- Prefer `std::vector` over owning dynamic arrays allocated with `new[]`; dynamic `new` appears
  only in the older school assignment TJ03. Prefer `unordered_*` over ordered `map`/`set` when
  key order is unnecessary. One repository change explicitly rewrote a solution to use
  `std::unordered_set` for speed.
- For simple examples, `rand() % N` with `srand(time(NULL))` is present. For more serious random
  number generation, use `<random>`, `std::random_device`, and `std::mt19937`.
- The comment in `Substr.cpp` captures the preferred approach:
  “Just use `std::string.substr(pos, len)`, in case you can't:”.

---

## 16. File and directory organization

### File names

| File type | Format | Examples |
|---|---|---|
| Algorithm | `PascalCase.cpp` | `BinarySearch.cpp`, `RomanToInt.cpp`, `Erastofenes.cpp` |
| Algorithm name containing spaces or symbols | Existing names may retain them | `gcd + lcd.cpp` |
| Lesson task | `TaskN.cpp` or `Task1-bubble.cpp` (hyphen suffix in lowercase) | |
| Subtask | `TaskN_M.cpp` | `Task3_2.cpp` |
| Matura | `main.cpp` inside `MaturaYYYY/`, `ZadanieA.cpp`, or `TaskA.cpp` | |
| Older school task | Existing names may be `Zadanie P14.cpp` or `ZadanieTJ03.cpp` | legacy |
| Algorithm variants | PascalCase suffix | `InsertionSortLegacy.cpp`, `InsertionSortVector.cpp`, `QuickSortRandomPivot.cpp`, `ZadanieDOptimised.cpp`, `ContainsSubstring.cpp` |

### Directory structure

```text
CPP/
├── CPPIntro (1st class)/   — school course organized by topic (legacy style)
├── Matura/
│   ├── PodstawowaMatura/MaturaYYYY/
│   ├── RozszerzonaMaturaSF/MaturaYYYY/
│   └── RozszerzonaMaturaNF/MaturaYYYY/...
├── PestitFiles/
│   ├── 2026/27 tasks/DD.MM.YYYY/ — lesson-date tasks (current style)
│   ├── CRoadMap/                 — pure C, LessonN.c
│   ├── Fun/, LeetCode/
├── SideTasks/              — number-theory tasks
├── Wrappers/               — reusable templates (Alghoritms/, Matura wrappers)
└── qs files/               — revised solutions
```

- Name a lesson-date directory `16.10.2026`, `21.10.2026`, and so on.
- Keep task input and output files beside the source when appropriate (`input.txt`,
  `liczby_do_zadania.txt`, `wyniki3.txt`).
- Name `.txt` output files according to the assignment (`wyniki4.txt`, `zadanie2.txt`,
  `wynik5.txt`).
- Do not commit binaries such as `*.bin` or `output.bin`. They are listed in `.gitignore`,
  although a few historical binaries slipped into the repository.

---

## 17. Git and commit messages

Write commit messages in English, without a final period. The established pattern is
“verb + (scope) → description”:

```text
add (task) → add tasks from 21.10.2026
add (tasks+gcd+lcd) → implement various lesson tasks and two efficient algorithms
Feat (bubble sort & binary search)
fix (imp. rem): remove unused imports
Done all tasks from 16.10.2026 lesson
Done Task 3.3 from Matura 2026 (latest)
Refactor SelectionSort: replace bool parameter with SortOrder enum
```

- Common verbs in repository history include `add`, `Add`, `Feat`/`feat`, `fix`, `Done`,
  `Refactor`, `Implemented`, `Rewritten`, and `Remove`.
- The arrow `→` is acceptable in a message.
- Use a bulleted list (`- ...`) in the commit body to describe what was used or implemented,
  for example `Used std::abs...` or `Implemented ...`.
- Historical capitalization is inconsistent. For new commits, prefer
  `add (scope) → description` or `Done ...` consistently.
- Keep one commit focused on one lesson, task, or algorithm.
- A manually written solution may include a body note such as “No LLM used” or “Clean code.”

---

## 18. Style history and obsolete conventions

This table records how the repository evolved. It is historical context, not a list of styles to
choose between; new code follows the current conventions described above.

| Period | Observed traits | Status |
|---|---|---|
| Feb–Mar 2026 | `using namespace std;`, Allman braces, `cout`/`endl`, Polish identifiers, `i++`, tabs | Obsolete |
| Apr–May 2026 | `std::` throughout, K&R braces, one-line `{ ... }` blocks, `CONFIGURATION` banner, `int main()` without a space, frequent `std::endl`, `i++`/`int i`, emerging `size_t`, `return -1` | Transitional |
| Jun 2026 | `unordered_set`, `size_t`, `++i` (“project standard”), configuration banner | Close to current |
| Sep–Oct 2026 | `int main ()`, a space in definitions such as `Foo (...)`, `++i`, `size_t`, `"\n"`, `return 1`, `INPUT_FILE` constants, `static constexpr npos`, no `std::endl` | **Current** |

In short: use `std::`, K&R braces, four spaces, `++i`, `size_t`, `"\n"` for string newlines,
`int main ()`, `Foo (...)` in definitions, and short one-line blocks with braces.

---

## 19. Known pitfalls

Examples from the repository that are useful warnings:

- `PestitFiles/2026/27 tasks/BinarySearch.cpp` can underflow with `left = mid - 1` when `left`
  is `size_t`, and its `left < right` condition fails on boundary cases. The canonical
  implementation is `Wrappers/Alghoritms/Search/BinarySearch.cpp`, which uses `right = mid;`,
  `left = mid + 1;`, and documents the underflow concern.
- `Tasks.cpp::Factorial` actually computes the sum `num + Factorial(num - 1)`, not a factorial
  product.
- `Matura2025.cpp::przestawI` is an unfinished iterative implementation with an infinite
  `while` loop.
- `Task3.cpp` (21.10) declares unused `max` and `maxSum`; `Task2.cpp` declares an unused `ctr`.
  Remove unused variables.
- Sieve initialization that writes `arr[0]` and `arr[1]` is invalid when `len < 2`.
- Large stack arrays such as `bool arr[1000001]` work for the observed task, but use
  `std::vector<bool>` when the bound is larger or not known at compile time.
- Established spelling mistakes in existing identifiers and paths are listed in
  [Section 7](#7-naming); preserve them when extending those existing names.

---

## 20. Canonical examples

### File-processing task

```cpp
#include <iostream>
#include <fstream>
#include <string>

const std::string INPUT_FILE = "input.txt";
const std::string OUTPUT_FILE = "output.txt";

bool IsPalindrome (const std::string& str) {
    for (size_t i = 0; i < str.size() / 2; ++i) {
        if (str[i] != str[str.size() - i - 1]) {
            return false;
        }
    }

    return true;
}

int main () {
    std::ifstream inputFile (INPUT_FILE);
    if (!inputFile) { std::cerr << "Error while opening input file!"; return 1; }

    std::ofstream outputFile (OUTPUT_FILE);
    auto Print = [&] (auto&&... args) { (std::cout << ... << args) << "\n"; (outputFile << ... << args) << "\n"; };

    std::string tempWord;
    size_t ctr = 0;

    while (inputFile >> tempWord) {
        if (IsPalindrome(tempWord)) { ++ctr; }
    }

    Print("Ilość: ", ctr);

    return 0;
}
```

### Matura task with a configuration banner

```cpp
#include <iostream>
#include <fstream>
#include <string>

// =========================== CONFIGURATION ===========================

const std::string INPUT_FILE_NAME = "dane.txt";
const std::string OUTPUT_FILE_NAME = "wyniki.txt";

// =====================================================================

int main () {
    std::ifstream inputFile (INPUT_FILE_NAME);
    if (!inputFile) { std::cerr << "Error while opening input file!"; return 1; }

    std::ofstream outputFile (OUTPUT_FILE_NAME);
    if (!outputFile) { std::cerr << "Error while opening output file!"; return 1; }

    std::string tempWord;

    while (inputFile >> tempWord) {

    }

    return 0;
}
```

### Legacy-array algorithm

```cpp
#include <cstddef>
#include <utility>

template<typename T, size_t len>
void SelectionSort (T (&arr)[len]) {
    for (size_t i = 0; i + 1 < len; ++i) {
        size_t minIdx = i;
        for (size_t fastPtr = i + 1; fastPtr < len; ++fastPtr) {
            if (arr[fastPtr] < arr[minIdx]) { minIdx = fastPtr; }
        }

        if (minIdx != i) { std::swap(arr[i], arr[minIdx]); }
    }
}
```

### `std::vector` algorithm

```cpp
#include <utility>
#include <vector>

void BubbleSort (std::vector<int>& arr) {
    if (arr.size() < 2) { return; }

    for (size_t i = 0; i < arr.size() - 1; ++i) {
        bool swapped = false;
        for (size_t j = 0; j < arr.size() - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        if (!swapped) { break; }
    }
}
```

### Pre-commit checklist

- [ ] Four spaces, K&R braces, and braces on every `if`/`for`/`while` body
- [ ] `int main ()` and `Foo (...)` in definitions; no space in function calls
- [ ] `std::` qualification; no `using namespace std` or `<bits/stdc++.h>`
- [ ] Includes follow the unified order and contain no unused headers
- [ ] File names and task parameters are in the configuration block; use the banner by its rule
- [ ] `++i`, `size_t` for indices, and no `std::endl`
- [ ] Input stream checked with `if (!inputFile) { std::cerr << "..."; return 1; }`
- [ ] Short bodies are one-line blocks; complex bodies are expanded
- [ ] No unused variables or includes
- [ ] Blank line before final `return`; exactly one blank line between functions
- [ ] Comments explain why, complexity, or algorithm stages—not obvious code
- [ ] Commit message follows `add (scope) → description` or `Done ...`
