#include <iostream>
using namespace std;

class Solution {

    void helper(int n, int idx, int k, vector<vector<int>>& res, vector<int>& temp) {
        //base
        if(k==0) {
            res.push_back(temp);
            return;
        }

        for(int i=idx; i<=n; i++) {
            temp.push_back(i);
            helper(n, i+1, k-1, res, temp);
            temp.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> temp;
        helper(n, 1, k, res, temp);
        return res;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> res =  s.combine(4, 3);

    for(vector<int> row: res) {
        cout<<"(";
        for(int s: row) {
            cout<<s<<", ";
        }
        cout<<")"<<endl;
    }

    return 0;
}