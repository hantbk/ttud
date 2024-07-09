// #include <bits/stdc++.h>
// using namespace std;
// #define INF 1e9
// #define MAX 1000009
// #define ll long long
// #define MOD 1000000009

// struct Point
// {
//     int x, y;
//     Point()
//     {
//         x = 0;
//         y = 0;
//     }
//     Point(int x, int y)
//     {
//         this->x = x;
//         this->y = y;
//     }
// };

// int n;
// vector<Point> P;
// vector<Point> C;
// Point O;

// long long dist2(Point &A, Point &B)
// {
//     long long x = A.x - B.x;
//     long long y = A.y - B.y;
//     return 1LL * x * x + 1LL * y * y;
// }

// long long cross_product(Point &O, Point &A, Point &B)
// {
//     // Tích có hướng của OA và OB
//     long long xa = A.x - O.x;
//     long long ya = A.y - O.y;
//     long long xb = B.x - O.x;
//     long long yb = B.y - O.y;
//     return 1LL * xa * yb - 1LL * xb * ya;
// }

// int ccw(Point &A, Point &B, Point &C)
// {
//     long long cp = cross_product(A, B, C);
//     if (cp == 0)
//         return 0;
//     return (cp > 0) ? 1 : -1;
// }

// // So sánh 2 điểm A và B so với điểm gốc P[0] theo thứ tự ngược chiều kim đồng hồ
// bool compare(Point &A, Point &B)
// {
//     long long cp = cross_product(O, A, B);
//     if (cp == 0)
//         return dist2(P[0], A) < dist2(P[0], B);
//     return cp > 0;
// }

// bool sameSide(Point &A, Point &B, Point &C, Point &D)
// {
//     // Kiểm tra 2 điểm C và D có cùng phía so với đường thẳng AB hay không
//     long long sc = ccw(A, B, C);
//     long long sd = ccw(A, B, D);
//     return (sc * sd >= 0);
// }

// bool checkInsideConvexHull(Point &T)
// {
//     int last = P.size() - 1;
//     if (sameSide(P[0], P[1], P[last], T)     // P[0] và P[1] cùng phía so với đường thẳng P[last]T
//         && sameSide(P[0], P[last], P[1], T)) // P[0] và P[last] cùng phía so với đường thẳng P[1]T
//     {
//         int l = 1, r = last;
//         while (r - l > 1)
//         {
//             int mid = (l + r) / 2;
//             if (sameSide(P[0], P[mid], P[last], T))
//             {
//                 l = mid;
//             }
//             else
//             {
//                 r = mid;
//             }

//             if (!sameSide(P[l], P[r], P[0], T))
//             {
//                 return false;
//             }
//         }
//         return true;
//     }
//     return false;
// }

// void computeConvexHull()
// {
//     C.clear();
//     // Tìm điểm gốc tọa độ
//     int pos = 0;
//     for (int i = 1; i < n; i++)
//     {
//         if (P[i].y < P[pos].y || (P[i].y == P[pos].y && P[i].x < P[pos].x))
//         {
//             pos = i;
//         }
//     }
//     swap(P[0], P[pos]); // Chọn điểm có hoành độ nhỏ nhất làm gốc tọa độ
//     O = P[0];
//     sort(P.begin() + 1, P.begin() + n, compare);
//     C.push_back(P[0]);
//     C.push_back(P[1]);
//     for (int i = 2; i < n; i++)
//     {
//         while (C.size() > 1 && ccw(C[C.size() - 2], C[C.size() - 1], P[i]) <= 0)
//         {
//             C.pop_back();
//         }
//         C.push_back(P[i]);
//     }
// }

// void input()
// {
//     cin >> n;
//     P.resize(n);
//     for (int i = 0; i < n; i++)
//     {
//         int x, y;
//         cin >> x >> y;
//         P[i] = Point(x, y);
//     }
// }

// int main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);

//     input();
//     computeConvexHull();
//     int res = 1;
//     if (C.size() != n)
//         res = 0;
//     int K;
//     cin >> K;
//     for (int k = 1; k <= K; k++)
//     {
//         int x, y;
//         cin >> x >> y;
//         Point T = Point(x, y);
//         if (res == 1)
//         {
//             res = checkInsideConvexHull(T);
//         }
//         cout << res << "\n";
//     }

//     return 0;
// }

// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;

// Sorting Function to sort points
bool cmp(pair<int, int>& a,
		pair<int, int>& b)
{

	if (a.first == b.first)
		return a.second < b.second;
	return a.first < b.first;
}

// Function To Check Clockwise
// Orientation
int cw(pair<int, int>& a,
	pair<int, int>& b,
	pair<int, int>& c)
{

	int p = a.first * (b.second - c.second)
			+ b.first * (c.second - a.second)
			+ c.first * (a.second - b.second);

	return p < 0ll;
}

// Function To Check Counter
// Clockwise Orientation
int ccw(pair<int, int>& a,
		pair<int, int>& b,
		pair<int, int>& c)
{

	int p = a.first * (b.second - c.second)
			+ b.first * (c.second - a.second)
			+ c.first * (a.second - b.second);

	return p > 0ll;
}

// Graham Scan algorithm to find Convex
// Hull from given points
vector<pair<int, int> > convexHull(
	vector<pair<int, int> >& v)
{
	// Sort the points
	sort(v.begin(),
		v.end(), cmp);

	int n = v.size();
	if (n <= 3)
		return v;

	// Set starting and ending points as
	// left bottom and top right
	pair<int, int> p1 = v[0];
	pair<int, int> p2 = v[n - 1];

	// Vector to store points in
	// upper half and lower half
	vector<pair<int, int> > up, down;

	// Insert StartingEnding Points
	up.push_back(p1);
	down.push_back(p1);

	// Iterate over points
	for (int i = 1; i < n; i++) {

		if (i == n - 1 || !ccw(p1, v[i], p2)) {

			while (up.size() > 1
				&& ccw(up[up.size() - 2],
						up[up.size() - 1],
						v[i])) {

				// Exclude this point
				// if we can form better

				up.pop_back();
			}

			up.push_back(v[i]);
		}

		if (i == n - 1 || !cw(p1, v[i], p2)) {

			while (down.size() > 1
				&& cw(down[down.size() - 2],
						down[down.size() - 1],
						v[i])) {

				// Exclude this point
				// if we can form better
				down.pop_back();
			}
			down.push_back(v[i]);
		}
	}

	// Combine upper and lower half
	for (int i = down.size() - 2;
		i > 0; i--)
		up.push_back(down[i]);

	// Remove duplicate points
	up.resize(unique(up.begin(),
					up.end())
			- up.begin());

	// Return the points on Convex Hull
	return up;
}

// Function to find if point lies inside
// a convex polygon
bool isInside(vector<pair<int, int> > points,
			pair<int, int> query)
{
	// Include the query point in the
	// polygon points
	points.push_back(query);

	// Form a convex hull from the points
	points = convexHull(points);

	// Iterate over the points
	// of convex hull
	for (auto x : points) {

		// If the query point lies
		// on the convex hull
		// then it wasn't inside
		if (x == query)
			return false;
	}

	// Otherwise it was Inside
	return true;
}

// Driver Code
int main()
{

	// Points of the polygon
	// given in any order
	int n = 7;
	vector<pair<int, int> > points;

	points = { { 1, 1 }, { 2, 1 }, { 3, 1 },
			{ 4, 1 }, { 4, 2 }, { 4, 3 },
			{ 4, 4 } };

	// Query Points
	pair<int, int> query = { 3, 2 };

	// Check if its inside
	if (isInside(points, query)) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}

	return 0;
}
