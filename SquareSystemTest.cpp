#include "SquareSystem.hpp"
#include <iostream>
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>



TEST_CASE("SquareIsingSystem","[examples of 6 by 6 lattices") {
    const vector <int> system_size = {6,6};
    SquareSystem model(system_size, 1);
    vector <bool> state = {1,1,0,1,1,1,0,0,1,1,1,0,1,1,1,1,0,1,0,0,0,0,0,0,1,1,0,1,0,1,1,1,0,0,0,0};
    vector <double> beta = {0.1,1.0,2.0};
    constexpr double energy = -4.0;
    constexpr int magz = 2;
    constexpr double w0 = 1.491824697641270;
    constexpr double w1 = 54.59815003314424;
    constexpr double w2 = 2980.957987041728;
    constexpr double w[3] = {w0,w1,w2};

    SECTION("pi state: magnetization and energy and Boltzmann weight") {
        model.set_state_by_index(state);
        REQUIRE(model.eval_square_magnetization() == magz);
        REQUIRE_THAT(model.eval_square_energy(), Catch::Matchers::WithinULP(energy,4));
        for (int i=0; i<3; i++) {
            REQUIRE_THAT(model.eval_square_weight(beta[i]), Catch::Matchers::WithinULP(w[i],4));
        }
    };

};