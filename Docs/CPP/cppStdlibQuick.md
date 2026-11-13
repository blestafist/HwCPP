# C/C++ Встроенные Библиотеки - Шпаргалка

## 📌 Основные C библиотеки

| Библиотека | Для чего | Основные функции |
|-----------|---------|-----------------|
| `<stdio.h>` | Ввод/вывод | `printf()`, `scanf()`, `fopen()`, `fread()` |
| `<stdlib.h>` | Память, числа | `malloc()`, `free()`, `atoi()`, `rand()` |
| `<string.h>` | Строки (C) | `strlen()`, `strcpy()`, `strcat()`, `strcmp()` |
| `<math.h>` | Математика | `sqrt()`, `pow()`, `sin()`, `cos()` |
| `<time.h>` | Время | `time()`, `clock()`, `ctime()` |
| `<ctype.h>` | Символы | `isalpha()`, `toupper()`, `tolower()` |
| `<limits.h>` | Границы типов | `INT_MAX`, `LONG_MIN` |

**⚠️ Компилировать с `-lm` если используешь `<math.h>`**

---

## 🚀 Важные C++ библиотеки

### Контейнеры и структуры данных

| Библиотека | Для чего | Основные функции | Когда использовать |
|-----------|---------|------------------|-------------------|
| `<vector>` | **Динамический массив** | `push_back()`, `pop_back()`, `size()`, `[]` | Когда размер заранее неизвестен. **По умолчанию** для всех случаев |
| `<deque>` | **Двусторонняя очередь** | `push_front()`, `push_back()`, `pop_front()` | Быстрая вставка/удаление в начало и конец |
| `<list>` | **Двусвязный список** | `push_back()`, `insert()`, `erase()` | Частые вставки/удаления в середину. O(1) для вставки |
| `<map>` | **Отсортированный словарь** | `insert()`, `find()`, `[]`, `count()` | Нужен порядок элементов, частый поиск по ключу |
| `<unordered_map>` | **Быстрый словарь** | `insert()`, `find()`, `[]`, `at()` | Нужна O(1) скорость поиска, порядок неважен |
| `<set>` | **Множество с порядком** | `insert()`, `find()`, `erase()` | Уникальные элементы в отсортированном порядке |
| `<unordered_set>` | **Множество (хеш-таблица)** | `insert()`, `find()`, `count()` | Быстрая проверка наличия, уникальные элементы |
| `<queue>` | **Очередь FIFO** | `push()`, `pop()`, `front()`, `empty()` | Первый пришел — первый вышел |
| `<stack>` | **Стек LIFO** | `push()`, `pop()`, `top()`, `empty()` | Последний пришел — первый вышел |
| `<priority_queue>` | **Приоритетная очередь** | `push()`, `pop()`, `top()` | Элементы извлекаются по приоритету (max-heap по умолчанию) |

### Алгоритмы и функции

| Библиотека | Для чего | Основные функции | Когда использовать |
|-----------|---------|------------------|-------------------|
| `<algorithm>` | **Алгоритмы STL** | `sort()`, `find()`, `count()`, `reverse()`, `unique()`, `transform()` | Для работы с контейнерами: сортировка, поиск, преобразования |
| `<numeric>` | **Численные операции** | `accumulate()`, `iota()`, `inner_product()` | Суммирование, заполнение, скалярные произведения |
| `<functional>` | **Функциональное программирование** | `std::function`, `std::bind()`, `std::greater<>` | Передача функций как параметров, лямбды, функторы |

### Строки и текст

| Библиотека | Для чего | Основные функции | Когда использовать |
|-----------|---------|------------------|-------------------|
| `<string>` | **Строки C++** | `find()`, `substr()`, `replace()`, `length()` | **Всегда** вместо `char*`. Безопаснее и удобнее |
| `<regex>` | **Регулярные выражения** | `std::regex_search()`, `std::regex_replace()` | Поиск по сложному шаблону, парсинг текста |

### Ввод/вывод

