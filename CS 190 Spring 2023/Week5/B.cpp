#include <iostream>
#include <vector>

using namespace std;

struct Node{
    //Node* parent = nullptr;
    vector<Node*> child;
    bool isTraitor = false;
    int familySize = 0;
};

int familySize(Node* root){
    int size = 1;
    for (unsigned i = 0; i < root->child.size(); i++){
        if (root->child.at(i)->isTraitor == false){
            size += familySize(root->child.at(i));
        }   
            
    }
    return size;
}

int main()
{
    vector<Node*> list;
    vector<Node*> traitorsList;
    
    int size;
    int traitors;
    int max = 0;

    cin >> size >> traitors;
    size --;

    Node* tempNode = new Node();
    list.push_back(tempNode);

    for (unsigned i = 0; i < size; i++){
        Node* tempNode = new Node();
        list.push_back(tempNode);
    }

    for (int i = 0; i < size; i++){
        int temp;
        cin >> temp;
        list.at(temp)->child.push_back(list.at(i+1));
        
    }

    for (unsigned i = 0; i < traitors; i++){
        int temp;
        cin >> temp;
        list.at(temp)->isTraitor = true;
        list.at(temp)->familySize = -99;
        traitorsList.push_back(list.at(temp));
    }
    if (!list.at(0)->isTraitor){
        list.at(0)->familySize = familySize(list.at(0));
        max = list.at(0)->familySize;
    }


    for (unsigned i = 0; i < traitorsList.size(); i++){
        for (int j = 0; j < traitorsList.at(i)->child.size(); j++){
            if(!traitorsList.at(i)->child.at(j)->isTraitor){
                traitorsList.at(i)->child.at(j)->familySize = familySize(traitorsList.at(i)->child.at(j));
                if (traitorsList.at(i)->child.at(j)->familySize > max){
                    max = traitorsList.at(i)->child.at(j)->familySize;
                }
            }
        }
    }

    cout << max;
    


    return 0;
}
