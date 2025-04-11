#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1.0);

// Define cotangent function
double cot(double x) {
    return 1.0 / tan(x);
}

double polygon_area(int n, int a) {
    return n * a * a / 4.0 * cot(PI / n);
}

double circumradius(int n, int a) {
    return a / (2.0 * sin(PI / n));
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int nt, at, nb, ab;
        scanf("%d %d", &nt, &at);
        scanf("%d %d", &nb, &ab);
        double rt = circumradius(nt, at);
        double rb = circumradius(nb, ab);
        double area_b = polygon_area(nb, ab);
        double ans = (rt < rb) ? area_b : 0.0;
        printf("%.6f\n", ans);
    }
    return 0;
}