#include "IsingSpin.hpp"
#include <bits/stdc++.h>

using namespace std;

class IsingSystem {
private:
    const double J = -1.0;
    const int spins_number;
    const long long max_stats_number;
    vector <IsingSpin> spin;

public:
    IsingSystem(const int spins_num) : spins_number(spins_num), max_stats_number(pow(2,spins_number)-1) {
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
    void eval_energy() {
        double energy = 0;
        for (int i=0; i<spins_number-1; i++) {
            energy += spin[i]._SpinValue()*spin[i+1]._SpinValue()*J*-1;
        }
        energy += spin[0]._SpinValue()*spin[spins_number-1]._SpinValue()*J*-1;
        cout << "system energy: " << energy << endl;
    }
};
int main() {
    IsingSystem system(10);
    system.set_state_by_code(7);
    system.eval_magnetization();
    system.eval_energy();
    system.set_state_by_code(77);
    system.eval_magnetization();
    system.eval_energy();
    system.set_state_by_code(777);
    system.eval_magnetization();
    system.eval_energy();

}
