const longestPalindrome = function(s) {
    let start = 0; 
    let end = 0;
    for (let i=0; i<s.length; i++) { 
        let oddPalindrome = true; 
        let lOdd = expandAroundCenter(s, i, i); 
        let lEven = expandAroundCenter(s, i, i+1); 
        let lMax = Math.max(lOdd, lEven); 
        if (lMax === lEven) { 
            oddPalindrome = false;
        }
        if (lMax > (end - start+1)) { 
            if (oddPalindrome) { 
                start = i - Math.floor(lMax/2); 
                end = i + Math.floor(lMax/2);
            } else {
                start = (i - (lMax/2)) +1;
                end = (i+1 + (lMax/2)) -1
            }
        }
    }
    return s.substring(start, end+1); 
}
const expandAroundCenter = function(s, L, R) {
    while (L >=0 && R < s.length && s[L] == s[R]) { 
        L--;
        R++;
    }
   
    R = R-1;
    L = L+1;
    return R - L + 1;
}
