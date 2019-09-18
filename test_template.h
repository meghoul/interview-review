#include <iostream>
#include <type_traits>

template<typename T>
typename std::enable_if<std::is_integral<T>::value, bool>::type is_odd(T i)
{
    return bool(i%2);
}

template <typename T, typename = typename std::enable_if<std::is_integral<T>::value>::type>
bool is_even(T i)
{
    return !bool(i%2);
}

// 通用模板，使用它时没有‘type’类型，所以编译会检查报错
template <bool B, typename T = void>
struct test_enable_if{ };

template <typename T>
struct test_enable_if<true, T>
{
    typedef T type;
};

template<typename T>
typename test_enable_if<std::is_integral<T>::value, bool>::type is_odd_test(T i)
{
    return bool(i%2);
}

struct TTest{};

template<int A, typename = void >
struct TA
{
        int a = A;
};