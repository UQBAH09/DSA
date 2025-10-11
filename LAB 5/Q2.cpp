#include <iostream>
#include<vector>
using namespace std;

void backtrack(int n, int open, int close, string& path, vector<string>& res) {
    if ((int)path.size() == 2 * n) {
        res.push_back(path);
        return;
    }
    if (open < n) {
        path.push_back('(');
        backtrack(n, open + 1, close, path, res);
        path.pop_back();
    }
    if (close < open) {
        path.push_back(')');
        backtrack(n, open, close + 1, path, res);
        path.pop_back();
    }
}

int main(){
    vector<string> para;
    string path;
    backtrack(3, 0, 0, path, para);

    for(string p: para){
        cout << p << endl;
    }
}