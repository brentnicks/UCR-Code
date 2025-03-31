#include <iostream>
#include <vector>

using namespace std;

struct Node{
    vector<*Node> adjacent;
    bool visited = false;
    bool inCycle = false;
    int cycleLength = 0;
};

void DFS(Node* curr, Node* prev){
    curr->visited = true;
    for (Node* n : curr->adjacent){
        if (!n->visited && n != prev){
            DFS(n); 
        }
    }
}

int main(){
    vector<*Node> nodes;
    int size;
    cin >> size;
    for (int i = 0; i < size; i++){
        Node* temp = new Node();
        nodes.push_back(temp);
    }
    for (int i = 0; i < size; i++){
        int n1, n2;
        cin >> n1 >> n2;
        nodes.at(n1 - 1)->adjacent.push_back(nodes.at(n2 - 1));
        nodes.at(n2 - 1)->adjacent.push_back(nodes.at(n1 - 1));
    }

    for (int i = 0; i < size; i++){

    }


    return 0;
}