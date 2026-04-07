using ll = long long;
using ull = unsigned long long;
using ld = long double;
using cd = complex<double>;
using pii = pair<int, int>;
using psi = pair<string, int>;
using pll = pair<ll, ll>;
using ppii = pair<int, pii>;
using vi = vector<int>;
using vd = vector<double>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vc = vector<char>;
using vpii = vector<pii>;
using vpll = vector<pll>;
using pis = pair<int, string>;
using vs = vector<string>;
using mii = map<int, int>;
using mll = map<ll, ll>;
using pli = pair<ll, int>;
using umii = unordered_map<int, int>;
using umcvi = unordered_map<char, vi>;
using umsi = unordered_map<string, int>;
using mivi = map<int, vi>;
using umci = unordered_map<char, int>;
#define pb push_back
#define MOD 1000000007
#define LMOD 1000000000000000007LL
class Robot {
public:
  int x, y, z;
  pii pos = {0, 0};
  int dir = 1;
  void direction() { dir = (dir + 3) % 4; }
  void move(int n) {
    if (dir == 0) {
      pos.second += n;
    } else if (dir == 1) {
      pos.first += n;
    } else if (dir == 2) {
      pos.second -= n;
    } else {
      pos.first -= n;
    }
  }
  Robot(int width, int height) {
    x = width - 1;
    y = height - 1;
    z = 2 * (x + y);
  }

  void step(int num) {
    if (num > z) {
      num %= z;
      num += z;
    }
    int steps;
    if (dir == 0) {
      if (y - pos.second < num) {
        steps = y - pos.second;
        num -= steps;
        move(steps);
        direction();
        step(num);
      } else {
        move(num);
      }
    } else if (dir == 1) {
      if (x - pos.first < num) {
        steps = x - pos.first;
        num -= steps;
        move(steps);
        direction();
        step(num);
      } else {
        move(num);
      }
    } else if (dir == 2) {
      if (pos.second < num) {
        steps = pos.second;
        num -= steps;
        move(steps);
        direction();
        step(num);
      } else {
        move(num);
      }
    } else {
      if (pos.first < num) {
        steps = pos.first;
        num -= steps;
        move(steps);
        direction();
        step(num);
      } else {
        move(num);
      }
    }
  }

  vector<int> getPos() { return {pos.first, pos.second}; }

  string getDir() {
    if (dir == 0)
      return "North";
    else if (dir == 1)
      return "East";
    else if (dir == 2)
      return "South";
    else
      return "West";
  }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */