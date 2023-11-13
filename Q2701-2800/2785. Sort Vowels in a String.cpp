class Solution {
public:
bool Vowel(char a){
    if(a=='a' || a=='e'||a=='i'||a=='o'||a=='u'||a=='A' || a=='E'||a=='I'||a=='O'||a=='U') return true;
       return false;
    }
    string sortVowels(string s) {
        vector<int>l(26,0);
        vector<int>u(26,0);
        for(auto it:s){
            if(it=='a' || it=='e'||it=='i'||it=='o'||it=='u')l[it-'a']++;
             if(it=='A' || it=='E'||it=='I'||it=='O'||it=='U')u[it-'A']++;
        }
        for(int i=0;i<s.length();i++){
            if(Vowel(s[i])){
                bool a=false;
                for(int j=0;j<26;j++){
                    if(u[j]!=0){s[i]=j+'A';
                      u[j]--;
                      a=true;
                    break;
                    }

                }
                if(a==false){
                for(int j=0;j<26;j++){
                    if(l[j]!=0){s[i]=j+'a';
                    l[j]--;
                    break;
                    }

                }
                }
            }
        }
       return s;
    }
};