| Библиотека | Для чего | Основные функции | Когда использовать |
|-----------|---------|------------------|-------------------|
| `<iostream>` | **Консольный ввод/вывод** | `std::cout`, `std::cin`, `std::cerr` | **Всегда** вместо `printf/scanf` в C++ |
| `<fstream>` | **Файловый ввод/вывод** | `std::ifstream`, `std::ofstream`, `std::fstream` | Чтение и запись файлов |
| `<sstream>` | **Строковые потоки** | `std::stringstream`, `std::istringstream` | Парсинг строк, форматирование в строку |
| `<iomanip>` | **Манипуляторы вывода** | `std::setprecision()`, `std::setw()`, `std::hex` | Форматирование чисел (точность, ширина, основание) |

### Память и указатели

| Библиотека | Для чего | Основные функции | Когда использовать |
|-----------|---------|------------------|-------------------|
| `<memory>` | **Умные указатели** | `std::unique_ptr`, `std::shared_ptr`, `std::make_unique` | **Всегда** вместо `new/delete`. Автоматическое управление памятью |
| `<new>` | **Операции выделения памяти** | `new`, `delete`, `operator new` | Редко используется. Предпочитайте умные указатели |

### Время и случайность

| Библиотека | Для чего | Основные функции | Когда использовать |
|-----------|---------|------------------|-------------------|
| `<chrono>` | **Работа с временем** | `high_resolution_clock`, `duration`, `time_point` | Измерение времени выполнения, работа с временными интервалами |
| `<random>` | **Генерация случайных чисел** | `std::mt19937`, `std::uniform_int_distribution` | **Всегда** вместо `rand()`. Более качественный генератор |

### Обработка ошибок и типы

| Библиотека | Для чего | Основные функции | Когда использовать |
|-----------|---------|------------------|-------------------|
| `<exception>` | **Исключения** | `try/catch`, `throw`, `std::exception` | Обработка ошибок. Выброс и перехват исключений |
| `<stdexcept>` | **Стандартные исключения** | `std::invalid_argument`, `std::runtime_error` | Выброс специфических типов исключений |
| `<typeinfo>` | **Информация о типах** | `typeid()`, `std::type_info` | Отладка, получение имени типа в runtime |
| `<limits>` | **Границы типов (C++)** | `std::numeric_limits<T>::max()` | Вместо `<limits.h>`. Получение min/max значений типа |

### Утилиты

| Библиотека | Для чего | Основные функции | Когда использовать |
|-----------|---------|------------------|-------------------|
| `<utility>` | **Утилиты** | `std::pair`, `std::make_pair()`, `std::swap()` | Работа с парами значений, свопинг |
| `<tuple>` | **Кортежи (несколько значений)** | `std::tuple`, `std::get<>()` | Группировка нескольких значений разных типов |
| `<optional>` | **Опциональное значение** | `std::optional<T>`, `has_value()` | Функция может вернуть значение или ничего (C++17) |
| `<variant>` | **Дискриминированное объединение** | `std::variant<T1, T2>`, `std::get<>()` | Переменная может быть одним из нескольких типов (C++17) |
| `<any>` | **Любой тип** | `std::any`, `std::any_cast()` | Хранение значения неизвестного типа (C++17) |

---

## 💡 Быстрые примеры

### Ввод/вывод
```cpp
#include <iostream>
std::cout << "Hello" << std::endl;
std::cin >> x;
```

### Строки
```cpp
#include <string>
std::string s = "Hello";
s.find("llo");        // Поиск
s.substr(0, 2);       // Подстрока
```

### Массивы
```cpp
#include <vector>
std::vector<int> v = {1, 2, 3};
v.push_back(4);       // Добавить
v.size();             // Размер
```

### Сортировка
```cpp
#include <algorithm>
std::sort(v.begin(), v.end());
std::sort(v.begin(), v.end(), std::greater<int>());  // Убывание
```

### Словари
```cpp
#include <map>
std::map<std::string, int> m;
m["key"] = 10;
m.find("key");        // Поиск
```

