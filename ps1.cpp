#include <bits/stdc++.h>
using namespace std;

int main () {
  ios::sync_with_stdio(false); cin.tie(NULL);
  int n; cin >> n;
  vector<int> deb;
  int count = 0;
  while (n--){
    int inp; cin >> inp;
    deb.push_back(inp);
  }
  int min = deb[0];
  int day = 0;
  for (int i = 1; i < deb.size(); i++ ) {
    if (deb[i] < min) {
      day = i;
      min = deb[i];
    }
  }
  cout << day++ << endl;
  return 0;
}
