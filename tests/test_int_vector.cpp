#include <stdexcept>
#include <catch2/catch_test_macros.hpp>

#include "int_vector.hpp"

TEST_CASE("push element to vector increases size", "[int_vector]")
{
    IntVector v;
    REQUIRE(v.size() == 0);
    v.push_back(1);
    REQUIRE(v.size() == 1);
}

TEST_CASE("vector capacity doubled when reached", "[int_vector]")
{
    IntVector v;
    REQUIRE(v.capacity() == 0);
    v.push_back(1);
    REQUIRE(v.capacity() == 1);
    v.push_back(2);
    REQUIRE(v.capacity() == 2);
    v.push_back(3);
    REQUIRE(v.capacity() == 4);
}

TEST_CASE("vector subscript and at checks", "[int_vector]")
{
    IntVector v;
    for (std::size_t i = 0; i < 1000; ++i) {
        v.push_back(static_cast<int>(i * 10));
    }
    
    SECTION("subscript and at accesses are correct") 
    {
        for (std::size_t i = 0; i < 1000; ++i) {
            REQUIRE(v.at(i) == static_cast<int>(i * 10));
            REQUIRE(v[i] == static_cast<int>(i * 10));
        }
    }

    SECTION("subscript modification changes correct index") 
    {
        REQUIRE(v[2] == 2 * 10);
        v[2] = 6;
        for (std::size_t i = 0; i < 1000; ++i) {
            if (i == 2) {
                REQUIRE(v[i] == 6);
            } else {
                REQUIRE(v[i] == static_cast<int>(i * 10));
            }
            
        }
    }

    SECTION("at throws out of bounds error for invalid index access") 
    {
        REQUIRE_THROWS_AS(v.at(v.size()), std::out_of_range);
        REQUIRE_THROWS_AS(v.at(1001), std::out_of_range);
    }
    
    SECTION("access through const reference still correct")
    {
        const IntVector& const_v = v;
        for (std::size_t i = 0; i < 1000; ++i) {
            REQUIRE(const_v.at(i) == static_cast<int>(i * 10));
            REQUIRE(const_v[i] == static_cast<int>(i * 10));
        }
    }

}