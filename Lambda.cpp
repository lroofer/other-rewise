#include <algorithm>
#include <iostream>
#include <vector>
#include <functional>
using namespace std;

void DoWork(vector<int> &vc, function<void(int)> f) {
	for (auto el : vc) {
		f(el);
	}
}

int main() {
	vector<int> vc = { 1, 5, 3, 4, 3, 4, 5, 3, 5, 35, 35 };
	// first var
	function<void(int)> f;
	f = [](int a){
		cout << "Lambda function was called by " << a << endl;
	};
	DoWork(vc, f);


	//second var
	
	DoWork(vc, [](int a) {
		cout << "Lambda function was called by " << a << endl;
	});
}
