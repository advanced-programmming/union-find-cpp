#include <iostream>
#include <vector>

using namespace std;

int main () {


}

class UnionFind {
    public :
    int size;
    vector<int> control;

    UnionFind(int size){
        size = size;
        control = new vector(size);

        for(int i = 0; i <= size; i++)
            control[i] = -1;
    }

    int find(int i){
        if(control[i] == -1) return i;
        return find(control[i]);
    }

    bool uni(int node1, int node2){
        int parent1 = find(node1);
        int parent2 = find(node2);

        if(parent1 != parent2){
            if(parent1 < parent2){
                int value = control[parent1];
                control[parent1] = value - 1;
                control[node2] = node1;
            } else {
                int value = control[parent2];
                control[parent2] = value - 1;
                control[node1] = node2;
            }
        }

        return true;
    }
};