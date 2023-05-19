class Solution {
public:
    string convert(string s, int nRows) {
        if(nRows==1) return s;
        bool down=true;
        string arr[numRows];
        int row=0;
        for(int i=0; i<s.size(); i++) {
            arr[row].push_back(s[i]);
            if(row==nRows-1) down=false;
            else if (row==0) down=true;
            if(down) row++;
            else row--;
        }
        string res="";
        for(int i=0; i<nRows; i++) {
            res += arr[i];
        }
        return res;
    }
};