### Время
```cpp
#include <chrono>
auto start = std::chrono::high_resolution_clock::now();
// код
auto elapsed = std::chrono::high_resolution_clock::now() - start;
```

### Умные указатели
```cpp
#include <memory>
auto ptr = std::make_unique<int>(42);     // Исключительное владение
auto shared = std::make_shared<int>(10);  // Общее владение
```

### Случайные числа
```cpp
#include <random>
std::mt19937 gen(std::random_device{}());
std::uniform_int_distribution<> dis(1, 100);
int random_num = dis(gen);
```

---

## 🎯 Выбор контейнера

**Нужны быстрые вставка/удаление в начало/конец?** → `std::deque`
**Нужны быстрые вставка/удаление в середину?** → `std::list`
**Нужна скорость?** → `std::vector` (по умолчанию)
**Ключ-значение с порядком?** → `std::map`
**Ключ-значение без порядка (быстро)?** → `std::unordered_map`
**Уникальные значения?** → `std::set` / `std::unordered_set`

---

## 📝 Флаги компиляции

```bash
g++ file.cpp -o prog              # Базовая компиляция
g++ -std=c++17 file.cpp -o prog   # С C++17
g++ -O2 file.cpp -o prog          # Оптимизация
g++ -g file.cpp -o prog           # Отладка
g++ file.cpp -o prog -lm          # С математикой
g++ -Wall -Wextra file.cpp -o prog # Все warnings
```

---

## 📚 Полное описание основных библиотек

### 🔧 Контейнеры

#### `<vector>` - Динамический массив
Автоматически увеличивающийся массив. Основной контейнер в C++ для большинства задач.

**Основные методы:**
- `push_back(x)` - добавить элемент в конец O(1)
- `pop_back()` - удалить последний элемент O(1)
- `size()` - размер контейнера
- `clear()` - очистить контейнер
- `at(i)` / `[i]` - доступ по индексу
- `front()` / `back()` - первый/последний элемент
- `insert(it, x)` - вставить в позицию it O(n)
- `erase(it)` - удалить элемент O(n)
- `reserve(n)` - зарезервировать память

```cpp
#include <vector>
std::vector<int> v = {1, 2, 3};
v.push_back(4);      // v = {1, 2, 3, 4}
v.pop_back();        // v = {1, 2, 3}
v.insert(v.begin() + 1, 10);  // v = {1, 10, 2, 3}
for (int x : v) std::cout << x << " ";
```

#### `<deque>` - Двусторонняя очередь
Быстрая вставка/удаление с обоих концов. Как vector, но с поддержкой операций в начале.

**Основные методы:**
- `push_front(x)` / `push_back(x)` - добавить в начало/конец O(1)
- `pop_front()` / `pop_back()` - удалить O(1)
- `front()` / `back()` - доступ к концам

```cpp
#include <deque>
std::deque<int> d = {2, 3};
d.push_front(1);     // d = {1, 2, 3}
d.push_back(4);      // d = {1, 2, 3, 4}
int first = d.front();  // first = 1
```

#### `<list>` - Двусвязный список
Оптимален для частых вставок/удалений в середину. Нет произвольного доступа.

**Основные методы:**
- `push_back(x)` / `push_front(x)` - O(1)
- `insert(it, x)` - вставить в позицию O(1)
- `erase(it)` - удалить O(1)
- `remove(x)` - удалить все равные x

```cpp
#include <list>
std::list<int> l = {1, 2, 3};
auto it = l.begin();
++it;
l.insert(it, 10);    // l = {1, 10, 2, 3}
l.remove(10);        // l = {1, 2, 3}
```

#### `<map>` - Отсортированный словарь
Ключ-значение с автоматической сортировкой. Поиск за O(log n).

**Основные методы:**
- `insert({key, value})` / `[key] = value`
- `find(key)` - поиск ключа, возвращает итератор или end()
- `count(key)` - есть ли ключ (0 или 1)
- `erase(key)`

