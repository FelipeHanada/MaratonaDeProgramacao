#include <bits/stdc++.h>

using namespace std;

struct rect {
    int top;
    int left;
    int bottom;
    int right;
};

int area(rect rectangle) {
    return (rectangle.right - rectangle.left) * (rectangle.bottom - rectangle.top);
}

rect intersection(rect rectangle1, rect rectangle2) {
    rect intersec {
        max(rectangle1.top, rectangle2.top),
        max(rectangle1.left, rectangle2.left),
        min(rectangle1.bottom, rectangle2.bottom),
        min(rectangle1.right, rectangle2.right)
    };

    if (intersec.right - intersec.left < 0 || intersec.bottom - intersec.top < 0)
        return {0, 0, 0, 0};

    return intersec;
}

int main() {
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);
    
    rect billboard1;
    rect billboard2;
    rect truck;
    cin >> billboard1.left >> billboard1.top >> billboard1.right >> billboard1.bottom;
    cin >> billboard2.left >> billboard2.top >> billboard2.right >> billboard2.bottom;
    cin >> truck.left >> truck.top >> truck.right >> truck.bottom;

    // A = A1 + A2 - INTER(A1, T) - INTER(A2, T) + INTER(A1, A2, T)
    // A = A1 + A2 - INTER(A1, T) - INTER(A2, T) + INTER(INTER(A1, A2), T)

    int A1 = area(billboard1),
        A2 = area(billboard2);
    
    int interA1T = area(intersection(billboard1, truck));
    int interA2T = area(intersection(billboard2, truck));
    int interA1A2T = area(intersection(truck, intersection(billboard1, billboard2)));

    cout << A1 + A2 - interA1T - interA2T + interA1A2T << endl;
}
