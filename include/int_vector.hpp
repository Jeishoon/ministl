#ifndef INT_VECTOR_H
#define INT_VECTOR_H

#include <cstddef>

class IntVector
{
private:
    std::size_t m_size{};
    std::size_t m_capacity{};
    int* m_int_list{};
    static constexpr std::size_t k_growth_factor{2};

public:
    IntVector();
    ~IntVector();

    std::size_t size() const;
    std::size_t capacity() const;

    int& operator[](std::size_t i);
    const int& operator[](std::size_t i) const;

    int& at(std::size_t i);
    const int& at(std::size_t i) const;

    void push_back(int n);
};

#endif