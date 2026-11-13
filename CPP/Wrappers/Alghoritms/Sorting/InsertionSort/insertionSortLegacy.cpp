#include <cstdlib> // for size_t

template <typename T, size_t len>
void InsertionSort(T (&arr)[len]) {
    for (size_t i = 1; i < len; ++i) { // все что перед i - отсортированная часть
        T temp = arr[i]; // сохраняем значение чтобы не потерять при сдвиге

        size_t searcher = i; // поисковик, ищем им место для вставки
        while (searcher > 0 && arr[searcher - 1] > temp) { // идем пока не дойдем до границы / элемент перед больше чем таргетный
            arr[searcher] = arr[searcher - 1]; // сдвигаем на один полностью отсортированную часть
            --searcher; // двигаемся влево
        }
        arr[searcher] = temp; // вставляем вместо того элемента наш таргетный, поэтому мы его и сохраняли (он был заменен изначально изза сдвига)
    }
}
