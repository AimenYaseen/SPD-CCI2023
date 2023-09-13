#include <iostream>
#include <iomanip> 
using namespace std;

int main() {
	int T; cin >> T;
	cout << setiosflags(ios::uppercase);
	cout << setw(0xf) << internal;
	while(T--) {
		double A; cin >> A;
		double B; cin >> B;
		double C; cin >> C;

		cout << hex << showbase << nouppercase << left << long(A) << endl;
        cout << setw(15) << setfill('_') << setprecision(2) << fixed << showpos << right << B << endl;
        cout<< setprecision(9) << scientific << uppercase << noshowpos << C << endl;
        
	}
	return 0;

}