#include <optional> // for optional values return

template<typename T, size_t len>
std::optional<size_t> LinearSearch(const T (&arr)[len], const T& target) {
    for (size_t i = 0; i < len; ++i) {
        if (arr[i] == target) { return i; }
    }

    return std::nullopt;
}
