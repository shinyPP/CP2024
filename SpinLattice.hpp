#ifndef SPINLATTICE_HPP
#define SPINLATTICE_HPP

#include <bits/stdc++.h>
#include "IsingSpin.hpp"
using  namespace std;
class SpinLattice : public IsingSpin {
private:
    vector <int> position;
    vector <int> neighbor;

public:
    SpinLattice() {
        set_dim(1);
        neighbor = {-1};
    }
    ~SpinLattice(){};
    void set_dim(int dim) {
        position.assign(dim,0);
    };
    vector <int> _position() const { return position; };
    vector <int> _neighbor() const { return neighbor; };
    int _neighbor(const int bond_index) const { return neighbor[bond_index]; };
    void set_neighbor(const int index, const int bond_index) {neighbor[bond_index] = index; };

};

#endif