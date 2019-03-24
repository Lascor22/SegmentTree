#include "Tree.h"
#include <limits.h>

typedef long long ll;

Tree::Tree(size_t size, const vector <ll> &a) {
    vector <ll> temp = a;
    int n = pow2(size);
    tree.resize(static_cast<unsigned int>(4 * n));
    for (int i = size; i < n; i++) {
        temp.push_back(LONG_LONG_MAX);
    }
    treeBuild(temp, 0, 0, n - 1);
}

int Tree::pow2(int n) {
    int res = 1;
    while (res < n) {
        res *= 2;
    }
    return res;
}

bool Tree::isList(int v) {
    return tree[v].left == tree[v].right;
}

void Tree::treeBuild(vector <ll> &a, int i, int treeLeft, int treeRight) {
    if (treeRight == treeLeft) {
        tree[i].value = a[treeLeft];
        tree[i].left = treeRight;
        tree[i].right = treeLeft;
        tree[i].isSet = false;
        tree[i].change = 0;
        return;
    }
    int treeMid = (treeLeft + treeRight) / 2;
    treeBuild(a, 2 * i + 1, treeLeft, treeMid);
    treeBuild(a, 2 * i + 2, treeMid + 1, treeRight);
    tree[i].value = std::min(tree[2 * i + 1].value, tree[2 * i + 2].value);
    tree[i].left = tree[2 * i + 1].left;
    tree[i].right = tree[2 * i + 2].right;
}

void Tree::_set(int left, int right, ll x, int v) {
    push(v);
    if (tree[v].left > right || tree[v].right < left) {
        return;
    }
    if (left <= tree[v].left && tree[v].right <= right) {
        if (isList(v)) {
            tree[v].value = x;
            tree[v].isSet = false;
            tree[v].change = 0;
        } else {
            push(v);
            tree[v].isSet = true;
            tree[v].change = x;
        }
        return;
    }
    push(v);
    _set(left, right, x, 2 * v + 1);
    _set(left, right, x, 2 * v + 2);
    push(2 * v + 1);
    push(2 * v + 2);
    tree[v].value = std::min(tree[2 * v + 1].value, tree[2 * v + 2].value);
}

void Tree::_add(int left, int right, ll x, int v) {
    push(v);
    if (tree[v].left > right || tree[v].right < left) {
        return;
    }
    if (left <= tree[v].left && tree[v].right <= right) {
        if (isList(v)) {
            tree[v].value += x;
            tree[v].change = 0;
        } else {
            push(v);
            tree[v].change = x;
        }
        return;
    }
    push(v);
    _add(left, right, x, 2 * v + 1);
    _add(left, right, x, 2 * v + 2);
    push(2 * v + 1);
    push(2 * v + 2);
    tree[v].value = std::min(tree[2 * v + 1].value, tree[2 * v + 2].value);
}

void Tree::push(int v) {
    if (tree[v].isSet) {
        if (isList(2 * v + 1)) {
            tree[2 * v + 1].value = tree[v].change;
            tree[2 * v + 1].isSet = false;
            tree[2 * v + 1].change = 0;
        } else {
            tree[2 * v + 1].isSet = true;
            tree[2 * v + 1].change = tree[v].change;
        }
        if (isList(2 * v + 2)) {
            tree[2 * v + 2].value = tree[v].change;
            tree[2 * v + 2].isSet = false;
            tree[2 * v + 2].change = 0;
        } else {
            tree[2 * v + 2].isSet = true;
            tree[2 * v + 2].change = tree[v].change;
        }
        tree[v].isSet = false;
        tree[v].value = tree[v].change;
        tree[v].change = 0;
    } else {
        tree[2 * v + 1].change += tree[v].change;
        tree[2 * v + 2].change += tree[v].change;
        tree[v].value += tree[v].change;
        tree[v].change = 0;
    }
}

ll Tree::_min(int left, int right, int v) {
    push(v);
    if (tree[v].left > right || tree[v].right < left) {
        return LONG_LONG_MAX;
    }
    if (left <= tree[v].left && tree[v].right <= right) {
        push(v);
        return tree[v].value;
    }
    push(v);
    long long ans = std::min(_min(left, right, 2 * v + 1), _min(left, right, 2 * v + 2));
    push(2 * v + 1);
    push(2 * v + 2);
    tree[v].value = std::min(tree[2 * v + 1].value, tree[2 * v + 2].value);
    return ans;
}

long long int Tree::min(int left, int right) {
    return _min(left - 1, right - 1, 0);
}

void Tree::add_on_segment(int left, int right, ll x) {
    _add(left - 1, right - 1, x, 0);
}

void Tree::set_on_segment(int left, int right, ll x) {
    _set(left - 1, right - 1, x, 0);
}

Tree::~Tree() {
    tree.resize(0);
}
