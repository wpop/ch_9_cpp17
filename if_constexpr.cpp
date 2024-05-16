#include <iostream>
#include <type_traits>
#include <string>
#include <cstddef>

template<typename T>
T abs(T n) {
    if (n >= 0) return n;
    return -n;
}

// --------------------- SFINAE --------------------
template<typename T>
std::enable_if<std::is_floating_point_v<T>, bool> 
nearly_equal(T n1, T n2)
{
    // in case if T type is a float or double
    return abs(n1 - n2) < static_cast<T>(0.000001);
}

template<typename T>
std::enable_if<!std::is_floating_point_v<T>, bool>
nearly_equal(T n1, T n2)
{
    // in case if T has an integer type
    return n1 == n2;
}

// ------------------- if constexpr ----------------

template<typename T>
bool nearly_equal_3(T n1, T n2) 
{
    if constexpr(std::is_floating_point_v<T>)
    {
        return abs(n1 - n2) < static_cast<T>(0.000001);
    }
    else
    {
        return n1 == n2;
    }
}

// receives a param and returns it as a string
template<typename T>
std::string str_convrt(T const& t)
{
    if constexpr (std::is_convertible_v<T, std::string>)
    {
        return t;
    }
    else 
    {
        return std::to_string(t);
    }
}

// ------------------ Main -----------------
int main()
{
    // auto res_eq = nearly_equal_3<int, int>(2, 2);
    // std::cout << nearly_equal<int, int>(2, 2);
    std::cout << str_convrt(3.14159) << std::endl;
    std::cout << str_convrt("AbracadabrA") << std::endl;

    return 0;
}