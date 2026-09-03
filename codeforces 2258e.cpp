#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 4e5+7;

int k;
int sieve[N], idx[N];
int a[N], tree[4*N];
vector<int> pp;

int mrg(int x, int y) {
    return min(x, y);
}

void build(int id = 0, int ns = 0, int ne = k-1) {
    if (ns == ne) {
        tree[id] = a[ns];
        return;
    }
    int l = 2*id+1;
    int r = 2*id+2;
    int md = (ns+ne)/2;
    build(l, ns, md);
    build(r, md+1, ne);
    tree[id] = mrg(tree[l], tree[r]);
}

int get(int qs, int qe, int id = 0, int ns = 0, int ne = k-1) {
    if(ns > qe || ne < qs) {
        return INT_MAX;
    }
    if (qs <= ns && qe >= ne) {
        return tree[id];
    }
    int l = 2*id+1;
    int r = 2*id+2;
    int md = (ns+ne)/2;
    return mrg(get(qs, qe, l, ns, md), get(qs, qe, r, md+1, ne));
}

void upd(int pos, int val, int id = 0, int ns = 0, int ne = k-1) {
    if (pos > ne || pos < ns)
        return;
    if(ns == ne) {
        tree[id] = val;
        return;
    }
    int l = 2*id+1;
    int r = 2*id+2;
    int md = (ns+ne)/2;
    upd(pos, val, l, ns, md);
    upd(pos, val, r, md+1, ne);
    tree[id] = mrg(tree[l], tree[r]);
}

vector<int> divisors(int x) {
    vector<int> ret;
    while (x > 1) {
        int p = sieve[x];
        int pw = 1;
        while (x%p == 0) {
            x /= p;
            pw *= p;
            ret.push_back(idx[pw]);
        }
    }
    return ret;
}

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    memset(sieve, -1, sizeof sieve);
    vector<int> primes;
    for (int i = 2; i < N; i++) {
        if (sieve[i] == -1) {
            primes.push_back(i);
            for (int j = i; j < N; j += i)
                if (sieve[j] == -1)
                    sieve[j] = i;
        }
    }
    for(int p : primes) {
        ll x = p;
        while(x < N) {
            pp.push_back(x);
            x *= p;
        }
    }
    sort(pp.begin(), pp.end());
    for(int i = 0; i < (int)pp.size(); i++)
        idx[pp[i]] = i;
    
    int T; cin >> T;
    while(T--) {
        int n; cin >> n;
        k = 0;
        for(int x : pp) {
            a[k] = 0;
            k++;
            if (x > n)
                break;
        }
        build();
        int last[k];
        bool ok[k];
        memset(last, 0, sizeof last);
        memset(ok, 0, sizeof ok);

        for(int i = 1; i <= n; i++) {
            int x; cin >> x;
            vector<int> d = divisors(x);
            for(int id : d) {
                int l = last[id]+1;
                if (!ok[id] && l < i && get(0, id-1) >= l)
                    ok[id] = true;
            }
            for(int id : d) {
                last[id] = i;
                upd(id, i);
            }
        }
        for(int i = 0; i < k; i++) {
            int l = last[i]+1;
            if(!ok[i] && l <= n && get(0, i-1) >= l)
                ok[i] = true;
        }
        vector<int> ans;
        for(int i = 0; i < k; i++)
            if(ok[i])
                ans.push_back(pp[i]);
    
        cout << ans.size() << '\n';
        for(int x : ans)
            cout << x << ' ';
        cout << endl;
    }
}