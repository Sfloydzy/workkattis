#include <bits/stdc++.h>
using namespace std;

int main () {
  ios::sync_with_stdio(false); cin.tie(NULL);
  map<int, list<int>> questlog;
  int n; cin >> n;
    while (n--) {

      string cmd;
      cin >> cmd;
      if (cmd == "add") {
        int e, g;
        cin >> e >> g;
        cin.ignore();

        auto it = questlog[e].begin();
        
        // cout << endl << "Sorting";
        // sort(questlog[e].begin(), questlog[e].end(), greater<int>());
      }

      else {
        int e;
        int sum = 0;
        cin >> e;
        cin.ignore();
        auto it = questlog.lower_bound(e);
        cout << endl << it->first;
        //cout << endl << "lower_bound: " <<  it->first;
        while (it != questlog.begin()) {
          if (e >= it->first) {
            sum += it->second.front();
            // it->second.pop();
            int e_key = it->first;
            e -= e_key;
            it--;
            questlog[e_key].pop_front();
            cout <<"next top: "<< questlog[e_key].front() << endl;
            if(it->second.empty()) {
              questlog.erase(e_key);
            }
          }
        }
        cout << sum << endl;

      }

    }



  return 0;
}


/*
9
add 8 10
add 3 25
add 5 6
query 7
query 7
add 1 9
add 2 13
query 20
query 1
*/
