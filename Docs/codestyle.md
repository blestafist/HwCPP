# Naming Conventions

- **Functions:** Use `PascalCase` and a clear verb or predicate: `BubbleSort`, `GenerateAll`,
  `IsPrime`, `Has2PrimeDividers`. Predicates start with `Is`, `Has`, `Does`, or `Are`;
  counting/summing functions start with `Count`, `Num`, or `Sum`.
- **Algorithm names:** Keep the public function named after the algorithm. Put recursive
  implementation details in a helper ending in `Rec` (for example, `QuickSortRec`). 
  For iterative implementations, use a helper ending in `Iter` (for example, `QuickSortIter`).
- **Variables and parameters:** Use `camelCase` (`inputFile`, `tempWord`, `minValueIndex`).
  Short names are appropriate when the context is clear: `i`/`j` for indices, `arr` for arrays,
  `num` for numbers, `str` for strings, `ctr` for a counter, and `result` for a computed result.
  Prefer descriptive names when a value's role is not obvious.
- **Constants:** Use `UPPER_SNAKE_CASE` (`INPUT_FILE`, `MAX_SIZE`).
- **Types and enum values:** Use `PascalCase` (`SortOrder`, `Ascending`). Template type
  parameters use `T`; array-size parameters use `size_t len`.
- **Algorithm variants:** Use descriptive suffixes such as `Legacy`, `Vector`, `STL`, `Full`,
  `Short`, `Optimised`, or `Minimal` (`InsertionSortVector`).
- **Lambdas:** Use `PascalCase` or a short descriptive lowercase name (`Print`).
- **Files:** Algorithm files use `PascalCase.cpp`; task files use `TaskN.cpp` or `TaskN_M.cpp`.
  Variant suffixes follow the same style (`insertionsortvector.cpp`)
- Write new identifiers in English and spell them correctly. Use a verb or predicate for function
  names. Preserve established names—including legacy misspellings—when extending existing files
  or paths; do not rename them just to fix spelling. Keep existing naming when editing legacy code
  unless the task calls for a refactor.
