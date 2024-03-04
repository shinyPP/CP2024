#include <bits/stdc++.h>
using namespace std;
class IsingSpin {
private:
    int SpinValue;

public:
    IsingSpin() {SpinValue = 1;}
    ~IsingSpin() {};

    int _SpinValue() const {return SpinValue;}
    void set_up() {SpinValue = 1;}
    void set_down() {SpinValue = -1;}

};

int main() {
    IsingSpin spin;
    cout << "Initial spin value: " << spin._SpinValue() << endl;
    spin.set_up();
    cout << "Upped spin value: " << spin._SpinValue() << endl;
    spin.set_down();
    cout << "Downed spin value: " << spin._SpinValue() << endl;
}
