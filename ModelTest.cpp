#include "IsingSpin.hpp"
#include <iostream>
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>

TEST_CASE("IsingSpin", "[single spin]") {
    IsingSpin spin;

    SECTION("spin state (initial)") {
        REQUIRE(spin._SpinValue() == 1);
    }
    SECTION("set spin state as up") {
        spin.set_up();
        REQUIRE(spin._SpinValue() == 1);
    }
    SECTION("set spin state as down") {
        spin.set_down();
        REQUIRE(spin._SpinValue() == -1);
    }
};
