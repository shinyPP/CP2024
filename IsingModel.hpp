#include <bits/stdc++.h>
using namespace std;
class IsingSpin {
private:
    int SpinValue;

public:
    IsingSpin() {SpinValue = 1;};
    ~IsingSpin() {};

    int _SpinValue() const {return SpinValue;};
    void set_up() {SpinValue = 1;};
    void set_down() {SpinValue = -1;};
    void flip() {SpinValue = -1 * SpinValue;};
};