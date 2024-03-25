#include "SquareSystem.hpp"
#include <iostream>
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>



TEST_CASE("CanonicalEnsembleOfSquareIsingSystem","[examples of 2 by 2 lattices") {
    vector <int> system_size = {2,2};
    SquareSystem two(system_size,1);

    SECTION("pi state: magnetization and energy and Boltzmann weight") {
        REQUIRE_THAT(two._internal_energy(), Catch::Matchers::WithinRel(0.01607165625,0.0001));
        REQUIRE_THAT(two._specific_heat(), Catch::Matchers::WithinRel(0.1283293275,0.0001));
        REQUIRE_THAT(two._squared_magnetization(), Catch::Matchers::WithinRel(15.9732151,0.0001));
    };
};