#include <iostream>
#include <cmath>
using namespace std;

#define PI 3.14159265

struct __point
{
  double x;
  double y;
};

__point get_s(__point p1, __point p2)
{
  __point s;
  s.x = (2 * p1.x + p2.x) / 3;
  s.y = (2 * p1.y + p2.y) / 3;
  return s;
}

__point get_t(__point p1, __point p2)
{
  __point t;
  t.x = (p1.x + 2 * p2.x) / 3;
  t.y = (p1.y + 2 * p2.y) / 3;
  return t;
}

__point get_u(__point s, __point t)
{
  __point u;
  double d = PI * 60 / 180; // degrees
  u.x = cos(d) * (t.x - s.x) - sin(d) * (t.y - s.y) + s.x;
  u.y = sin(d) * (t.x - s.x) + cos(d) * (t.y - s.y) + s.y;
  return u;
}

void print_point(__point p)
{
  cout << p.x << " " << p.y << endl;
}

void kock(int n, __point p1, __point p2)
{
  if (!n) return;
  __point s, u, t;
  s = get_s(p1, p2);
  t = get_t(p1, p2);
  u = get_u(s, t);

  /* recusion */
  kock(n - 1, p1, s);
  print_point(s);
  kock(n - 1, s, u);
  print_point(u);
  kock(n - 1, u, t);
  print_point(t);
  kock(n - 1, t, p2);
}

int main()
{
  int n;
  cin >> n;
  __point p1, p2;
  p1.x = 0;   p1.y = 0;
  p2.x = 100; p2.y = 0;
  print_point(p1);
  kock(n, p1, p2);
  print_point(p2);
  return 0;
}
