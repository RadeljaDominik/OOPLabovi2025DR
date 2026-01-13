#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
#include <algorithm>
#include <iterator>
#include <fstream>

using namespace std;

namespace math_utils {

    struct Point {
        double x;
        double y;
    };

    double distance(const Point& a, const Point& b) {
        return sqrt((a.x - b.x) * (a.x - b.x) +
                    (a.y - b.y) * (a.y - b.y));
    }

    Point centroid(const vector<Point>& points) {
        if (points.empty())
            return {0.0, 0.0};

        Point sum = accumulate(points.begin(), points.end(), Point{0.0, 0.0},
            [](const Point& acc, const Point& p) {
                return Point{acc.x + p.x, acc.y + p.y};
            });

        return {
            static_cast<double>(sum.x) / points.size(),
            static_cast<double>(sum.y) / points.size()
        };
    }
}

istream& operator>>(istream& is, math_utils::Point& p) {
    return is >> p.x >> p.y;
}

ostream& operator<<(ostream& os, const math_utils::Point& p) {
    return os << "(" << p.x << ", " << p.y << ")";
}

int main() {
    using math_utils::Point;

    ifstream file("points.txt");
    if (!file) {
        cerr << "Ne mogu otvoriti datoteku points.txt\n";
        return 1;
    }

    vector<Point> points(
        istream_iterator<Point>(file),
        istream_iterator<Point>()
    );

    Point origin{0, 0};
    sort(points.begin(), points.end(),
         [&](const Point& a, const Point& b) {
             return math_utils::distance(a, origin) <
                    math_utils::distance(b, origin);
         });

    int countFirstQuadrant = count_if(points.begin(), points.end(),
        [](const Point& p) {
            return p.x > 0 && p.y > 0;
        });

    Point c = math_utils::centroid(points);

    transform(points.begin(), points.end(), points.begin(),
        [](const Point& p) {
            return Point{p.x + 5, p.y + 3};
        });

    points.erase(
        remove_if(points.begin(), points.end(),
            [](const Point& p) {
                return p.x < 0 && p.y < 0;
            }),
        points.end()
    );

    cout << "Tocke nakon obrade:\n";
    copy(points.begin(), points.end(),
         ostream_iterator<Point>(cout, "\n"));

    cout << "\nBroj tocaka u prvom kvadrantu: "
         << countFirstQuadrant << endl;

    cout << "Centroid: " << c << endl;

    return 0;
}

