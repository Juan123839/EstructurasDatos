#include <iostream>
#include <string>

using namespace std;

int main() {

    string linea;

    while (true) {

        cout << "$ ";

        getline(cin, linea);

        cout << "Escribiste: " << linea << endl;
    }

    return 0;
}