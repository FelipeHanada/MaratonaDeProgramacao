#include <bits/stdc++.h>
using namespace std;


int main() {
	vector<string> in;
	int size = 0;
	{
		string s;
		while (getline(cin, s)) {
			in.push_back(s);
			size = max(size, (int)s.size());
		}
	}
	
	cout << "**";
	for (int i=0; i<size; i++) cout << '*';
	cout << '\n';
	
	bool move_left = false;
	for (int i=0; i<in.size(); i++) {
		cout << '*';
		
		int r = size - in[i].size(), left, right;
		
		if (move_left) {
			right = r / 2;
			left = r - right;
		} else {
			left = r / 2;
			right = r - left;
		}
		
		for (int i=0; i<left; i++) cout << ' ';
		cout << in[i];
		for (int i=0; i<right; i++) cout << ' ';

		if (left != right) move_left = !move_left;
			
		
		cout << "*\n";
	}
	
	cout << "**";
	for (int i=0; i<size; i++) cout << '*';
	cout << '\n';
}