#include <bits/stdc++.h>
#include "SquareSystem.hpp"

using namespace std;

int main() {
    vector <int> size = {5,5};
    SquareSystem model(size,0.05);
    ofstream data("data_5.txt");
    if (!data.is_open()) {
        cout << "error" << endl;
        return 0;
    }
    for (int i=1; i<=80; i++) {
        double temp= i*0.05;
        model.set_observables(1/temp);
        data << temp << "\t" << model._internal_energy() << "\t" << model._specific_heat() << "\t" << model._squared_magnetization() << endl;
    }
    data.close();
}
