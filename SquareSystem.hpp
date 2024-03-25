#ifndef SQUARESYSTEM_HPP
#define SQUARESYSTEM_HPP

#include <bits/stdc++.h>
#include "Ising_system.hpp"

using namespace std;

class SquareSystem : public IsingSystem {
private:
    vector <int> SystemSize;
    void set_system_square_neighbors() {
        for (int i=0; i<spins_number; i++) {
            vector <int> pin = coordinate(i);
            spin[i].set_neighbor(index(square_neighbor(pin,0,1)),0);
            spin[i].set_neighbor(index(square_neighbor(pin,1,1)),1);
            spin[i].set_neighbor(index(square_neighbor(pin,0,-1)),2);
            spin[i].set_neighbor(index(square_neighbor(pin,1,-1)),3);
            // bond index in square system as below
            /*                  neighbor[1]             *
             *       neighbor[2]    i   neighbor[0]     *
             *                  neighbor[3]             */
        }
    };
    double GroundStateEnergy;
    double beta;
    double PartitionFunction=0;
    double InternalEnergy=0;
    double SpecificHeat=0;
    double SquaredMagnetization=0;

public:
    SquareSystem(const vector <int> SystemSize, double temperature) : IsingSystem(SystemSize[0]*SystemSize[1]), SystemSize(SystemSize), beta(temperature) {
        set_system_square_neighbors();
        GroundStateEnergy = J*SystemSize[0]*SystemSize[1]*2;
        set_observables(beta);
    };
    ~SquareSystem() {};
    int index(const vector <int> coordinate) const {
        return coordinate[0]+SystemSize[0]*coordinate[1];
    };
    vector <int> coordinate(int index) const {
        return {index % SystemSize[0], index / SystemSize[0]};
    };
    vector <int> square_neighbor(vector <int> coordinate, int axis, int sgn) const{
        assert(sgn==1 || sgn==-1);
        coordinate[axis] = (coordinate[axis]+sgn) % SystemSize[axis];
        return coordinate;
    };
    int eval_square_magnetization() {
        int magnetization = 0;
        for (int i=0; i<spins_number; i++) {
            magnetization += spin[i]._SpinValue();
        }
        return magnetization;
    };
    double eval_square_energy() {
        double energy = 0;
        for (int i=0; i<spins_number; i++) {
            energy += spin[i]._SpinValue()*spin[neighbor_spin_index(i,0)]._SpinValue()*J;
            energy += spin[i]._SpinValue()*spin[neighbor_spin_index(i,1)]._SpinValue()*J;
        }
        return energy;
    };
    double eval_square_weight() {
        double weight = exp(-1*beta*eval_square_energy());
        return weight;
    };
    void set_observables(double b) {
        beta = b;
        PartitionFunction = 0;
        double energy_sum=0;
        double SquaredEnergy_sum=0;
        double SquaredMagnetization_sum=0;
        for (long long code=0; code<=max_stats_number; code++) {
            set_state_by_code(code);
            double RelativeEnergy = eval_square_energy()-GroundStateEnergy;
            double weight = exp(-1*beta*RelativeEnergy);
            PartitionFunction += weight;
            energy_sum += RelativeEnergy * weight;
            SquaredMagnetization_sum += pow(eval_square_magnetization(),2) * weight;
            SquaredEnergy_sum += pow(RelativeEnergy,2) * weight;
        }
        InternalEnergy = energy_sum/PartitionFunction;
        SpecificHeat = beta*beta*(SquaredEnergy_sum/PartitionFunction-InternalEnergy*InternalEnergy);
        SquaredMagnetization = SquaredMagnetization_sum/PartitionFunction;
    };
    vector <double> eval_each_energy_by_code() {
        vector <double> hamiltonian = {};
        for (long long code=0; code<=max_stats_number; code++) {
            set_state_by_code(code);
            hamiltonian.push_back(eval_square_energy()-GroundStateEnergy);
        }
        return hamiltonian;
    }
    vector <double> eval_each_squared_magnetization_by_code() {
        vector <double> SquaredMagnetizaition = {};
        for (long long code=0; code<=max_stats_number; code++) {
            SquaredMagnetizaition.push_back(pow(eval_square_magnetization(),2));
        }
        return SquaredMagnetizaition;
    }

    double _internal_energy() const {return InternalEnergy; };
    double _specific_heat() const {return SpecificHeat; };
    double _squared_magnetization() const {return SquaredMagnetization; };
    double _partition_function() {return PartitionFunction; };
};

#endif