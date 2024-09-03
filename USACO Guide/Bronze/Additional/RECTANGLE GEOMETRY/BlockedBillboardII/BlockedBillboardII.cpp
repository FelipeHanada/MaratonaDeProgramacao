#include <bits/stdc++.h>

using namespace std;


struct rectangle {
    int top, left, bottom, right;
    int width() { return right - left; }
    int height() { return bottom - top; }
    int area() { return width() * height(); }
};

int main() {
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);

    rectangle bill1, bill2;
    cin >> bill1.left >> bill1.top >> bill1.right >> bill1.bottom;
    cin >> bill2.left >> bill2.top >> bill2.right >> bill2.bottom;

    if (bill2.top <= bill1.top && bill2.bottom >= bill1.bottom) {
        int left_overlap = max(bill1.left, bill2.left);
        int right_overlap = min(bill1.right, bill2.right);
        int width_reduction = max(0, right_overlap - left_overlap);
        cout << bill1.height() * (bill1.width() - width_reduction) << endl;

    } else if (bill2.left <= bill1.left && bill2.right >= bill1.right) {
        int top_overlap = max(bill1.top, bill2.top);
        int bottom_overlap = min(bill1.bottom, bill2.bottom);
        int height_reduction = max(0, bottom_overlap - top_overlap);
        cout << (bill1.height() - height_reduction) * bill1.width() << endl;

    } else {
        cout << bill1.area() << endl;
    }
}