```cpp
#include <map>
std::map<std::string, int> m;
m["Alice"] = 25;
m["Bob"] = 30;
if (m.find("Alice") != m.end()) std::cout << "Found\n";
for (auto [key, val] : m) std::cout << key << ": " << val << "\n";
```

#### `<unordered_map>` - Быстрый словарь
Хеш-таблица. В среднем O(1) поиск, но нет сортировки.

**Основные методы:** такие же как map

```cpp
#include <unordered_map>
std::unordered_map<int, std::string> m;
m[1] = "one";
m[2] = "two";
if (m.count(1)) std::cout << m[1] << "\n";  // faster than map
```

#### `<set>` / `<unordered_set>` - Множества
set - отсортированное, unordered_set - хеш-таблица. Только уникальные значения.

```cpp
#include <set>
std::set<int> s = {3, 1, 2};  // s = {1, 2, 3} (отсортирован)
s.insert(4);
if (s.count(2)) std::cout << "2 found\n";

std::unordered_set<int> us = {3, 1, 2};  // порядок неопределен
us.insert(4);
```

#### `<queue>` / `<priority_queue>` - Очереди
queue - FIFO (первый пришел, первый ушел), priority_queue - по приоритету.

```cpp
#include <queue>
std::queue<int> q;
q.push(1); q.push(2); q.push(3);
while (!q.empty()) {
    std::cout << q.front() << " ";  // 1 2 3
    q.pop();
}

std::priority_queue<int> pq;  // max-heap по умолчанию
pq.push(3); pq.push(1); pq.push(2);
while (!pq.empty()) {
    std::cout << pq.top() << " ";  // 3 2 1
    pq.pop();
}
```

#### `<stack>` - Стек
LIFO (последний пришел, первый ушел).

```cpp
#include <stack>
std::stack<int> st;
st.push(1); st.push(2); st.push(3);
while (!st.empty()) {
    std::cout << st.top() << " ";  // 3 2 1
    st.pop();
}
```

---

### 🎯 Алгоритмы и численные операции

#### `<algorithm>` - Полный список функций

**Сортировка и поиск:**
- `sort(first, last)` - сортировка O(n log n)
- `sort(first, last, comp)` - сортировка с компаратором
- `partial_sort(first, middle, last)` - сортировка до middle элемента
- `nth_element(first, nth, last)` - найти n-й элемент как при сортировке
- `is_sorted(first, last)` - проверка, отсортирован ли диапазон
- `binary_search(first, last, val)` - поиск в отсортированном массиве (bool)
- `lower_bound(first, last, val)` - первый >= val
- `upper_bound(first, last, val)` - первый > val
- `equal_range(first, last, val)` - оба bounds одновременно

**Поиск:**
- `find(first, last, val)` - найти первое совпадение
- `find_if(first, last, pred)` - найти по условию
- `find_if_not(first, last, pred)` - найти где условие ложно
- `find_first_of(first1, last1, first2, last2)` - найти первый из second
- `search(first1, last1, first2, last2)` - найти подпоследовательность
- `search_n(first, last, count, val)` - найти count одинаковых элементов
- `find_end(first1, last1, first2, last2)` - найти последнее вхождение

**Подсчет:**
- `count(first, last, val)` - подсчитать совпадения
- `count_if(first, last, pred)` - подсчитать по условию

**Модификация:**
- `copy(first, last, dest)` - копировать
- `copy_if(first, last, dest, pred)` - копировать если условие
- `copy_backward(first, last, dest)` - копировать в обратном направлении
- `move(first, last, dest)` - переместить
- `transform(first, last, dest, op)` - трансформировать все элементы
- `fill(first, last, val)` - заполнить значением
- `fill_n(first, count, val)` - заполнить n элементов
- `generate(first, last, gen)` - заполнить результатами генератора
- `generate_n(first, count, gen)` - заполнить n элементов

