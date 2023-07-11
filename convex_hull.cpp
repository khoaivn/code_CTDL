
#include <iostream>
#include <vector>

using namespace std;
const double EPS = 1e-9;

// Kiểu điểm
struct Point {
    int x, y;
    Point(int x = 0, int y = 0) : x(x), y(y) {}
    bool operator==(const Point &o) {
        return x == o.x && y == o.y;
    }
    bool operator!=(const Point &o) {
        return !(*this == o);
    }
    Point operator-(const Point &o) {
        return Point(x - o.x, y - o.y);
    }
    double length() const {
        return sqrt(1LL * x * x + 1LL * y * y);
    }
};

// Tích vô hướng của vector A và vector B
long long dot(const Point &A, const Point &B) {
    return 1LL * A.x * B.x + 1LL * A.y * B.y;
}



// Góc giữa vector A và vector B
double calcAngle(const Point &A, const Point &B) {
    return acos(dot(A, B) / A.length() / B.length());
}

// Trả về bao lồi với thứ tự các điểm được liệt kê cùng chiều kim đồng hồ
vector<Point> convexHull(vector<Point> p, int n) {
    if (n <= 2) return p;

    // Đưa điểm trái nhất lên đầu tập
    for (int i = 1; i < p.size(); ++i) {
        if (p[0].x > p[i].x) swap(p[0], p[i]);
    }

    // Tập bao lồi
    vector<Point> hull;
    hull.push_back(p[0]);

    // Dựng bao lồi
    do {
        // Đỉnh cuối của tập hull
        Point P = hull.back();

        // Đỉnh kế cuối của tập hull
        // Nếu hull.size() == 1 thì đặt đỉnh kế cuối là (P.x, P.y - 1)
        // Vì ban đầu hướng đang nhìn là từ dưới lên trên
        Point P0 = (hull.size() == 1 ? Point(P.x, P.y - 1) : hull[hull.size() - 2]);

        // Q là đỉnh tiếp theo của tập hull
        Point Q      = p[0];
        double angle = calcAngle(P0 - P, Q - P);

        for (int i = 1; i < n; ++i) {
            if (Q == P || Q == P0) {
                Q     = p[i];
                angle = calcAngle(P0 - P, Q - P);
                continue;
            }
            if (p[i] == P || p[i] == P0) continue;

            double newAngle = calcAngle(P0 - P, p[i] - P);
            // Nếu góc (P0, P, Q) nhỏ hơn góc (P0, P, p[i]) thì gán Q = p[i]
            if (abs(angle - newAngle) > EPS) {
                if (angle < newAngle) {
                    Q     = p[i];
                    angle = newAngle;
                }
            }
            else {
                if ((Q - P).length() > (p[i] - P).length()) {
                    Q     = p[i];
                    angle = newAngle;
                }
            }
        }
        hull.push_back(Q);
    } while (hull[0] != hull.back());

    // Đỉnh đầu tiên lặp lại ở cuối 1 lần
    hull.pop_back();

    return hull;
}
int main(){
    return 0;
}