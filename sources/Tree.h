#ifndef TREE_TREE_H
#define TREE_TREE_H

#include <cstddef>
#include <vector>

using std::vector;
typedef long long ll;

struct Node {
    int left;
    int right;
    long long value;
    bool isSet;
    long long change;
};

struct Tree {
    explicit Tree(size_t size, const vector <ll> &a);

    long long int min(int left, int right);

    void add_on_segment(int left, int right, ll x);

    void set_on_segment(int left, int right, ll x);

    ~Tree();

private:
    vector <Node> tree;

    int pow2(int n);

    bool isList(int v);

    void treeBuild(vector <ll> &a, int i, int treeLeft, int treeRight);

    void _set(int left, int right, ll x, int v);

    void _add(int left, int right, ll x, int v);

    void push(int v);

    ll _min(int left, int right, int v);
};


#endif //TREE_TREE_H
