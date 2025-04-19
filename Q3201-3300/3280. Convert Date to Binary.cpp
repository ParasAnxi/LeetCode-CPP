class Solution {
public:
  string convertDateToBinary(string date) {
    int yr, mon, day;
    char d1, d2;
    stringstream(date) >> yr >> d1 >> mon >> d2 >> day;

    string bD = bitset<8>(day).to_string();
    string bMo = bitset<8>(mon).to_string();
    string bYr = bitset<32>(yr).to_string();

    bD = bD.substr(bD.find('1'));
    bMo = bMo.substr(bMo.find('1'));
    bYr = bYr.substr(bYr.find('1'));

    return bYr + "-" + bMo + "-" + bD;
  }
};