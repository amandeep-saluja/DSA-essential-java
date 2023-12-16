class Solution {
    bool helper(string& s, string& p, int i, int j) {
        //both string and pattern is empty
        if(i<0 && j<0) return true;
        //pattern is empty but string is not
        if(j<0 && i>=0) return false;
        //string is empty but pattern is not
        if(i<0 && j>=0) {
            //**j**?**, ""
            //abc, ""
            //??ffsdadas, ""
            if(p[j]=='*') return helper(s, p, i, j-1);// check if we have some more chars in pattern
            return false;
        }

        //characters are same
        if(s[i]==p[j] || p[j]=='?')
            return helper(s, p, i-1, j-1);

        //*
        if(p[j] == '*')
            return helper(s, p, i, j-1) || helper(s, p, i-1, j);

        return false;
    }
public:
    bool isMatch(string s, string p) {
        return helper(s, p, s.size()-1, p.size()-1);
    }
};