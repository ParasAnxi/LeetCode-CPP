class Solution {
public:
    bool hasMatch(const string& s, const string& p) {
        size_t k = p.find('*');
        string pre = p.substr(0, k);
        string suf = p.substr(k + 1);

        size_t i = s.find(pre);
        if (i == string::npos) return false;

        size_t j = s.find(suf, i + pre.length());
        return j != string::npos;
    }
};
