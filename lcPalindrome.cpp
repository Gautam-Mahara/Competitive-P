class Solution {
public:
    int helper(string &s ,string &t, vector<vector<int>> &st,int ind1,int ind2){
        if(ind2 > t.size()-1 || ind1 > s.size()-1) return 0;
        if(st[ind1][ind2]!=-1) return st[ind1][ind2];
        int match=0,nomatch=0;
        if(s[ind1]==t[ind2])
        {
            match= 1 + helper(s,t,st,ind1+1,ind2+1);
        }
        else {
            int left = helper(s,t,st,ind1+1,ind2);
            int right= helper(s,t,st,ind1,ind2+1);
            nomatch = max(left,right);
        }
        return st[ind1][ind2] = max(match,nomatch);
    }
    int longestPalindromeSubseq(string s) {
       string t(s.rbegin(), s.rend());
         int n = s.size();
        vector<vector<int>> st(n+1,vector<int>(n+1,-1));
        return helper(s,t,st,0,0);
    }
};