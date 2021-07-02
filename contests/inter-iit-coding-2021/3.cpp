/* @author: saran
 * Git: https://github.com/abhisheksaran
 * LinkedIn: https://www.linkedin.com/in/abhishek-saran-2900b/
 */

#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef pair<string, string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<LL> vl;
typedef vector<vl> vvl;

double EPS = 1e-9;
int INF = 1000000005;
long long INFF = 1000000000000000005LL;
double PI = acos(-1);
int dirx[8] = { -1, 0, 0, 1, -1, -1, 1, 1 };
int diry[8] = { 0, 1, -1, 0, -1, 1, -1, 1 };

#ifdef TESTING
#define DEBUG fprintf(stderr, "====TESTING====\n")
#define VALUE(x) cerr << "The value of " << #x << " is " << x << endl
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define DEBUG
#define VALUE(x)
#define debug(...)
#endif

#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define FORN(a, b, c) for (int(a) = (b); (a) <= (c); ++(a))
#define FORD(a, b, c) for (int(a) = (b); (a) >= (c); --(a))
#define FORSQ(a, b, c) for (int(a) = (b); (a) * (a) <= (c); ++(a))
#define FORC(a, b, c) for (char(a) = (b); (a) <= (c); ++(a))
#define FOREACH(a, b) for (auto&(a) : (b))
#define REP(i, n) FOR(i, 0, n)
#define REPN(i, n) FORN(i, 1, n)
#define MAX(a, b) a = max(a, b)
#define MIN(a, b) a = min(a, b)
#define SQR(x) ((LL)(x) * (x))
#define RESET(a, b) memset(a, b, sizeof(a))
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ALL(v) v.begin(), v.end()
#define ALLA(arr, sz) arr, arr + sz
#define SIZE(v) (int)v.size()
#define SORT(v) sort(ALL(v))
#define REVERSE(v) reverse(ALL(v))
#define SORTA(arr, sz) sort(ALLA(arr, sz))
#define REVERSEA(arr, sz) reverse(ALLA(arr, sz))
#define PERMUTE next_permutation
#define TC(t) while (t--)

inline string IntToString(LL a)
{
    char x[100];
    sprintf(x, "%lld", a);
    string s = x;
    return s;
}

inline LL StringToInt(string a)
{
    char x[100];
    LL res;
    strcpy(x, a.c_str());
    sscanf(x, "%lld", &res);
    return res;
}

inline string GetString(void)
{
    char x[1000005];
    scanf("%s", x);
    string s = x;
    return s;
}

inline string uppercase(string s)
{
    int n = SIZE(s);
    REP(i, n)
    if (s[i] >= 'a' && s[i] <= 'z')
        s[i] = s[i] - 'a' + 'A';
    return s;
}

inline string lowercase(string s)
{
    int n = SIZE(s);
    REP(i, n)
    if (s[i] >= 'A' && s[i] <= 'Z')
        s[i] = s[i] - 'A' + 'a';
    return s;
}

inline void OPEN(string s)
{
#ifndef TESTING
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
#endif
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n,i;
  cin>>n;
  vector<vector<pair<int,int>>> adjList(n);
  vi p(n,0);
  REP(i,n-1){
    int u,v,x;
    cin>>u>>v>>x;
    u--;
    v--;
    adjList[u].push_back({v,x});
    adjList[v].push_back({u,x});
    p[v] = u;
  }
  vector<LL> w(n,0);
  i = 0;
  REP(i,n) {
    cin>>w[i];
//    cout<<i<<" "<<w[i]<<endl;
  }
  
  vector<LL> d1(n,INFF);
  d1[0] = w[0];
  vector<LL> d2(n,INFF);
  d2[0] = 0;
  queue<int> q;
  q.push(0);
  while(!q.empty()){
    int u = q.front();
  //  cout<<u<<endl;
    q.pop();
    for(auto e: adjList[u]){
      int v = e.first;
      int wg = e.second;
      if(v!=p[u]){
        d1[v] = d1[u]+wg;
        d2[v] = d2[u]+2*wg;
        int temp = d1[v];
        d1[v] = min(d1[v], d2[v] + w[v]);
        d2[v] = min(d2[v], temp + w[v]);
       // d2[v] = min(d1[v]+w[v], d2[u]+ 2*wg);
        q.push(v);
      }
    }
  }
  
  //process query
  int Q;
  cin>>Q;
  REP(i,Q){
    int u,v;
    cin>>u>>v;
    cout<<d2[u-1]<<endl;
  }
  /*
  REP(i,n){
    cout<<i+1<<" "<<d1[i]<<" "<<d2[i]<<endl;
  }
  */
	return 0;
}
