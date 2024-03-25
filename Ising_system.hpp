#ifndef ISINGSYSTEM_HPP
#define ISINGSYSTEM_HPP

#include "SpinLattice.hpp"
#include <bits/stdc++.h>

using namespace std;

class IsingSystem {
protected:
    double J;
    const int spins_number;
    const long long max_stats_number;
    vector <SpinLattice> spin;

public:
    IsingSystem(const int spins_num) : J(-1.0), spins_number(spins_num), max_stats_number(pow(2,spins_number)-1) {
        spin.resize(spins_number);
    };
    ~IsingSystem() {};
    void set_state_by_code(long long code_state) {
        for (int i=0; i<spins_number; i++) {
            if (code_state % 2 == 0) spin[i].set_down();
            else spin[i].set_up();
            code_state /= 2;
        }
    }
    void eval_magnetization() {
        int magnetization = 0;
        for (int i=0; i<spins_number; i++) {
            magnetization += spin[i]._SpinValue();
        }
        cout << "system magnetization: " << magnetization << endl;
    }
    int value_magnetization() {
        int magnetization = 0;
        for (int i=0; i<spins_number; i++) {
            magnetization += spin[i]._SpinValue();
        }
        return magnetization;
    }
    void eval_energy() {
        double energy = 0;
        for (int i=0; i<spins_number-1; i++) {
            energy += spin[i]._SpinValue()*spin[i+1]._SpinValue()*J;
        }
        energy += spin[0]._SpinValue()*spin[spins_number-1]._SpinValue()*J;
        cout << "system energy: " << energy << endl;
    }
    double value_energy() {
        double energy = 0;
        for (int i=0; i<spins_number-1; i++) {
            energy += spin[i]._SpinValue()*spin[i+1]._SpinValue()*J;
        }
        energy += spin[0]._SpinValue()*spin[spins_number-1]._SpinValue()*J;
        return energy;
    }
    int system_size() const {return spins_number; };
    int max_state_number() const {return max_stats_number; };
    void set_up_spin(const int index) {spin[index].set_up(); };
    void set_down_spin(const int index) {spin[index].set_down(); };
    void flip_spin(const int index) {spin[index].flip(); };
    int value_spin(const int index) {return spin[index]._SpinValue(); };
    void set_dim(int dim) {for (auto& each: spin) each.set_dim(dim); };
    vector <int> position_spin(const int index) const {return spin[index]._position(); };
    vector <int> neighbor_spin_index(const int index) const {return spin[index]._neighbor(); };
    int neighbor_spin_index(const int index, const int bond_index) const {return spin[index]._neighbor(bond_index);};
    void set_state_by_index(vector <bool> index_state) {
        int state_size = index_state.size();
        assert(state_size == spins_number);
        for (int i=0; i<spins_number; i++) {
            if (index_state[i]) spin[i].set_up();
            else spin[i].set_down();
        }
    }

};

#endif