#include <bits/stdc++.h>
using namespace std;

int main () {
  ios::sync_with_stdio(false); cin.tie(NULL);
  map<int, priority_queue<int>, greater<int> > questlog;
  int n; cin >> n;
    while (n--) {

      string cmd;
      cin >> cmd;
      if (cmd == "add") {
        int e, g;
        cin >> e >> g;
        cin.ignore();
        questlog[e].push(g);
      }

      else {
        int e;
        int sum = 0;
        cin >> e;
        cin.ignore();
        auto it = questlog.lower_bound(e);
        while (it != questlog.begin()) {
          if (e >= it->first) {
            sum += it->second.top();
            it->second.pop();
          }
          it--;
          e -= it->first;
        }
        cout << sum << endl;

      }

    }



  return 0;
}
