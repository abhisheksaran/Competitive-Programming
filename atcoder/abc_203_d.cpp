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
//if there exist a k*k subgrid such that median is greater than or equal to X, return true
//else return false;
bool medianPossible(int x, vvi& a,int n, int k){
  vvi temp(n,vi(n,0));
  int i,j;
  REP(i,n){
    REP(j,n){
      if(a[i][j]<=x) temp[i][j] = 1;
   }
  }

  //calculate and see if there exist such a subgrid
  //s[i][j] depicts the count of heights less than equal to x from (1,1) to (i,j)
  vvi s(n+1,vi(n+1,0)) ;
  REPN(i,n){
    REPN(j,n){
      s[i][j] += s[i-1][j] + s[i][j-1] - s[i-1][j-1] + temp[i-1][j-1];   
    }
  }

  //calculate cnt for k*k sub grid
  n = n-k+1;
  REPN(i,n){
    REPN(j,n){
      int cnt = s[i+k-1][j+k-1] - s[i-1][j+k-1] - s[i+k-1][j-1] + s[i-1][j-1];
      //cout<<i<<" "<<j<<" " <<cnt<<" "<<x<<endl;
      if(cnt>=(ceil((k*k)/2.0))) return true;
    }
  }
  return false;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n,k,i,j;
  cin>>n>>k;
  vvi a(n,vi(n));
  int mx=0;
  REP(i,n){
    REP(j,n){
      cin>>a[i][j];
      mx = max(mx, a[i][j]);
    }
  }
  i=0;
  while(i<mx){
     int mid = (i+mx)/2;
     //the guessed median is too large
     if(medianPossible(mid,a,n,k)) mx=mid;
     //guessed median is too small
     else i = mid+1;
    // cout<<i<<" "<<mx<<endl;
  }
  cout<<i<<endl; 
	return 0;
}