**Перестановки:**
- `reverse(first, last)` - развернуть
- `rotate(first, middle, last)` - циклический сдвиг
- `reverse_copy(first, last, dest)` - развернуть в dest
- `rotate_copy(first, middle, last, dest)` - циклический сдвиг в dest
- `shuffle(first, last, gen)` - перемешать (нужен RNG)
- `next_permutation(first, last)` - следующая перестановка
- `prev_permutation(first, last)` - предыдущая перестановка

**Удаление элементов:**
- `unique(first, last)` - удалить соседние дубликаты, возвращает новый конец
- `unique_copy(first, last, dest)` - копировать без дубликатов
- `remove(first, last, val)` - "удалить" элементы (на деле сдвигает)
- `remove_if(first, last, pred)` - "удалить" по условию
- `remove_copy(first, last, dest, val)` - копировать без элементов
- `remove_copy_if(first, last, dest, pred)` - копировать без элементов по условию

**Сравнение:**
- `equal(first1, last1, first2)` - равны ли диапазоны
- `lexicographical_compare(first1, last1, first2, last2)` - лексикографическое сравнение
- `mismatch(first1, last1, first2)` - найти первое отличие

**Min/Max:**
- `min(a, b)` / `max(a, b)` - минимум/максимум двух элементов
- `min(init_list)` / `max(init_list)` - из списка инициализации
- `min_element(first, last)` - итератор на минимальный элемент
- `max_element(first, last)` - итератор на максимальный элемент
- `minmax(a, b)` - пара (min, max)
- `minmax_element(first, last)` - пара итераторов (min, max)

**Сортировка по выбору:**
- `partition(first, last, pred)` - разделить по условию
- `stable_partition(first, last, pred)` - разделить сохраняя порядок
- `partition_point(first, last, pred)` - найти точку раздела

**Другие:**
- `swap(a, b)` - поменять местами два значения
- `swap_ranges(first1, last1, first2)` - поменять два диапазона
- `replace(first, last, old, new)` - заменить все old на new
- `replace_if(first, last, pred, new)` - заменить по условию
- `replace_copy(first, last, dest, old, new)` - копировать и заменить
- `replace_copy_if(first, last, dest, pred, new)` - копировать и заменить по условию
- `sample(first, last, out, k, gen)` - выбрать k случайных элементов (C++17)

```cpp
#include <algorithm>
#include <vector>

std::vector<int> v = {3, 1, 4, 1, 5, 9, 2, 6};

// Сортировка
std::sort(v.begin(), v.end());  // v = {1, 1, 2, 3, 4, 5, 6, 9}

// Поиск
auto it = std::find(v.begin(), v.end(), 4);
if (it != v.end()) std::cout << "Found at " << std::distance(v.begin(), it) << "\n";

// Подсчет
int count = std::count(v.begin(), v.end(), 1);  // count = 2

// Трансформация
std::vector<int> v2(v.size());
std::transform(v.begin(), v.end(), v2.begin(), [](int x) { return x * 2; });

// Удаление дубликатов
auto last = std::unique(v.begin(), v.end());
v.erase(last, v.end());  // v = {1, 2, 3, 4, 5, 6, 9}

// Развертывание
std::reverse(v.begin(), v.end());

// Минимум/максимум
int min_val = *std::min_element(v.begin(), v.end());
int max_val = *std::max_element(v.begin(), v.end());
```

#### `<numeric>` - Численные операции

**Базовые численные функции:**
- `std::accumulate(first, last, init)` - сумма всех элементов (init + x1 + x2 + ...)
- `std::accumulate(first, last, init, op)` - аккумуляция с операцией op
- `std::iota(first, last, value)` - заполнить последовательностью от value
- `std::inner_product(first1, last1, first2, init)` - скалярное произведение
- `std::inner_product(first1, last1, first2, init, op1, op2)` - обобщенное произведение
- `std::adjacent_difference(first, last, dest)` - разности соседних элементов
- `std::adjacent_difference(first, last, dest, op)` - с операцией op
- `std::partial_sum(first, last, dest)` - префиксные суммы
- `std::partial_sum(first, last, dest, op)` - с операцией op
- `std::gcd(m, n)` - наибольший общий делитель (C++17)
- `std::lcm(m, n)` - наименьшее общее кратное (C++17)

