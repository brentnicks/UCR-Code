#include <iostream>
#include <queue>
#include <set>

using namespace std;

struct Node{
    char x;
    int y;
    int move = 0;
};

int main(){
    

    int blockCount;
    int curr = 0;
    cin >> blockCount;
    while (blockCount != -1){
        curr++;
        queue<Node*> q;
        set<pair<char,int>> s;

        char xStart, xFinish;
        int yStart,yFinish;
        bool found = false;

        for (int i = 0; i < blockCount; i++){
            char c;
            int x;
            cin >> c >> x;
            s.insert({c,x});
        }

        cin >> xStart >> yStart >> xFinish >> yFinish;
        //cout << xStart << yStart << endl << xFinish << yFinish << endl;

        Node* start = new Node();
        start->x = xStart;
        start->y = yStart;
        q.push(start);
        while (q.size() != 0){
            //cout << q.size() << endl;
            if (q.front()->x == xFinish && q.front()->y == yFinish){
                cout << "Board " << curr << ": " << q.front()->move << " moves" << endl;
                found = true;
                break;
            }
            if (q.front()->x + 2 <= 'h' && q.front()->y + 1 <= 8){ //right and up
                if (s.count({q.front()->x + 2,q.front()->y + 1}) == 0){
                Node* temp = new Node();
                temp->x = q.front()->x + 2;
                temp->y = q.front()->y + 1;
                temp->move = q.front()->move + 1;
                q.push(temp);
                //cout << "right and up" << endl;
                //if doesnt work then insert pos into s
                s.insert({q.front()->x + 2,q.front()->y + 1});
                }
            }
            if (q.front()->x + 2 <= 'h' && q.front()->y - 1 >= 1){ //right and down
                if (s.count({q.front()->x + 2,q.front()->y - 1}) == 0){
                Node* temp = new Node();
                temp->x = q.front()->x + 2;
                temp->y = q.front()->y - 1;
                temp->move = q.front()->move + 1;
                q.push(temp);
                //cout << "right and down" << endl;
                s.insert({q.front()->x + 2,q.front()->y - 1});
                }
            }
            if (q.front()->x - 2 >= 'a' && q.front()->y + 1 <= 8){ //left and up
                if (s.count({q.front()->x - 2,q.front()->y + 1}) == 0){
                Node* temp = new Node();
                temp->x = q.front()->x - 2;
                temp->y = q.front()->y + 1;
                temp->move = q.front()->move + 1;
                q.push(temp);
                s.insert({q.front()->x - 2,q.front()->y + 1});
                //if doesnt work then insert pos into s
                //cout << "left and up" << endl;
                }
            }
            if (q.front()->x - 2 >= 'a' && q.front()->y - 1 >= 1){ //left and down
                if (s.count({q.front()->x - 2,q.front()->y - 1}) == 0){
                Node* temp = new Node();
                temp->x = q.front()->x - 2;
                temp->y = q.front()->y - 1;
                temp->move = q.front()->move + 1;
                q.push(temp);
                //cout << "left and down" << endl;
                s.insert({q.front()->x - 2,q.front()->y - 1});
                }
            }

            //other 4 options

            if (q.front()->x + 1 <= 'h' && q.front()->y + 2 <= 8){ //right and up
                if (s.count({q.front()->x + 1,q.front()->y + 2}) == 0){
                Node* temp = new Node();
                temp->x = q.front()->x + 1;
                temp->y = q.front()->y + 2;
                temp->move = q.front()->move + 1;
                q.push(temp);
                //cout << "right and up" << endl;
                //if doesnt work then insert pos into s
                s.insert({q.front()->x + 1,q.front()->y + 2});
                }
            }
            if (q.front()->x + 1 <= 'h' && q.front()->y - 2 >= 1){ //right and down
                if (s.count({q.front()->x + 1,q.front()->y - 2}) == 0){
                Node* temp = new Node();
                temp->x = q.front()->x + 1;
                temp->y = q.front()->y - 2;
                temp->move = q.front()->move + 1;
                q.push(temp);
                //cout << "right and down" << endl;
                s.insert({q.front()->x + 1,q.front()->y - 2});
                }
            }
            if (q.front()->x - 1 >= 'a' && q.front()->y + 2 <= 8){ //left and up
                if (s.count({q.front()->x - 1,q.front()->y + 2}) == 0){
                Node* temp = new Node();
                temp->x = q.front()->x - 1;
                temp->y = q.front()->y + 2;
                temp->move = q.front()->move + 1;
                q.push(temp);
                //if doesnt work then insert pos into s
                //cout << "left and up" << endl;
                s.insert({q.front()->x - 1,q.front()->y + 2});
                }
            }
            if (q.front()->x - 1 >= 'a' && q.front()->y - 2 >= 1){ //left and down
                if (s.count({q.front()->x - 1,q.front()->y - 2}) == 0){
                Node* temp = new Node();
                temp->x = q.front()->x - 1;
                temp->y = q.front()->y - 2;
                temp->move = q.front()->move + 1;
                q.push(temp);
                //cout << "left and down" << endl;
                s.insert({q.front()->x - 1,q.front()->y - 2});
                }
            }
            q.pop();
        }
        if (!found) cout << "Board " << curr << ": not reachable" << endl;
        cin >> blockCount;
    }
    


    return 0;
}