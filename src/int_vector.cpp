#include <stdexcept>

#include "int_vector.hpp"

IntVector::IntVector():
    m_size{ 0 },
    m_capacity{ 0 }
{
}

IntVector::~IntVector()
{
    delete[] m_int_list;
}

std::size_t IntVector::size() const
{
    return m_size;
}

std::size_t IntVector::capacity() const
{
    return m_capacity;
}

int& IntVector::operator[](std::size_t i) 
{
    return m_int_list[i];
}

const int& IntVector::operator[](std::size_t i) const
{
    return m_int_list[i];
}

int& IntVector::at(std::size_t i)
{
    if (i >= m_size) {
        throw std::out_of_range("IntVector::at: index out of range");
    }
    return m_int_list[i];
}

const int& IntVector::at(std::size_t i) const
{
    if (i >= m_size) {
        throw std::out_of_range("IntVector::at: index out of range");
    }
    return m_int_list[i];
}

void IntVector::push_back(int n)
{
    if (m_size == m_capacity) {
        std::size_t new_capacity = m_capacity == 0 ? 1 : m_capacity * k_growth_factor;
        int* new_int_list{ new int[new_capacity] };

        for (std::size_t i = 0; i < m_size; i++) {
            new_int_list[i] = m_int_list[i];
        }
        
        delete[] m_int_list;
        m_int_list = new_int_list;
        m_capacity = new_capacity;

    }

    m_int_list[m_size] = n;
    m_size++;
}