**Численные функции (C++17):**
- `std::reduce(first, last, init)` - параллельная сумма
- `std::reduce(first, last, init, op)` - с операцией
- `std::transform_reduce(first, last, first2, init, op1, op2)` - трансформ + редукция
- `std::exclusive_scan(first, last, dest, init, op)` - префиксная сумма без текущего
- `std::inclusive_scan(first, last, dest, op)` - префиксная сумма с текущим
- `std::transform_exclusive_scan(first, last, dest, init, op1, op2)` - трансформ + exclusive
- `std::transform_inclusive_scan(first, last, dest, op1, op2)` - трансформ + inclusive

```cpp
#include <numeric>
#include <vector>

std::vector<int> v = {1, 2, 3, 4, 5};

// Сумма всех элементов
int sum = std::accumulate(v.begin(), v.end(), 0);  // sum = 15

// Произведение всех элементов
int product = std::accumulate(v.begin(), v.end(), 1, std::multiplies<int>());  // 120

// Заполнение последовательностью
std::vector<int> seq(5);
std::iota(seq.begin(), seq.end(), 10);  // seq = {10, 11, 12, 13, 14}

// Скалярное произведение
std::vector<int> a = {1, 2, 3};
std::vector<int> b = {4, 5, 6};
int dot = std::inner_product(a.begin(), a.end(), b.begin(), 0);  // 1*4 + 2*5 + 3*6 = 32

// Префиксные суммы
std::vector<int> v2 = {1, 2, 3, 4};
std::vector<int> prefix(4);
std::partial_sum(v2.begin(), v2.end(), prefix.begin());  // prefix = {1, 3, 6, 10}

// Разности соседних
std::vector<int> v3 = {1, 3, 6, 10};
std::vector<int> diffs(4);
std::adjacent_difference(v3.begin(), v3.end(), diffs.begin());  // diffs = {1, 2, 3, 4}

// НОД и НОК (C++17)
int g = std::gcd(48, 18);  // g = 6
int l = std::lcm(12, 18);  // l = 36
```

---

### 📤 Ввод/вывод

#### `<iostream>` - Консоль
```cpp
#include <iostream>

std::cout << "Output\n";
std::cerr << "Error\n";
std::clog << "Log\n";

int x;
std::cin >> x;
std::cin >> x >> y >> z;

// Чтение строки со пробелами
std::string line;
std::getline(std::cin, line);
```

#### `<fstream>` - Файлы
```cpp
#include <fstream>

// Чтение
std::ifstream in("file.txt");
std::string line;
while (std::getline(in, line)) {
    std::cout << line << "\n";
}
in.close();

// Запись
std::ofstream out("file.txt");
out << "Hello, World!\n";
out.close();

// Чтение и запись
std::fstream f("file.txt", std::ios::in | std::ios::out);
```

#### `<sstream>` - Строковые потоки
```cpp
#include <sstream>

// Парсинг
std::string s = "123 456 789";
std::istringstream iss(s);
int a, b, c;
iss >> a >> b >> c;  // a=123, b=456, c=789

// Форматирование
std::ostringstream oss;
oss << "x=" << 42 << ", y=" << 3.14;
std::string result = oss.str();  // "x=42, y=3.14"

// Преобразование
int num = 42;
std::string str = std::to_string(num);  // "42"
int val = std::stoi("123");  // 123
```

#### `<iomanip>` - Форматирование
```cpp
#include <iomanip>
#include <iostream>

std::cout << std::setprecision(2) << 3.14159 << "\n";  // 3.1
std::cout << std::fixed << std::setprecision(2) << 3.14159 << "\n";  // 3.14
std::cout << std::setw(10) << "hello" << "\n";  // "     hello" (ширина 10)
std::cout << std::left << std::setw(10) << "hello" << "\n";  // "hello     "
std::cout << std::hex << 255 << "\n";  // ff
std::cout << std::oct << 8 << "\n";    // 10
std::cout << std::scientific << 1000.0 << "\n";  // 1.000000e+03
```

