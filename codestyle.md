# Code Style Guide — pestit (C++ / SchoolHomeworkCPP)

Полный свод привычек и правил, выведенный из анализа репозитория (≈300 `.cpp/.h/.c`
файлов, история с февраля по октябрь 2026).

**Главный принцип: пиши так, как в самых свежих файлах** (`PestitFiles/2026/27 tasks/**`,
сентябрь–октябрь 2026). Стиль заметно менялся, и старые файлы (`CPPIntro`, `LeetCode`,
ранние `SideTasks`) ему уже не соответствуют. Раздел [Эволюция стиля](#18-эволюция-стиля-что-считать-устаревшим)
показывает, что считать устаревшим.

Оглавление:

1. [Общее и форматирование файла](#1-общее-и-форматирование-файла)
2. [Отступы и скобки](#2-отступы-и-скобки)
3. [Пробелы](#3-пробелы)
4. [Однострочные блоки и ветвления](#4-однострочные-блоки-и-ветвления)
5. [Порядок `#include`](#5-порядок-include)
6. [Конфигурационный блок и константы](#6-конфигурационный-блок-и-константы)
7. [Нейминг](#7-нейминг)
8. [Типы, циклы, инициализация](#8-типы-циклы-инициализация)
9. [Функции и шаблоны](#9-функции-и-шаблоны)
10. [Ввод / вывод и файлы](#10-ввод--вывод-и-файлы)
11. [Структура `main`](#11-структура-main)
12. [Пустые строки](#12-пустые-строки)
13. [Комментарии](#13-комментарии)
14. [Привычки написания алгоритмов](#14-привычки-написания-алгоритмов)
15. [STL vs ручная реализация](#15-stl-vs-ручная-реализация)
16. [Организация файлов и имена](#16-организация-файлов-и-имена)
17. [Git и коммиты](#17-git-и-коммиты)
18. [Эволюция стиля](#18-эволюция-стиля-что-считать-устаревшим)
19. [Известные грабли](#19-известные-грабли)
20. [Эталонные шаблоны](#20-эталонные-шаблоны)

---

## 1. Общее и форматирование файла

| Параметр | Правило |
|---|---|
| Язык | C++ (в основном C++17: `std::gcd`, structured bindings, fold expressions, `std::optional`). Чистый C только в `CRoadMap`. |
| Компиляция | `g++ File.cpp -o out` без CMake; в `.gitignore`: `*.bin`, `*.o`, `build/`, `.vscode/`, `private/` |
| Кодировка | UTF-8 (польские буквы и стрелка `→` в строках допустимы) |
| Переводы строк | LF (CRLF в репозитории нет) |
| Новая строка в конце файла | Да (во всех 19 файлах из `PestitFiles/2026`) |
| Завершающие пробелы | Не оставлять (изредка проскакивают, но это случайность) |
| Лимит длины строки | Жёсткого нет. Обычно ≤ 100 символов, но длинные строки допустимы: `Print`-лямбда на одной строке (≈150), строки с `std::cerr … return 1;` |
| Классы / структуры | **Не используются совсем.** Только свободные функции, шаблоны, лямбды и `enum class` |
| Namespace | Не объявляются. Всегда `std::` вручную |
| `using namespace std;` | **Запрещено** в новом коде (остался только в школьных `CPPIntro` и `LeetCode`) |
| `#include <bits/stdc++.h>` | Не использовать (мелькало только в мае) |
| Один файл — одна программа | Каждый файл самодостаточен, с собственным `main` (кроме `Wrappers/Alghoritms/*`, где `main` убран намеренно, это библиотечные заготовки) |

---

## 2. Отступы и скобки

### Отступы

- **4 пробела на уровень.** Это 274 файла из 297.
- Табы встречаются только в школьных работах (`CPPIntro`, `Matura2026/Task2,3` и пара `SideTasks`), потому что их писали на школьном ПК. В новом коде табов не должно быть.
- Внутри `switch`/лямбд/продолжений строки отступ тоже 4 пробела.

### Скобки: K&R (открывающая на той же строке)

```cpp
int main () {
    for (size_t i = 0; i < n; ++i) {
        if (cond) {
            ...
        }
    }
}
```

- Открывающая `{` **всегда на той же строке**. Allman (`{` на новой строке) встречался только в самых первых файлах (февраль–март) и больше не применяется.
- **Скобки у `if/for/while` ставятся всегда**, даже для одной инструкции:

  ```cpp
  if (!arr[i]) { continue; }       // да
  if (arr.size() < 2) return;      // нет (единичное исключение в Task1-bubble.cpp, не повторять)
  ```

- Между закрывающей `}` функции и следующей функцией ровно **одна пустая строка**.

### `else`

Есть два допустимых варианта.

1. **Цепочка однострочников**: `else` / `else if` каждый с новой строки, вровень с `if`:

   ```cpp
   if (arr[mid] == target) { return mid; }
   else if (arr[mid] > target) { left = mid - 1; continue; }
   else { right = mid + 1; continue; }
   ```

2. **Многострочные блоки**: cuddled (`} else {`) в свежем коде, как в `Matura2025.cpp` и `RomanToInt.cpp`:

   ```cpp
   if (i + 1 < roman.size() && values.at(roman[i + 1]) > current) {
       result -= current;
   } else { result += current; }
   ```

Старый вариант с `else` на отдельной строке после `}` и пустой строкой перед ним (`}\n\nelse {`, как в `Tasks.cpp::Silnia` и `LeetCode`) не повторять.

---

## 3. Пробелы

| Место | Правило | Пример |
|---|---|---|
| Ключевые слова | пробел перед `(` | `if (`, `for (`, `while (`, `switch (` |
| **Определение функции** | **пробел между именем и `(`** (с сентября 2026) | `int main () {`, `void BubbleSort (int (&arr)[5]) {` |
| **Вызов функции** | в основном **без пробела** | `Factorial(num - 1)`, `std::swap(a, b)`, `IsPrime(i)` |
| Объявление объекта с конструктором | пробел перед `(` | `std::ifstream inputFile (INPUT_FILE);`, `std::vector<size_t> cnt (50001, 0);` |
| Бинарные операторы | пробелы вокруг | `a + b`, `i * i <= num`, `x = y` |
| Унарные `++/--`, `!`, `*`, `&` | без пробела | `++i`, `!arr[i]`, `*ptr` |
| Запятая | пробел после | `f(a, b, c)` |
| `&` и `*` в типах | **прилипают к типу** | `std::string& str`, `const auto& i`, `int* ptr`, `auto&&... args` |
| Ссылка на массив | `T (&arr)[len]` | `int (&arr)[20]`, `const T (&arr)[len]` |
| Фигурные скобки инициализации | пробелы внутри в новом коде | `{ 'I', 1 }`, `int arr[5] = { 12, 5, 17, 21, 9 }` |
| Пустая инициализация | `{}` или `= {}` | `int arr[20] = {};`, `bool helper[X][Y] {};` |
| Однострочный блок | пробел после `{` и перед `}` | `{ return false; }` |
| Тернарный оператор | пробелы вокруг `?` и `:` | `a < b ? b : a` |
| Шаблон | `template<typename T, size_t len>`, без пробела после `template`; вариант `template <…>` тоже встречается | |

> Пробел перед `(` в **определении**, но не в **вызове**, это сознательная привычка последнего
> месяца. В вызовах на сентябрь–октябрь приходится около 90 % без пробела.
> Но иногда проскакивает `SelectionSort (arr);` и `std::gcd (i, nwdAll);`. Лучше писать без пробела.

Продолжение длинных выражений:

- Цепочка `<<` переносится с отступом +4 и оператором **в начале** строки:

  ```cpp
  std::cout << " | sum: "
      << sumRows[x];
  ```

- Тернарный оператор переносится так, что `?` и `:` стоят **в конце** строки:

  ```cpp
  const bool shouldSwap = order == SortOrder::Descending ?
      arr[fastPtr] > arr[bestIndex] :
      arr[fastPtr] < arr[bestIndex];
  ```

- Объявление нескольких переменных с переносом: продолжение на новой строке после запятой (в старых файлах без выравнивания, в `Matura2013` с выравниванием на 4):

  ```cpp
  int evenCharsCounter = 0,
      sameCharsQuantityCounter = 0,
      wordsOnlyFromZeroes = 0;
  ```

---

## 4. Однострочные блоки и ветвления

Фирменная черта: **короткие тела пишутся в одну строку в фигурных скобках**.

```cpp
if (!inputFile) { std::cerr << "Error while opening input file!"; return 1; }
if (arr[i] == target) { return i; }
if (!swapped) { break; }
if (num % div == 0) { ++ctr; num /= div; }
else { ++div; }
if (IsPrime(n)) { std::cout << n << ' '; ++ctr; }
```

Несколько простых инструкций в одной строке допустимы, если они тесно связаны:

```cpp
arr[0] = false; arr[1] = false;
if (arr[mid] > target) { left = mid - 1; continue; }
```

Правила:

- Однострочный блок допустим, пока в нём **1–3 коротких инструкции** и нет вложенных блоков.
- Если логика сложнее, раскрывай многострочно.
- **Guard clauses / ранний выход** вместо глубокой вложенности: `if (!x) { continue; }`, `if (arr.size() <= 1) { return; }`.
- Условие для базового случая рекурсии идёт **первым**:

  ```cpp
  if (curr == size) { return; }
  ```

- Для `if/else` с двумя возвращаемыми значениями иногда сразу тернарный `return`:
  `return b == 0 ? a : gcd(b, a % b);`.

---

## 5. Порядок `#include`

Алфавитного порядка **нет** (по алфавиту отсортировано только 16 из 104 файлов с тремя и более include). Но есть устойчивая «иерархия привычек»:

1. `<iostream>` идёт первым (пара `iostream` → `fstream` встречается 124 раза).
2. `<fstream>`, если работа с файлами.
3. `<string>` (часто опускается: тянется через `iostream`/`fstream`; в свежих файлах `<string>` бывает и явно).
4. Утилиты и алгоритмы: `<utility>`, `<algorithm>`, `<numeric>`, `<cstddef>`, `<cstdlib>`, `<ctime>`, `<climits>`, `<stdexcept>`, `<optional>`.
5. Контейнеры: `<unordered_map>`, `<unordered_set>`, `<vector>`. Контейнеры последние, и после `<fstream>` обычно соблюдается алфавит между собой (`numeric`, `unordered_map`, `vector`).

Типичные образцы из репозитория:

```cpp
#include <iostream>
#include <fstream>
#include <string>
```

```cpp
#include <iostream>
#include <vector>
#include <fstream>
#include <utility>
```

```cpp
#include <climits>
#include <iostream>
#include <fstream>
#include <numeric>
#include <unordered_map>
#include <vector>
```

Правила:

- Только угловые скобки `<…>` (кавычки `"cstddef"` в `Tasks.cpp`, это ошибка).
- Только C++-заголовки: `<cstddef>`, `<cstdlib>`, `<ctime>`, `<climits>`, `<cstdint>`. Старые `<time.h>`, `<limits.h>`, `<stdint.h>` остались в школьных работах.
- Нет пустых строк внутри блока include; после блока одна пустая строка.
- Включай только то, что реально используется (коммит *«remove unused imports»*).
- В `Wrappers/Alghoritms/*` каждый include может иметь пояснение в конце строки:

  ```cpp
  #include <optional> // for optional values return
  #include <cstdlib>  // for size_t
  ```

  Для обычных задач без пояснений.

---

## 6. Конфигурационный блок и константы

Имена файлов и параметры выносятся в блок констант сразу после include.

### Короткий вариант (один–два файла, без баннера)

```cpp
const std::string INPUT_FILE = "input.txt";
const std::string OUTPUT_FILE = "zadanie2.txt";
```

### Матурный вариант (с баннером)

```cpp
// =========================== CONFIGURATION ===========================

const std::string INPUT_FILE_NAME = "korpo_przyklad.txt";
const std::string OUTPUT_FILE_NAME = "wyniki4.txt";

// =====================================================================
```

Правила баннера:

- Заголовок `CONFIGURATION` заглавными, окружён `=`.
- Закрывающая линия **той же длины**, что и открывающая.
- Пустая строка после открывающей и перед закрывающей.
- Баннер используется в матурных задачах и там, где ≥ 2 настраиваемых параметров (в `Fibonacci.cpp`, `SemiprimeNum.cpp`, `munchausenNumbers.cpp` тоже). Для массивов файлов: `const std::string INPUT_FILE_NAMES[3] = { … };`.
- Константы размера / границ тоже сюда: `const int MIN = 100; const int MAX = 1000;`, `constexpr int DECIMAL_DIGITS = 10;`.

Константы:

- `UPPER_SNAKE_CASE`: `INPUT_FILE`, `OUTPUT_FILE_NAME`, `DIMENSIONS_X`, `POWERS_TABLE`.
- Глобальные `const std::string` / `constexpr` / `static constexpr` допустимы на верхнем уровне.
- Исключение: сентинел в стиле стандартной библиотеки пишется строчными, `static constexpr size_t npos = -1;`.
- Магические числа в алгоритмах вроде `1000001` (размер решета) допускаются, если это одноразовая задача.

---

## 7. Нейминг

### Сводка

| Сущность | Стиль | Примеры |
|---|---|---|
| Функции (основные) | **PascalCase** | `BubbleSort`, `IsPalindrome`, `SumASCIICode`, `LongestPrefixSuffix`, `FindString` |
| Функции-предикаты | `Is…`, `Has…`, `Does…`, `Are…` | `IsPrime`, `IsKaprekar`, `Has2PrimeDividers`, `DoesHave6Ones`, `AreZeroesMajority` |
| Функции «посчитать» | `Sum…`, `Count…`, `Num…` | `SumOfNeighbors`, `CountSwaps`, `NumOfPlaces` |
| Функции-обёртки | имя алгоритма без суффикса; рекурсивная часть `…Rec` | `QuickSort` → `QuickSortRec` → `PartitionQuickSort` |
| «Стандартные» алгоритмы | допускается snake_case / lowercase, по аналогии со стандартной библиотекой | `gcd`, `lcd`, `gcd_it`, `to_bin`, `przestaw` |
| Лямбды | PascalCase либо короткое строчное | `Print`, `rev`, `countDigits` |
| Переменные | **camelCase** | `inputFile`, `tempWord`, `maxWord`, `minValueIndex`, `bossForNobody` |
| Константы | `UPPER_SNAKE_CASE` | `INPUT_FILE`, `MIN` |
| Шаблонные параметры | `T`, `size_t len` | `template<typename T, size_t len>` |
| Типы (`enum class`) | PascalCase | `SortOrder { Ascending, Descending }` |

### Типовые короткие имена

- Индексы: `i`, `j` (вложенный), `x`, `y` (матрицы / поле), `nx`, `ny` (соседи).
- Счётчики: `ctr` (самое частое в новом коде), `counter`, `cnt`, `…Counter`, `++ctr`.
- Результат: `result` (в функциях), `res` (коротко), `sum`.
- Временные при чтении: `tempWord`, `tempNum`, `tempStr`, `tempChar`, `temp`, `word`, `word1`/`word2`.
- Массивы: `arr`, `mainArr`, `helperArr`, мапы: `mp`, `domMap`, `frequency`, `words`.
- Числа и строки: `num`, `str`, `str1`/`str2`, `c` для `char`.
- Указатели-бегунки: `fastPtr`, `ptr`, `searcher`, `shift` (смещение начала окна), `fence` («забор» в Quick Sort), `mid`, `left`, `right`, `first`, `last`, `piv`.
- Лучший индекс / лучшее значение: `minIdx`, `minValueIndex`, `bestIndex`, `maxSum`, `max`, `min`.
- Сохранённое значение при сдвиге: `temp`, `savedValue`, `val`.
- Потоки: `inputFile`, `outputFile` (всегда так; для нескольких: `inputFileWords`, `inputFileNew`).

### Особенности

- **Опечатки в именах закрепились и сохраняются для единообразия**: `Alghoritms`, `Erastofenes`, `Fibonnaci`, `neightboor`, `Task1-insetion`, `Harshard`. Если расширяешь существующий файл или папку, не переименовывай «исправления ради». Для нового кода лучше писать правильно.
- Имя функции — это глагол или предикат: `GenerateAll`, `PrintErastofenes`, `ParseFile`, `SimulateNextGen`.
- Версии одного алгоритма различаются **суффиксом** (см. [раздел 16](#16-организация-файлов-и-имена)): `Legacy`, `Vector`, `STL`, `Full`, `Short`, `Optimised`, `Minimal`, `IWS`, `_it`.
- Итеративная версия рекурсивной функции получает суффикс `_it` (`gcd_it`).
- Польские имена встречаются только в школьных заданиях (`przestaw`, `Silnia`, `wynik`). Новое пишется по-английски.

---

## 8. Типы, циклы, инициализация

### Типы

- **Индексы и размеры — `size_t`** (с апреля 2026). Раньше в старом коде был `int`.
- Суммы, коды ASCII: `unsigned int` с `static_cast<unsigned int>(c)` (C-style cast `(int)x` встречался в мае, больше не использовать).
- Большие числа: `unsigned long long` (степени, факториалы), `long` / `unsigned long` для произведений кодов (Task5).
- Начальные значения экстремумов: `UINT_MAX` из `<climits>` либо `std::numeric_limits<…>::max()`; для максимума часто стартуют с `0` или `-1` как «пустого».
- `bool` для массива решета, флагов (`swapped`, `match`).
- `auto` разрешён в range-for и для сложных типов (`std::chrono`, лямбды). Для простых типов (`int`, `size_t`) пишется явно.

### Циклы

```cpp
for (size_t i = 0; i < arr.size(); ++i) { … }        // классический
for (char c : str) { … }                             // по символам
for (auto i : arr) { … }                             // по значениям
for (const auto& i : arr) { … }                      // по const-ссылке
for (auto& [key, value] : map) { … }                 // structured binding
while (inputFile >> tempWord) { … }                  // чтение файла
```

- **Только префиксный инкремент `++i` / `--i`** (коммиты *«unify for-loop increment style»*, *«searcher-- → --searcher to follow the project standard»*). Постфиксный `i++` остался в старом коде и в `arrays[key]++`, где это значение не используется. Для счётчика в мапе допустимо `mp[res]++;`.
- Условие цикла предпочитай безопасное для `unsigned`: `shift + 1 < len` вместо `shift < len - 1` (underflow при `len == 0`).
- Квадратный корень заменяется условием `i * i <= num` (без `<cmath>`).
- Шаг по нечётным / `6k ± 1`: `i += 2`, `i += 6`.
- Переменная цикла объявляется внутри `for`.

### Инициализация

```cpp
int arr[20] = {};                    // нули
bool helper[X][Y] {};                // нули
int sumRows[ROWS] = {};
std::vector<size_t> cnt (50001, 0);  // vector(n, value), с пробелом перед (
std::vector<unsigned int> arr = {};
int ctr = 0, div = 2;                // несколько однотипных в одну строку
unsigned int max = 0, min = UINT_MAX;
```

- Объявляй переменную **как можно ближе к первому использованию**, но блок объявлений в начале `main` (потоки, счётчики, временные переменные) допустим и является нормой.
- Несколько однотипных переменных через запятую в одной строке — норма.

---

## 9. Функции и шаблоны

### Сигнатуры

```cpp
bool IsPalindrome (const std::string& str) {              // read-only строка → const&
void BubbleSort (std::vector<int>& arr) {                 // изменяемый контейнер → &
unsigned int SumASCIICode (const std::string& str) {
long fibonnaci (int n, long firstNum = 0, long secondNum = 1) { // аккумуляторы как параметры по умолчанию
```

- Пробел между именем и `(` в **определении**.
- Строки, векторы и т. п. всегда передаются по ссылке (`const &` для чтения).
- Простые типы по значению.
- Результат возвращается значением (не через out-параметр). Исключение — учебная рекурсия `Silnia(int num, int& wynik)`.
- Для «не найдено» — `npos` (`static constexpr size_t npos = -1;`) в ручных задачах или `std::optional<size_t>` / `std::nullopt` в переиспользуемых функциях `Wrappers/Alghoritms`.
- Ошибки: `throw std::invalid_argument("…: " + roman)` / `std::runtime_error` в функциях; `return 1;` + `std::cerr` в `main`.

### Legacy-массивы (C-style) через ссылку и шаблон

```cpp
template<typename T, size_t len>
void InsertionSort (T (&arr)[len]) { … }

template<size_t len>
void ErastInit (bool (&arr)[len]) { … }

void BubbleSort (int (&arr)[5]) { … }
```

- Шаблон на **отдельной строке** над функцией.
- Размер массива — параметр шаблона `size_t len` (имя именно `len`).
- Массив всегда передаётся по ссылке, чтобы знать размер.
- Для векторных версий вместо шаблона по размеру: `std::vector<T>& arr` и `arr.size()`.

### Лямбды

Лямбда `Print` с fold expression дублирует вывод на консоль и в файл (≈56 использований):

```cpp
auto Print = [&] (auto&&... args) { (std::cout << ... << args) << "\n"; (outputFile << ... << args) << "\n"; };
Print("Ilość liczb: ", ctr);
Print(i, ": ", fibonacciNum, ": ", tempStr);
```

- Одна строка, захват `[&]`, пробел между `]` и `(`.
- Вызывается `Print();` для пустой строки.
- Ставится в `main` после открытия `outputFile`.
- Короткие помощники в `main` тоже лямбдами: `auto rev = [] (std::string s) -> std::string { … };`.

### Размер функции

- Одна функция — одна идея. `main` собирает в себе только ввод/вывод и вызовы.
- Помощники, которые делают одну проверку, отдельными функциями (`SumASCIICode`, `IsPalindrome`, `IsInputValid`).
- Если функцию нужно повторить в нескольких файлах, она копируется как есть (`ErastInit`/`ErastGen` скопированы в Task2 и Task3). Общих `.h` нет.

---

## 10. Ввод / вывод и файлы

### Открытие входного файла

```cpp
std::ifstream inputFile (INPUT_FILE);
if (!inputFile) { std::cerr << "Error while opening input file!"; return 1; }
```

- Эта пара строк **неизменна** (текст сообщения `"Error while opening input file!"` — почти дословно во всех файлах).
- Код возврата: с лета 2026 `return 1;` (раньше `-1`).
- Выходной файл: `std::ofstream outputFile (OUTPUT_FILE);` после пустой строки; проверка открытия делается в старых и матурных шаблонах (`"Error while opening output file!"`), в свежих учебных задачах пропущена. Для матурных решений проверка полезна.
- Потоки закрывать вручную не нужно (RAII), `close()` только если реально нужно досрочно (в `Wrapper-Matura.cpp` и `inputFileNew.close()` с комментарием).

### Чтение

```cpp
while (inputFile >> tempWord) { … }      // слова
while (inputFile >> word1 >> word2) { … } // пары
while (inputFile >> temp) { arr.push_back(temp); } // числа в вектор
```

- Чтение через `>>` в условии цикла, без `.eof()`.
- Для строк целиком `std::getline`.

### Вывод

- **`"\n"` в двойных кавычках** для конца строки в цепочках (`<< "\n"`) в свежем коде.
- `'\n'` и `' '` одиночными кавычками, когда это один символ в цепочке (`<< i << ' '`, `<< '\n'`).
- **`std::endl` не использовать** (96 использований, в основном апрель–май; последнее исключение — `Tasks.cpp`).
- Финальный вывод ответа обычно без завершающего `\n`; построчные ответы с `"\n"`.
- Ответы на польском в стиле матуры: `"Ilość liczb: "`, `"Liczba par: "`, `"Największa liczba w pliku: "`; сообщения об ошибках — английские.
- Стрелка `→` — разделитель в выводе: `Print(maxWord, " → ", maxSum);`.
- Если вывод должен быть и в консоль, и в файл:
  - либо `Print`-лямбда (предпочтительно);
  - либо две строки подряд (`std::cout << …; outputFile << …;`), как в задачах от 16.10.

---

## 11. Структура `main`

Типовой порядок внутри `main`:

1. Открытие `inputFile` + проверка.
2. Пустая строка.
3. Открытие `outputFile` (+ проверка в матурных шаблонах).
4. Пустая строка.
5. Объявление рабочих переменных: временные, счётчики, максимумы, контейнеры.
6. Пустая строка.
7. `Print`-лямбда (если нужна).
8. Основной цикл чтения.
9. Пустая строка.
10. Вывод результатов.
11. Пустая строка и `return 0;`.

```cpp
int main () {
    std::ifstream inputFile (INPUT_FILE);
    if (!inputFile) { std::cerr << "Error while opening input file!"; return 1; }

    std::ofstream outputFile (OUTPUT_FILE);

    std::string tempWord;
    unsigned int ctr = 0;

    while (inputFile >> tempWord) {
        if (IsPalindrome(tempWord)) {
            ++ctr;
        }
    }

    std::cout << "Ilość: " << ctr;

    return 0;
}
```

- Сигнатура строго `int main () {` (без аргументов, пробел перед `()`).
- `return 0;` в конце — норма. В самых маленьких учебных примерах (BinarySearch, gcd + lcd, Matura2026/Task2) может отсутствовать, что допустимо.
- Тестовые данные в маленьких алгоритмических файлах задаются в `main` литералами (`int arr[5] = { 12, 5, 17, 21, 9 };`, `std::string str2 = "ca";`) или генерируются `rand() % 10`.

---

## 12. Пустые строки

- **Одна** пустая строка между функциями (две подряд только в старом коде).
- Пустая строка **перед `return`** в конце функции (почти всегда).
- Пустая строка после блока объявлений и перед циклом.
- Пустая строка между логическими блоками: после `while`/`for`, перед выводом.
- Пустая строка после include-блока и вокруг конфигурационного баннера.
- Внутри цикла/ветки пустых строк нет, кроме больших тел.
- Блок `if (!x) { … return …; }` сразу за объявлением переменных от них не отделяется, если логически связан.

---

## 13. Комментарии

Общий подход: **минимум комментариев**, код должен читаться сам. Из истории: *«Remove comment for code clarity»*, *«Remove readability comment…»*, *«Clean code»*, *«No LLM used»*.

Что комментируется:

1. **Почему** (не что): защита от underflow, оптимизации, сентинелы.
   `// shift + 1 < len is same as shift < len - 1 but safer for size_t (unsigned int)`.
2. **Сложность функции**, справа от сигнатуры: `// O(n)`, `// O(log n)`.
3. **Баннер конфигурации** (см. раздел 6).
4. **Этапы алгоритма**: короткая строка над блоком:
   `// find index of the best element (min or max depending on order)`,
   `// swap if necessary`,
   `// comparing to a right neightboor`,
   `// now displaying answers`.
5. **Пометки `// !`** для важного замечания: `// ! QuickSort for Legacy Arrays (C)`.
6. **Пояснение include** в `Wrappers/Alghoritms/*`: `// for size_t`.
7. В учебных/«шпаргалочных» реализациях (`Wrappers/Alghoritms/Sorting/InsertionSort/InsertionSortLegacy.cpp`) допускаются подробные комментарии почти на каждой строке. В Legacy-версии они **на русском**, в `Vector`-версии комментариев нет. Это осознанное деление: *«Legacy (rus comments)»* и *«Vector (no comments)»*.

Формат:

- Только `//`, блочных `/* */` нет.
- Пробел после `//`.
- Строчными буквами, без точки в конце; английский (основной) или русский (разбор алгоритмов).
- Комментарий на той же строке отделяется **одним пробелом** от кода.
- Закомментированный отладочный код допускается временно, но не стоит оставлять (`// std::cout << "R: " …` в `Matura2025.cpp`).

Не комментируются: очевидные вещи, `#include` в обычных задачах, сами имена функций.

---

## 14. Привычки написания алгоритмов

Здесь собраны повторяющиеся приёмы по каждому классу задач.

### 14.1. Общие приёмы

- **Две версии**: ручная и STL, либо Legacy-массив и вектор. Классический набор: `…Legacy`, `…Vector`, `…STL`, `…Short`, `…Full`, `…Optimised`.
- Сначала простое решение, потом оптимизированное (brute force → `O(n)`; `IsPrimeV1` vs `IsPrimeV2` с замером `std::chrono`).
- **Ранний `return`/`continue`/`break`** вместо вложенности.
- Флаг `bool match`/`swapped` + `break`.
- **Безопасность для `unsigned`**: проверка `size() < 2`/`<= 1` до цикла с `size() - 1`.
- Вычитание сначала в безопасном виде: `left + ((right - left) / 2)`, а не `(left + right) / 2`.
- Сумма / произведение накапливается в более широкий тип (`unsigned long long`), проверка раннего выхода по превышению (`if (sum > original) return false;`).
- Копия числа для разбора: `cp`, `copy`, `original`.
- Подсчёт частот: `std::unordered_map<K, int>` + `map[key]++`, либо массив `int cnt[10] {}`, либо `std::vector<size_t> cnt (N, 0)`.
- Поиск максимума: переменная `max`/`maxSum` + парная `maxWord`; инициализация `0` либо `-1` как «ещё не было»; для минимума `UINT_MAX`. Обновление: `if (curr > max) { max = curr; maxWord = … ; }`.

### 14.2. Работа с цифрами

```cpp
while (num > 0) {
    int digit = num % 10;
    num /= 10;
}
```

- `c - '0'` для символа → цифра, `'0' + d` для цифра → символ.
- Количество цифр отдельной функцией (`NumOfPlaces`, или `countDigits` лямбдой).
- Степень — своей функцией `IntPower` / `Power` (цикл умножения), для частых — `constexpr` таблица (`POWERS_TABLE` в `munchausenNumbers.cpp`).
- Счётчики цифр: `int digitsCount[10] {};` и обращения `digitsCount[cp % 10]++`.
- Сравнение в обратном порядке цифр через `--pos`.

### 14.3. Простые числа

- Базовый: `if (num < 2) return false; for (i = 2; i * i <= num; ++i)`.
- Оптимизированный (**предпочтительный**, правило `6k ± 1`):

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

### 14.4. Решето Эратосфена

- Булев массив на стеке `bool arr[1000001];` (границы в `main`).
- Две–три функции: заполнение, просеивание, вывод.
  - `GenerateAll`/`ErastInit`: `arr[0] = false; arr[1] = false;` и остальное `true`.
  - `Erastofenes`/`ErastGen`: внешний цикл `i * i < len`, `if (!arr[i]) { continue; }`, внутренний от `i * i` шагом `i`.
  - `PrintErastofenes`: выводит `i`, у которых `arr[i]`.
- Перед обращением к решёту по входному числу проверка границ: `num >= 0 && num <= 1000000 && arr[num]`.

### 14.5. НОД / НОК

- Рекурсивный одной строкой + итеративный с суффиксом `_it`:

  ```cpp
  int gcd (int a, int b) { return b == 0 ? a : gcd (b, a % b); }
  int gcd_it (int a, int b) { while (b > 0) { int tmp = b; b = a % b; a = tmp; } return a; }
  int lcd (int a, int b) { return (a / gcd (a, b)) * b; }   // сначала делим, чтобы не переполнить
  ```

- Если разрешено, `std::gcd` из `<numeric>`.
- НОД «всех»: накапливается в цикле `nwdAll = std::gcd(i, nwdAll)`.

### 14.6. Сортировки

Общее: порядок элементов меняет `std::swap`; отсортированная часть слева; `size_t`-индексы.

- **Selection**: `minIdx`/`minValueIndex`/`bestIndex`; внутренний цикл ищет индекс лучшего; своп только `if (bestIndex != i)`; внешний цикл `shift + 1 < len`. Направление — `enum class SortOrder { Ascending, Descending };` (а не `bool`).
- **Bubble**: проход `j < size - i - 1`; флаг `swapped` и `if (!swapped) { break; }`; перед циклами `if (arr.size() < 2) return;`.
- **Insertion**: сохранить `arr[i]` в `temp`/`savedValue`/`val`; бегунок `ptr`/`searcher`/`fastPtr` = `i`; пока `ptr > 0 && arr[ptr - 1] > val` сдвигаем вправо и `--ptr`; потом вставка.
- **Quick (Lomuto)**: pivot = последний элемент, «забор» `fence = first - 1`, функции `PartitionQuickSort` + `QuickSortRec` + публичная обёртка `QuickSort` с проверкой `size() <= 1`; вариант `RandomPivot` со `srand(time(NULL))` и свопом случайного элемента в конец.

### 14.7. Поиск

- **Binary**: `left`, `right`, `mid = left + ((right - left) / 2)`; три ветки `==` / `<` / `>`; результат — индекс либо `npos`/`std::nullopt`. Массив предварительно сортируется `std::sort`.
- **Linear**: `for` + `if (arr[i] == target) { return i; }`, затем `return std::nullopt;`.
- **Подстрока**: `shift`-цикл по началу и внутренний по символам, `bool match` + `break`; короткая версия `str1.find(str2) != std::string::npos`. Собственный `substr` резервирует память: `result.reserve(len)`.

### 14.8. Строки и слова

- Палиндром: `for (i < size / 2) if (str[i] != str[size - i - 1]) return false;`.
- Сумма ASCII: `for (char c : str) sum += static_cast<unsigned int>(c);`.
- Зеркальные слова: лямбда `rev` с `std::reverse`.
- Пересечение префикс/суффикс: убывающий цикл `i` от `min(size1, size2)` вниз до порога, сравнение `substr`.
- Уникальные символы: `std::unordered_set<char>` и `.count()`.
- Для римских цифр / таблиц соответствий — `static const std::unordered_map<char, int>` на верхнем уровне, вызовы `.at()`, `.count()`.

### 14.9. Рекурсия

- База первой строкой с `return`.
- Аккумуляторы передаются параметрами (tail-style): `fibonnaci(n - 1, secondNum, firstNum + secondNum)`.
- Для вывода по индексу: `Recurr(arr, size, curr + 1)`.

### 14.10. Матура: разбор по заданиям

- Для каждого пункта задания отдельный файл `Task3_1.cpp`, `Task3_2.cpp` (или `1.cpp`, `2.cpp`, `3.cpp`) либо отдельные функции в одном `main.cpp`.
- Всегда в паре с файлами данных: `…_przyklad.txt` (пример) для отладки, потом основной.
- Заготовки: `Wrapper-Matura.cpp`, `Minimal-Wrapper-Matura.cpp`.

---

## 15. STL vs ручная реализация

- Если на уроке просят «без STL» (или цель — понять алгоритм), пишется вручную, и рядом может лежать STL-версия для сравнения (`IsAutobiographicSTL`).
- Часто используемые стандартные функции: `std::swap`, `std::sort`, `std::count`, `std::reverse`, `std::min/max`, `std::gcd`, `std::to_string`, `std::stoi`, `std::accumulate`, `std::numeric_limits`, `std::unordered_map/set`, `std::vector`, `std::array`.
- Контейнеры: `std::vector` вместо `new[]` (динамическая память `new` встретилась только в школьном TJ03); `unordered_*` вместо `map/set`, если порядок не нужен (коммит *«Rewritten … to std::unordered_set to work faster»*).
- Случайные числа: `rand() % N` + `srand(time(NULL))` в простых примерах; `<random>` (`std::random_device`, `std::mt19937`) в «серьёзных».
- Комментарий в `Substr.cpp` показывает позицию: *«Just use std::string.substr(pos, len), in case you can't:»*.

---

## 16. Организация файлов и имена

### Имена файлов

| Тип | Формат | Примеры |
|---|---|---|
| Алгоритм | `PascalCase.cpp` | `BinarySearch.cpp`, `RomanToInt.cpp`, `Erastofenes.cpp` |
| Алгоритм с пробелом / символами | допускается | `gcd + lcd.cpp` |
| Задача урока | `TaskN.cpp`, `Task1-bubble.cpp` (суффикс через дефис, строчными) | |
| Подпункт | `TaskN_M.cpp` | `Task3_2.cpp` |
| Матура | `main.cpp` в `MaturaГГГГ/`, `ZadanieA.cpp`, `TaskA.cpp` | |
| Школьные задания | `Zadanie P14.cpp`, `ZadanieTJ03.cpp` | (устарело) |
| Варианты | суффикс в PascalCase | `InsertionSortLegacy.cpp`, `InsertionSortVector.cpp`, `QuickSortRandomPivot.cpp`, `ZadanieDOptimised.cpp`, `ContainsSubstring.cpp` |

### Структура директорий

```
CPP/
├── CPPIntro (1st class)/   — школьный курс по темам (устаревший стиль)
├── Matura/
│   ├── PodstawowaMatura/MaturaГГГГ/
│   ├── RozszerzonaMaturaSF/MaturaГГГГ/
│   └── RozszerzonaMaturaNF/MaturaГГГГ/…
├── PestitFiles/
│   ├── 2026/27 tasks/ДД.ММ.ГГГГ/   — задачи по датам уроков (основной актуальный стиль)
│   ├── CRoadMap/                    — чистый C, LessonN.c
│   ├── Fun/, LeetCode/
├── SideTasks/              — задачи по теории чисел
├── Wrappers/               — переиспользуемые заготовки (Alghoritms/, Matura wrappers)
└── qs files/               — переработанные решения
```

- Папка за дату урока: `16.10.2026`, `21.10.2026`.
- Рядом с кодом лежат входные/выходные файлы задачи (`input.txt`, `liczby_do_zadania.txt`, `wyniki3.txt`).
- Выходные результаты в `.txt` называются по формату задания (`wyniki4.txt`, `zadanie2.txt`, `wynik5.txt`).
- Бинарники (`*.bin`, `output.bin`) не коммитятся (есть в `.gitignore`, но несколько уже просочилось).

---

## 17. Git и коммиты

Формат сообщений — «глагол + (область) → описание», по-английски, без точки:

```
add (task) → add tasks from 21.10.2026
add (tasks+gcd+lcd) → implement various lesson tasks and two efficient algorithms
Feat (bubble sort & binary search)
fix (imp. rem): remove unused imports
Done all tasks from 16.10.2026 lesson
Done Task 3.3 from Matura 2026 (latest)
Refactor SelectionSort: replace bool parameter with SortOrder enum
```

- Глаголы: `add`, `Add`, `Feat`/`feat`, `fix`, `Done`, `Refactor`, `Implemented`, `Rewritten`, `Remove`.
- Стрелка `→` внутри сообщения допустима.
- Тело коммита — маркированные пункты `- …` (что использовано: `Used std::abs…`, `Implemented …`).
- Регистр первой буквы непостоянный; стремись к `add (scope) → описание` / `Done …`.
- Один коммит — один урок / задание / алгоритм.
- Для вручную написанных решений допускается пометка «No LLM used» / «Clean code» в теле.

---

## 18. Эволюция стиля (что считать устаревшим)

| Период | Признаки | Статус |
|---|---|---|
| Фев–мар 2026 | `using namespace std;`, Allman-скобки, `cout`/`endl`, имена на польском, `i++`, табы | устарело |
| Апр–май 2026 | `std::` везде, K&R, однострочные `{ … }`, баннер CONFIGURATION, `int main()` без пробела, много `std::endl`, `i++`/`int i`, `size_t` начинает появляться, `return -1` | переходный |
| Июнь 2026 | `unordered_set`, `size_t`, `++i` ("project standard"), баннер | близко к актуальному |
| Сен–окт 2026 | `int main ()` с пробелом, пробел в определениях `Foo (…)`, `++i`, `size_t`, `"\n"`, `return 1`, константы `INPUT_FILE`, `static constexpr npos`, без `std::endl` | **актуальный** |

Коротко: **использовать `std::`, K&R, 4 пробела, `++i`, `size_t`, `"\n"`, `int main ()`, `Foo (…)` в определениях, однострочные `{ … }`.**

---

## 19. Известные грабли

Небольшая «карта мин» из собственных файлов:

- `PestitFiles/2026/27 tasks/BinarySearch.cpp`: `left = mid - 1` при `size_t` даёт underflow, а условие `left < right` ломает поиск на границах. Канонический вариант лежит в `Wrappers/Alghoritms/Search/BinarySearch.cpp` (`right = mid;`, `left = mid + 1;`, комментарий про underflow).
- `Tasks.cpp::Factorial` на самом деле считает сумму `num + Factorial(num - 1)`, а не произведение.
- `Matura2025.cpp::przestawI` — незавершённая итеративная версия с бесконечным `while`.
- `Task3.cpp` (21.10) объявляет `max, maxSum`, которые не используются; `Task2.cpp` объявляет неиспользуемый `ctr`. Неиспользуемые переменные лучше убирать.
- `arr[0]`/`arr[1]` в решете: обращение к `arr[1]` невалидно при `len < 2`.
- Крупные массивы на стеке (`bool arr[1000001]`) работают, но для больших значений лучше `std::vector<bool>`.
- Опечатки в именах закреплены (см. раздел 7).

---

## 20. Эталонные шаблоны

### Задача с файлами (современный стиль)

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

### Матурный шаблон с баннером

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

### Алгоритм на Legacy-массиве

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

### Алгоритм на `std::vector`

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

---

### Чек-лист перед коммитом

- [ ] 4 пробела, K&R, скобки у всех `if/for/while`
- [ ] `int main ()` и `Foo (…)` в определениях; вызовы без пробела
- [ ] `std::` везде, нет `using namespace std`, нет `bits/stdc++.h`
- [ ] Include: `iostream` → `fstream` → `string` → утилиты → контейнеры, без лишних
- [ ] `INPUT_FILE`/`OUTPUT_FILE` (или баннер CONFIGURATION) вынесены наверх
- [ ] `++i`, `size_t` для индексов, `"\n"` вместо `std::endl`
- [ ] Проверка `if (!inputFile) { std::cerr << "…"; return 1; }`
- [ ] Короткие тела в одну строку `{ … }`, длинные раскрыты
- [ ] Нет неиспользуемых переменных и include
- [ ] Пустая строка перед `return`, между функциями ровно одна
- [ ] Комментарии только «почему» / сложность / этапы
- [ ] Коммит: `add (scope) → описание` или `Done …`
