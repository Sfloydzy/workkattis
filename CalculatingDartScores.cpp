#include <iostream>
#include <tuple>
#include <vector>
#include <queue>
using namespace std;
typedef vector<pair<int,int> > vd;
typedef vector<int> vi;
typedef vector<pair<string, int> > vds;
int n;

vi dist;
vd AL;

vds match;


void bfs () {
  dist[0] = 0;
  queue<int> score;
  score.push(0);

  while (!score.empty()) {
    int s = score.front();
    score.pop();
    for (auto &i : AL) {
      int p = s + i.first * i.second;
      if (p <= n) {
        if (dist[p] > dist[s] + 1 && (dist[s] + 1) <= 3) {
          score.push(p);
          dist[p] = dist[s] + 1;
          string mx;
          if (i.first == 1)
            mx = "single";

          else if (i.first == 2)
            mx = "double";

          else
            mx = "triple";

          match[dist[p] - 1] = make_pair(mx, i.second);
        }
      }
    }
  }
}

int main () {
  ios::sync_with_stdio(false); cin.tie(NULL);
  cin >> n;
  dist.assign(180, 1e9);
  match.assign(3, pair<string, int> ());
  for (int i = 1; i <= 20; ++i) {
    for (int j = 1; j <= 3; ++j) {
      AL.push_back(make_pair(j,i));
    }
  }

  bfs();
  for (auto &i : match) {
    cout << i.first << " " << i.second << endl;
  }

  return 0;
}