---

### 🧠 Память и указатели

#### `<memory>` - Умные указатели
```cpp
#include <memory>

// unique_ptr - исключительное владение
std::unique_ptr<int> ptr1 = std::make_unique<int>(42);
// ptr1 автоматически удалится когда выйдет из области видимости

// shared_ptr - совместное владение
std::shared_ptr<int> ptr2 = std::make_shared<int>(10);
std::shared_ptr<int> ptr3 = ptr2;  // оба указывают на одно значение
// удалится когда последний shared_ptr выйдет из области видимости

// Проверка
if (ptr1) std::cout << *ptr1 << "\n";
```

---

### 🎲 Время и случайность

#### `<chrono>` - Время
```cpp
#include <chrono>
#include <iostream>

// Измерение времени
auto start = std::chrono::high_resolution_clock::now();
// код
auto end = std::chrono::high_resolution_clock::now();
auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
std::cout << "Time: " << elapsed.count() << "ms\n";

// Работа с временем
auto now = std::chrono::system_clock::now();
auto time = std::chrono::system_clock::to_time_t(now);
```

#### `<random>` - Случайные числа
```cpp
#include <random>
#include <iostream>

// Инициализация генератора
std::mt19937 gen(std::random_device{}());  // Mersenne Twister

// Целые числа [1, 100]
std::uniform_int_distribution<> dis(1, 100);
for (int i = 0; i < 5; ++i) {
    std::cout << dis(gen) << " ";
}

// Вещественные числа [0.0, 1.0)
std::uniform_real_distribution<> dis_real(0.0, 1.0);
for (int i = 0; i < 5; ++i) {
    std::cout << dis_real(gen) << " ";
}

// Нормальное распределение (среднее=0, стд.откл=1)
std::normal_distribution<> dis_norm(0.0, 1.0);
```

---

### 📦 Утилиты

#### `<utility>` - Парки и утилиты
```cpp
#include <utility>

// Пара
std::pair<int, std::string> p = {10, "hello"};
std::cout << p.first << ", " << p.second << "\n";

// или
std::pair<int, std::string> p = std::make_pair(10, "hello");

// Swap
int a = 5, b = 10;
std::swap(a, b);  // a=10, b=5
```

#### `<tuple>` - Кортежи
```cpp
#include <tuple>

// Создание кортежа с тремя элементами разных типов
std::tuple<int, std::string, double> t = {42, "hello", 3.14};

// Получение значений
int x = std::get<0>(t);      // 42
std::string s = std::get<1>(t);  // "hello"
double d = std::get<2>(t);   // 3.14

// С структурированным связыванием (C++17)
auto [x, s, d] = t;
```

#### `<optional>` - Опциональное значение (C++17)
```cpp
#include <optional>
#include <iostream>

std::optional<int> maybe_value;

// Проверка
if (maybe_value.has_value()) {
    std::cout << maybe_value.value() << "\n";
} else {
    std::cout << "No value\n";
}

// Присваивание
maybe_value = 42;
if (maybe_value) {  // или maybe_value.has_value()
    std::cout << *maybe_value << "\n";
}
```

#### `<variant>` - Дискриминированное объединение (C++17)
```cpp
#include <variant>
#include <iostream>

// Может быть int или std::string
std::variant<int, std::string> v = 42;

if (std::holds_alternative<int>(v)) {
    std::cout << std::get<int>(v) << "\n";
}

v = "hello";
if (std::holds_alternative<std::string>(v)) {
    std::cout << std::get<std::string>(v) << "\n";
}

// Visitor pattern
std::visit([](auto&& arg) {
    std::cout << arg << "\n";
}, v);
```

