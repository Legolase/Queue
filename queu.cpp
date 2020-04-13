#include <iostream>
#include <vector>

using namespace std;

struct queu{
private:
	int size;
	int capasity;
	int* var;
public:
	queu() {
		size = 0;
		capasity = 4;
		var = new int[size];
	}
	~queu() {
		delete[] var;
	}
	void add(int x) {
		++size;
		int* new_var = new int[size];
		for (int i = 0; i < size-1; ++i) {
			new_var[i] = var[i];
		}
		new_var[size-1] = x;
		delete[] var;
		var = new int[size];
		for (int i = 0; i < size; ++i)
			var[i] = new_var[i];
		capasity = ceil(size / 4);
	}
	int get() {
		--size;
		int first = var[0];
		int* new_var = new int[size];
		for (int i = 0; i < size; ++i) {
			new_var[i] = var[i + 1];
		}
		delete[] var;
		var = new int[size];
		for (int i = 0; i < size; ++i)
			var[i] = new_var[i];
		capasity = ceil(size / 4);
		return first;
	}
	int length() {
		return size;
	}
};

int main() {
	queu a;
	for (int i = 0; i < 5; ++i)
		a.add(i * 2);
	int x = a.get();
	cout << x;
}