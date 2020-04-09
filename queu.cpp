#include <iostream>
#include <vector>

using namespace std;

struct {
private:
	vector<int> v;
	bool empty() {
		if (v.size() > 0)
			return false;
		else
			return true;
	}
public:
	int que_size() {
		return v.size();
	}
	void push(int i) {
		v.push_back(i);
	}
	int pop() {
		int x = v[0];
		for (int i = 0; i < v.size() - 1; ++i)
			v[i] = v[i + 1];
		v.pop_back();
		return x;
	}
};

int main() {}