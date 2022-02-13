#include <iostream>
#include <vector>
using namespace std;
struct Point {
	double x;
	double y;
};
int main () {
    vector<Point> points;
    int n, x, y;
    cout << "n = ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        Point point;
        point.x = x;
        point.y = y;
        points.push_back(point);
    }
    double min =1000;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) {
            double d = sqrt((points[j].x - points[i].x) * (points[j].x - points[i].x) + (points[j].y - points[i].y) * (points[j].y - points[i].y));
            if (d < min)
                min = d;
        }
            
    cout << min;
}