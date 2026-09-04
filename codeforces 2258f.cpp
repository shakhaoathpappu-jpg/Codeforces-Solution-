#include<bits/stdc++.h>
using namespace std;

using ll = long long;

struct Node {
    ll key, lazy;
    int prio, sz;
    Node *l, *r;

    Node(ll k = 0) : key(k), lazy(0), prio(rng()), sz(1), l(nullptr), r(nullptr) {}

    static uint32_t rng() {
        static uint32_t x = 123456789;
        x ^= x << 13;
        x ^= x >> 17;
        x ^= x << 5;
        return x;
    }
};

int sz(Node *t) {
    return t ? t->sz : 0;
}

void apply(Node *t, ll add) {
    if (!t) return;
    t->key += add;
    t->lazy += add;
}

void push(Node *t) {
    if (!t || t->lazy == 0) return;
    apply(t->l, t->lazy);
    apply(t->r, t->lazy);
    t->lazy = 0;
}

void pull(Node *t) {
    if (t) t->sz = 1 + sz(t->l) + sz(t->r);
}

void splitRank(Node *t, int k, Node *&a, Node *&b) {
    if (!t) {
        a = b = nullptr;
        return;
    }
    push(t);

    int leftSz = sz(t->l);
    if (k <= leftSz) {
        Node *leftPart, *rightPart;
        splitRank(t->l, k, leftPart, rightPart);
        t->l = rightPart;
        pull(t);
        a = leftPart;
        b = t;
    } else {
        Node *leftPart, *rightPart;
        splitRank(t->r, k - leftSz - 1, leftPart, rightPart);
        t->r = leftPart;
        pull(t);
        a = t;
        b = rightPart;
    }
}

void splitKey(Node *t, ll key, Node *&a, Node *&b) {
    if (!t) {
        a = b = nullptr;
        return;
    }
    push(t);

    if (t->key <= key) {
        Node *l2, *r2;
        splitKey(t->r, key, l2, r2);
        t->r = l2;
        pull(t);
        a = t;
        b = r2;
    } else {
        Node *l2, *r2;
        splitKey(t->l, key, l2, r2);
        t->l = r2;
        pull(t);
        a = l2;
        b = t;
    }
}

Node *concat(Node *a, Node *b) {
    if (!a) return b;
    if (!b) return a;

    if (a->prio < b->prio) {
        push(a);
        a->r = concat(a->r, b);
        pull(a);
        return a;
    } else {
        push(b);
        b->l = concat(a, b->l);
        pull(b);
        return b;
    }
}

Node* insertSingle(Node* root, Node* item) {
    if (!item) return root;
    item->l = item->r = nullptr;
    item->sz = 1;
    item->lazy = 0;
    
    Node *a, *b;
    splitKey(root, item->key, a, b);
    return concat(concat(a, item), b);
}

void extractAndInsert(Node* src, Node*& dest) {
    if (!src) return;
    push(src);
    
    Node* left_child = src->l;
    Node* right_child = src->r;
    
    dest = insertSingle(dest, src);
    
    extractAndInsert(left_child, dest);
    extractAndInsert(right_child, dest);
}

void addFirst(Node *&root, int x, ll delta) {
    if (x <= 0 || !root) return;
    if (x >= sz(root)) {
        apply(root, delta);
        return;
    }

    Node *a, *b;
    splitRank(root, x, a, b);
    apply(a, delta);
    root = concat(a, b);
}

void addLast(Node *&root, int y, ll delta) {
    if (y <= 0 || !root) return;
    if (y >= sz(root)) {
        apply(root, delta);
        return;
    }

    Node *a, *b;
    splitRank(root, sz(root) - y, a, b);
    apply(b, delta);
    root = concat(a, b);
}

ll sumNegative(Node *t) {
    if (!t) return 0;
    push(t);
    ll res = (t->key < 0 ? t->key : 0);
    res += sumNegative(t->l);
    res += sumNegative(t->r);
    return res;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];

        vector<vector<int>> g(n + 1);
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        vector<int> parent(n + 1, 0), ord;
        ord.reserve(n);
        parent[1] = -1; 
        ord.push_back(1);

        for (int i = 0; i < (int)ord.size(); i++) {
            int v = ord[i];
            for (int to : g[v]) {
                if (to == parent[v]) continue;
                parent[to] = v;
                ord.push_back(to);
            }
        }

        vector<int> szSub(n + 1, 0), cntPlus(n + 1, 0), cntZero(n + 1, 0);
        vector<ll> val(n + 1, 0);
        vector<Node*> root(n + 1, nullptr);

        for (int idx = n - 1; idx >= 0; idx--) {
            int v = ord[idx];

            szSub[v] = 1;
            cntPlus[v] = (a[v] == 1);
            cntZero[v] = (a[v] == 0);

            int heavyCld = -1;
            int mxSz = -1;
            ll base = 0; 

            for (int to : g[v]) {
                if (parent[to] != v) continue;

                szSub[v] += szSub[to];
                cntPlus[v] += cntPlus[to];
                cntZero[v] += cntZero[to];
                base += val[to]; 

                if (sz(root[to]) > mxSz) {
                    mxSz = sz(root[to]);
                    heavyCld = to;
                }
            }

            if (heavyCld != -1) {
                root[v] = root[heavyCld];
            }

            for (int to : g[v]) {
                if (parent[to] != v || to == heavyCld) continue;
                extractAndInsert(root[to], root[v]);
            }

            if (a[v] == 0) {
                root[v] = insertSingle(root[v], new Node(0));
            }

            if (root[v]) {
                int L = cntPlus[v];
                int R = cntPlus[v] + cntZero[v];
                int nv = szSub[v];

                int valT = nv / 2;          
                int S = (nv + 1) / 2;    

                int x = 0;
                if (L < valT) {
                    int hi = min(R - 1, valT - 1);
                    if (hi >= L) x = hi - L + 1;
                }

                int y = 0;
                int lo = max(L, S);
                if (lo <= R - 1) y = R - lo;

                addFirst(root[v], x, -2);
                addLast(root[v], y, +2);
            }

            val[v] = base + llabs(2LL * cntPlus[v] - szSub[v]);
        }

        ll ans = val[1] + sumNegative(root[1]);
        cout << ans << endl;
    }
}