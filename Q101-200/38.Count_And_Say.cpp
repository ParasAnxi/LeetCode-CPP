class Solution {
public:
    string countAndSay(int n) {
        if(n == 1){
        return to_string(1);
    }

    string value = countAndSay(n-1);
    if(value.length() == 1){
        return "11";
    }
    int i = 0, cnt = 1;
    string answer = "";
    while(i<value.length()-1){
        if(value[i] == value[i+1]){
            cnt++;
        }
        else{
            answer += to_string(cnt)+value[i];
            cnt = 1;
        }
        i++;
    }
    answer = answer + to_string(cnt) + value[value.length() - 1];
    return answer;
    }
};