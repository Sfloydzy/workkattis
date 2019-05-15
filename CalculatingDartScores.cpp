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
        score.push(p);
      }
    }
  }
}
int main () {
  ios::sync_with_stdio(false); cin.tie(NULL);
  cin >> n;
  dist.assign(180, 1e9);
  for (int i = 1; i <= 20; ++i) {
    for (int j = 1; j <= 3; ++j) {
      AL.push_back(make_pair(j,i));
    }
  }

  bfs();


  return 0;
}
