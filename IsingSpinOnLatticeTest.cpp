#include "SquareSystem.hpp"
#include <iostream>
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>

TEST_CASE("IsingSpinOnLattice", "[single spin]") {
    SpinLattice spin;
    SECTION("spin position (initial)") {
        constexpr int dim = 2;
        spin.set_dim(dim);
        REQUIRE(spin._position() == vector <int> ({0,0}));
        REQUIRE(spin._neighbor() == vector <int> ({-1}));
        REQUIRE(spin._neighbor(0) == -1);
    }
};

TEST_CASE("IsingSpinOnLattice", "[system size]") {
    const vector <int> system_size = {6,6};
    SquareSystem model(system_size, 1);
    SECTION("basics") {
        REQUIRE(model.system_size() == 36);
    };
    SECTION("site index") {
        const vector <int> lattice_coordinate = {3,4};
        REQUIRE(model.index(lattice_coordinate) == 27);
        REQUIRE(model.coordinate(27) == lattice_coordinate);
    };
    SECTION("connectivity") {
        constexpr int i=21;
        REQUIRE(model.neighbor_spin_index(i,0) == 22);
    };
};