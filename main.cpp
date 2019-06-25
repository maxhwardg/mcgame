#include <bits/stdc++.h>

using namespace std;

vector<int> apply(vector<int> perm) {
    stack<int> s;
    while (perm.size()) {
        for (int i=0;i<perm.size();i+=2) {
            s.push(perm[i]);
        }
        vector<int> next;
        for (int i=1;i<perm.size();i+=2) {
            next.push_back(perm[i]);
        }
        perm=next;
    }
    vector<int> ans;
    while (!s.empty()) {
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}

int main() {
    int N;
    cin>>N;
    vector<int> perm(N);
    for (int i=0;i<N;++i) perm[i]=i;
    for (int i=1;i<1000;++i) {
        perm = apply(perm);
        for (int p : perm) {
            cout <<p<< " ";
        }
        cout << endl;
        bool g=1;
        for (int j=0;j<N;++j) if (perm[j]!=j) {
            g=0;break;
        }
        if (g) {
            std::cout << i << std::endl;
            return 0;
        }
    }
}