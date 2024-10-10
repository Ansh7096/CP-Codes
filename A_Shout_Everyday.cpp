#include <iostream>
using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;

   
    bool z = false;

    if (B < C) {
        
        if (A >= B && A < C) {
            z = true;
        }
    } else {
      
        if (A >= B || A < C) {
            z = true;
        }
    }

    if (z) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }

    return 0;
}