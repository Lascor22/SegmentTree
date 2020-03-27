#ifndef TREE_TREE_H
#define TREE_TREE_H

#include <cstddef>
#include <vector>



struct Tree {
    struct Node {
        int left;
        int right;
        long long value;
        bool isSet;
        long long change;
    };

    explicit Tree(size_t size, const std::vector <long long> &a);

    long long int min(int left, int right);

    void add_on_segment(int left, int right, long long x);

    void set_on_segment(int left, int right, long long x);

    ~Tree();

private:
    std::vector <Node> tree;

    int pow2(int n);

    bool isList(int v);

    void treeBuild(std::vector <long long> &a, int i, int treeLeft, int treeRight);

    void _set(int left, int right, long long x, int v);

    void _add(int left, int right, long long x, int v);

    void push(int v);

    long long _min(int left, int right, int v);
};


#endif //TREE_TREE_H
