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

bool isValid(int x,int y,int n,int m){
	if(x>=0 && y>=0 && x<n && y<m) return true;
	else return false;
}

int main(){
	ios_base::sync_with_stdio(false);
    	cin.tie(NULL);
		
	//imagine a structure floating of water, how it fills as you push it down
	int t;
	cin>>t;
	REP(i,t){
		int n,m;
		cin>>n>>m;
		int mesh[n][m];
		//final heights 
		int fh[n][m] ;
		//boundry points in a min heap
		priority_queue< pair<int,pii>, vector<pair<int,pii>>, greater<pair<int,pii>> > bp;
		//filled columns 
		bool filled[n][m];
		REP(j,n){
			REP(k,m){
				cin>>mesh[j][k];
				filled[j][k] = false;
				if(j==0||j==n-1||k==0||k==m-1){
				       	bp.push(mp(mesh[j][k],mp(j,k)));
					filled[j][k] = true;
					fh[j][k] = mesh[j][k];
				}

			}
		}
		int ans = 0;
		
		while(!bp.empty()){
			//the lowest not filled boundry point
			int j = bp.top().se.fi;
			int k = bp.top().se.se;
			//filled[j][k] = true;
			bp.pop();
			//reachable columns from this point, BFS
			if(isValid(j+1, k,n,m) && !filled[j+1][k] ) {
				//if current column has height less than final height of its lowest neightbour
				//then fill it with water equal to final height of its neighbour
				if(mesh[j+1][k]<= fh[j][k]) {
					ans += (fh[j][k] - mesh[j+1][k]);
					fh[j+1][k] = fh[j][k];
				}
				//else if the final height will be its height itself otherwise water will spill from its neighbour
				else fh[j+1][k] = mesh[j+1][k] ;
			
				filled[j+1][k] = true;
				bp.push(mp(mesh[j+1][k],mp(j+1,k)));
			}
			if(isValid(j-1, k,n,m) && !filled[j-1][k]  ){
			       	if(mesh[j-1][k] <=  fh[j][k]){
				       	ans += (fh[j][k] - mesh[j-1][k]);
					fh[j-1][k] = fh[j][k];
				}
				else fh[j-1][k] = mesh[j-1][k];
				
				bp.push(mp(mesh[j-1][k],mp(j-1,k)));
				filled[j-1][k] = true;
			}
			if(isValid(j, k+1,n,m) && !filled[j][k+1] ) {
				if(mesh[j][k+1] <= fh[j][k]){
				       	ans += (fh[j][k] - mesh[j][k+1]);
					fh[j][k+1] = fh[j][k];
				}
				else fh[j][k+1] = mesh[j][k+1];
				
				bp.push(mp(mesh[j][k+1],mp(j,k+1)));
				filled[j][k+1] = true;
			}
			if(isValid(j, k-1,n,m) && !filled[j][k-1] ) {
				if(mesh[j][k-1] <= mesh[j][k]){
				       	ans += (fh[j][k] - mesh[j][k-1]);
					fh[j][k-1] = fh[j][k];
				}
				else fh[j][k-1] = mesh[j][k-1];
				
				bp.push(mp(mesh[j][k-1],mp(j,k-1)));
				filled[j][k-1] = true;
			}
		}
		
		REP(j,n){
			REP(k,m){
//				cout<<j<<" "<<k<<" "<<fh[j][k]<<"\n";
			}
		}
		cout<<ans<<"\n";

		//each test case seperater by an empty line
		string blank;
		if(i<t-1) getline(cin,blank);	
	}

}
//current status : not passing the some test cases
