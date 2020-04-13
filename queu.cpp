#include <iostream>
#include <vector>

using namespace std;

class queu{
private:
	int size;
	int capasity;
	int* var;
public:
	queu(int len = 0, int fill = 0) {
		size = len;
		capasity = ceil(size / 4);
		var = new int[len];
		for (int i = 0; i < size; ++i)
			var[i] = fill;
	}
	~queu() {
		delete[] var;
		cout << "delete";
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
		if (size < capasity)
			capasity *= 2;
		delete[] new_var;
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
		if (size < capasity)
			capasity *= 2;
		delete[] new_var;
		return first;
	}
	int length() {
		return size;
	}
};