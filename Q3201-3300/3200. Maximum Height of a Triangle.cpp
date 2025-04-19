class Solution {
private:
  int solve(int red, int blue) {

    int bls = 1;
    bool flg = true;

    while (red > 0 || blue > 0) {
      if (flg && red >= bls) red -= bls;
      else if (!flg && blue >= bls) blue -= bls;
      else break;
      flg = !flg;
      bls++;
    }

    return bls - 1;
  }

public:
  int maxHeightOfTriangle(int red, int blue) {
    return max(solve(red, blue), solve(blue, red));
  }
};