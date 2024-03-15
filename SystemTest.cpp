#include "Ising_system.hpp"
#include <iostream>
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>

TEST_CASE("IsingSpin", "[single spin]") {
    IsingSpin spin;

    SECTION("initial spin state") {
        REQUIRE(spin._SpinValue() == 1);
    }
    SECTION("set spin state up") {
        spin.set_up();
        REQUIRE(spin._SpinValue() == 1);
    }
    SECTION("set spin state down") {
        spin.set_down();
        REQUIRE(spin._SpinValue() == -1);
    }
    SECTION("flip spin once") {
        spin.flip();
        REQUIRE(spin._SpinValue() == -1);
    }
    SECTION("flip spin twice") {
        spin.flip();
        spin.flip();
        REQUIRE(spin._SpinValue() == 1);
    }
};

TEST_CASE("IsingSystem", "10 spins array") {
    IsingSystem array(10);

    SECTION("initial system size") {
        REQUIRE(array.system_size() == 10);
    }
    SECTION("initial system spin state") {
        for (int i=0; i<10; i++) {
            REQUIRE(array.value_spin(i) == 1);
        }
    }
    /*SECTION("set state by index") {
        for (int i=0; i<10; i++) {
            array.set_up_spin(i);
            REQUIRE(array.value_spin(i) == 1);
            array.set_down_spin(i);
            REQUIRE(array.value_spin(i) == -1);
        }
    }*/
    SECTION("flip state by index") {
        for (int i=0; i<10; i++) {
            array.flip_spin(i);
            REQUIRE(array.value_spin(i) == -1);
            array.flip_spin(i);
            REQUIRE(array.value_spin(i) == 1);
        }
    }
    SECTION("set state by code #7") {
        array.set_state_by_code(7);
        for (int i=0; i<3; i++) {
            REQUIRE(array.value_spin(i) == 1);
        }
        for (int i=3; i<10; i++) {
            REQUIRE(array.value_spin(i) == -1);
        }
        REQUIRE(array.value_magnetization() == -4);
        REQUIRE(array.value_energy() == 6);
    }
    SECTION("set state by code #255") {
        array.set_state_by_code(255);
        for (int i=0; i<8; i++) {
            REQUIRE(array.value_spin(i) == 1);
        }
        for (int i=8; i<10; i++) {
            REQUIRE(array.value_spin(i) == -1);
        }
        REQUIRE(array.value_magnetization() == 6);
        REQUIRE(array.value_energy() == 6);
    }
};
