#include <bits/stdc++.h>
using namespace std;

int fibonacci(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    int ff = 0;
    int f = 1;
    int ans;
    for (int i = 2; i <= n; i++) {
        ans = ff + f;
        ff = f;
        f = ans;
    }
    return ans;
}
int main() {
    cout << fibonacci(7) << endl;
    cout << fibonacci(15) << endl;
    cout << fibonacci(31) << endl;
}