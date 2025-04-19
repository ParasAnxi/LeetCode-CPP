class Solution {
public:
  bool checkTwoChessboards(string coordinate1, string coordinate2) {
    int x1 = coordinate1[0] - 'a';
    int y1 = coordinate1[1] - '0';
    int x2 = coordinate2[0] - 'a';
    int y2 = coordinate2[1] - '0';
    
    return (((x1 + y1) % 2) == ((x2 + y2) % 2)) ? 1 : 0;
  }
};