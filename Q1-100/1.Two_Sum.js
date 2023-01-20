let twoSum = function(num, end) {
    let numMap = {};
    let ans = [];
    for (let i = 0; i < num.length; i++) {
        if ((end - num[i]) in numMap) {
            ans[1] = i;
            ans[0] = numMap[end - num[i]];
            return ans;
        }
        numMap[num[i]] = i;
    }

    return ans;
};
