// AG___
// There is a one percent chance, and sometimes that chance is good enough.
// But what matters is what you think about that one percent.

// Template Credits- Punpun018
/****************************************************************************/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define intmin LLONG_MIN
#define intmax LLONG_MAX
#define ll long long
#define double long double
#define uint unsigned long long
#define inf 1000000000000000005
const long long mod = 998244353;
const ll N = 1e9 + 10;
const int MAX = 2000005;
#define yes cout << "YES" << "\n"
#define no cout << "NO" << "\n"
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define endl "\n"
/**************************************************************************/
ll gcd(ll a, ll b)
{
    if (b > a)
    {
        return gcd(b, a);
    }
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}
ll expo(ll a, ll b, ll mod)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b = b >> 1;
    }
    return res;
}
void extendgcd(ll a, ll b, ll *v)
{
    if (b == 0)
    {
        v[0] = 1;
        v[1] = 0;
        v[2] = a;
        return;
    }
    extendgcd(b, a % b, v);
    ll x = v[1];
    v[1] = v[0] - v[1] * (a / b);
    v[0] = x;
    return;
} // pass an arry of size1 3
ll mminv(ll a, ll b)
{
    ll arr[3];
    extendgcd(a, b, arr);
    return arr[0];
} // for non prime b
ll mminvprime(ll a, ll b) { return expo(a, b - 2, b); }
bool revsort(ll a, ll b) { return a > b; }
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact)
{
    ll val1 = fact[n];
    ll val2 = ifact[n - r];
    ll val3 = ifact[r];
    return (((val1 * val2) % m) * val3) % m;
}
void google(int t) { cout << "Case #" << t << ": "; }
vector<ll> sieve(int n)
{
    int *arr = new int[n + 1]();
    vector<ll> vect;
    for (int i = 2; i <= n; i++)
        if (arr[i] == 0)
        {
            vect.push_back(i);
            for (int j = 2 * i; j <= n; j += i)
                arr[j] = 1;
        }
    return vect;
}
ll mod_add(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (((a + b) % m) + m) % m;
}
ll mod_mul(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (((a * b) % m) + m) % m;
}
ll mod_sub(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (((a - b) % m) + m) % m;
}
ll mod_div(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (mod_mul(a, mminvprime(b, m), m) + m) % m;
} // only for prime m
ll phin(ll n)
{
    ll number = n;
    if (n % 2 == 0)
    {
        number /= 2;
        while (n % 2 == 0)
            n /= 2;
    }
    for (ll i = 3; i <= sqrt(n); i += 2)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
                n /= i;
            number = (number / i * (i - 1));
        }
    }
    if (n > 1)
        number = (number / n * (n - 1));
    return number;
} // O(sqrt(N))
class Hash {
  private:
	map<tuple<int,int,int>,int>hash_table;
  public:
	Hash () {}
	int hash(int x){
		return hash({x,0,0});
	}
	int hash(tuple<int,int>x){
		return hash({get<0>(x),get<1>(x),0});
	}
	int hash(tuple<int,int,int>x){
		if(hash_table.find(x)!=hash_table.end())
			return hash_table[x];
		int new_hash = hash_table.size();
		hash_table[x]=new_hash;
		return new_hash;
	}
};

class Graph {

	bool is_directed;

	public:
		vector<vector<pair<int,ll>>>adj;
    	int n,N=5000000;
    	Hash h;

		Graph(int n_, bool is_directed_ = true){
			n=n_; is_directed = is_directed_;
			adj.resize(N,vector<pair<int,ll>>());
		}

		int hash(int u, int v){
			return h.hash({u,v});
		}
		int hash(int u, int v, int k){
			return h.hash({u,v,k});
		}

		void add_edge(int uR, int vR, ll c=0){
		  int u=h.hash(uR), v=h.hash(vR);
		  add_edge_internal(u,v,c);
		}
		void add_edge(tuple<int,int> uR, tuple<int,int> vR, ll c=0){
		  int u=h.hash(uR), v=h.hash(vR);
		  add_edge_internal(u,v,c);
		}
		void add_edge(tuple<int,int,int> uR, tuple<int,int,int> vR, ll c=0){
		  int u=h.hash(uR), v=h.hash(vR);
		  add_edge_internal(u,v,c);
		}


	private :

	  void add_edge_internal(int u, int v, ll c=0){
			add_edge_weighted_undirected(u,v,c);
			if(!is_directed)
				add_edge_weighted_undirected(v,u,c);
		}
		void add_edge_weighted_undirected(int u, int v, ll c) {
			pair<int,ll>p = make_pair(v,c);
			adj[u].push_back(p);
		}

};

class BFS {
    vector<ll>min_dist_from_source;
    vector<bool> visited;
    Graph *g;

    public:
      BFS(Graph *g_) {
          g = g_;
          clear();
      }

	  	void clear() {
  			min_dist_from_source.clear();
  			min_dist_from_source.resize(g->N,-1);
  			visited.clear();
  			visited.resize(g->N, false);
  		}


      void run(int sourceR) {
        int source = (g->h).hash(sourceR);
        run_internal(source);
      }
      void run(tuple<int,int> sourceR) {
        int source = (g->h).hash(sourceR);
        run_internal(source);
      }
      void run(tuple<int,int,int> sourceR) {
        int source = (g->h).hash(sourceR);
        run_internal(source);
      }


      int min_dist(int targetR){
      	int target = (g->h).hash(targetR);
      	return min_dist_internal(target);
      }
      int min_dist(tuple<int,int> targetR){
      	int target = (g->h).hash(targetR);
      	return min_dist_internal(target);
      }
      int min_dist(tuple<int,int,int> targetR){
      	int target = (g->h).hash(targetR);
      	return min_dist_internal(target);
      }

      bool is_visited(int targetR){
      	int target = (g->h).hash(targetR);
      	return is_visited_internal(target);
      }
      bool is_visited(tuple<int,int> targetR){
      	int target = (g->h).hash(targetR);
      	return is_visited_internal(target);
      }
      bool is_visited(tuple<int,int,int> targetR){
      	int target = (g->h).hash(targetR);
      	return is_visited_internal(target);
      }

  private:
    void run_internal(int source) {
			queue<int> q;
			q.push(source);

			visited[source] = true;
			min_dist_from_source[source] = 0;

			while(!q.empty()) {
				int cur_node = q.front();
				for (unsigned int i = 0; i < (g->adj[cur_node]).size(); ++i) {
					int adj_node =  (g->adj[cur_node])[i].first;
					if (visited[adj_node] == false) {
						visited[adj_node] = true;
						min_dist_from_source[adj_node] = min_dist_from_source[cur_node] + 1;
						q.push(adj_node);
					}
				}
				q.pop();
			}

			return;
    }

    int min_dist_internal(int target){
    	return min_dist_from_source[target];
    }

    bool is_visited_internal(int target){
    	return visited[target];
    }

};
/**********************************************************************************************/

void sol()
{
   
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    // t = 1;
    cin >> t;
    while (t--)
    {
        sol();
    }
}