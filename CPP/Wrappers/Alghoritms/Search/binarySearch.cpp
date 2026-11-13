#include <optional>  // for optional value return
#include <type_traits>  // for allowing all int / float types

template<typename T, size_t len, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
std::optional<int> BinarySearch(const T (&arr)[len], const T& target) {
    size_t left = 0, right = len - 1, mid;

    while (left < right) {
        mid = left + ((right - left) / 2);
        if (target == arr[mid]) { return mid; }
        else if (target < arr[mid]) {
            right = mid; // включаем mid в диапазон чтобы не получить underflow
        }
        else {
            left = mid + 1;
        }
    }

    return std::nullopt;
}