#### `<any>` - Любой тип (C++17)
```cpp
#include <any>
#include <iostream>

std::any a = 42;
std::cout << std::any_cast<int>(a) << "\n";  // 42

a = "hello";
std::cout << std::any_cast<const char*>(a) << "\n";  // hello

// Проверка типа
if (a.type() == typeid(int)) {
    std::cout << "It's int\n";
}
```

---

### 🔌 Функциональное программирование

#### `<functional>` - Функции и функторы
```cpp
#include <functional>
#include <algorithm>
#include <vector>

std::vector<int> v = {3, 1, 4, 1, 5};

// Сравниватели
std::sort(v.begin(), v.end(), std::greater<int>());  // {5, 4, 3, 1, 1}

// std::function для хранения функций
std::function<int(int, int)> add = [](int a, int b) { return a + b; };
int result = add(2, 3);  // 5

// std::bind для частичного применения (C++11)
auto multiply_by_2 = std::bind(std::multiplies<int>(), std::placeholders::_1, 2);
result = multiply_by_2(5);  // 10

// Функторы
struct Multiplier {
    int factor;
    int operator()(int x) const { return x * factor; }
};

std::vector<int> v2(v.size());
std::transform(v.begin(), v.end(), v2.begin(), Multiplier{10});  // каждый *10
```

---

### ⚠️ Обработка ошибок

#### `<exception>` и `<stdexcept>` - Исключения
```cpp
#include <exception>
#include <stdexcept>
#include <iostream>

try {
    throw std::invalid_argument("Bad argument!");
} catch (const std::invalid_argument& e) {
    std::cerr << "Caught: " << e.what() << "\n";
} catch (const std::exception& e) {
    std::cerr << "Generic exception: " << e.what() << "\n";
} catch (...) {
    std::cerr << "Unknown exception\n";
}

// Стандартные исключения:
// std::invalid_argument - неверный аргумент
// std::runtime_error - ошибка во время выполнения
// std::out_of_range - индекс вне диапазона
// std::logic_error - логическая ошибка
// std::length_error - слишком большой размер
```

---

### 🔍 Информация о типах

#### `<typeinfo>` и `<limits>`
```cpp
#include <typeinfo>
#include <limits>
#include <iostream>

int x = 42;

// Информация о типе во время выполнения
std::cout << typeid(x).name() << "\n";  // "i" (обычно)
std::cout << typeid(x).name() == typeid(int).name() << "\n";  // 1

// Границы типов
std::cout << std::numeric_limits<int>::max() << "\n";    // 2147483647
std::cout << std::numeric_limits<int>::min() << "\n";    // -2147483648
std::cout << std::numeric_limits<double>::epsilon() << "\n";  // минимальное различие
std::cout << std::numeric_limits<float>::digits << "\n";  // количество бит мантиссы
```

---

## 🚀 Примеры использования

#### Решение задач со списками:
```cpp
#include <vector>
#include <algorithm>
#include <numeric>

std::vector<int> v = {1, 2, 3, 4, 5};

// Сумма четных элементов
int sum = 0;
for (int x : v) {
    if (x % 2 == 0) sum += x;
}

// или с алгоритмами
int sum2 = std::accumulate(
    v.begin(), v.end(), 0,
    [](int acc, int x) { return x % 2 == 0 ? acc + x : acc; }
);
```

#### Парсинг данных:
```cpp
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

std::ifstream file("data.txt");
std::vector<int> numbers;

std::string line;
while (std::getline(file, line)) {
    std::istringstream iss(line);
    int num;
    while (iss >> num) {
        numbers.push_back(num);
    }
}
```

#### Сортировка объектов:
```cpp
#include <vector>
#include <algorithm>

struct Person {
    std::string name;
    int age;
};

std::vector<Person> people = {
    {"Alice", 30},
    {"Bob", 25},
    {"Charlie", 35}
};

// Сортировка по возрасту
std::sort(people.begin(), people.end(),
    [](const Person& a, const Person& b) {
        return a.age < b.age;
    }
);
```
