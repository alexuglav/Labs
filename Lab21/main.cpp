#include "graph.h"
#include <QApplication>
#include <queue>
#include <iostream>
#include <Windows.h>
using namespace std;

vector <vector<int>> mat = { {0, 34, 8, 0, 2, 23 },
                             {27, 0, 60, 50, 8, 0 },
                             {8, 60, 0, 0, 0, 0 },
                             {0, 50, 0, 0, 4, 0 },
                             {2, 8, 0, 4, 0, 15 },
                             {23, 0, 0, 0, 15, 0 } };
int result[6] = { INT_MAX, INT_MAX, INT_MAX, INT_MAX,INT_MAX, INT_MAX };
bool visited[6] = { 0, 0, 0, 0, 0, 0 };
void Dejkstra();

int main(int argc, char *argv[])
{

    cout << "Shortest paths from each point" << endl;
    Dejkstra();
    QApplication a(argc, argv);
    Graph w;
    w.show();
    return a.exec();
}

void Dejkstra()
{
    int top = 0; //вершина с номером 1
    queue<int> line;
    line.push(top);
    result[0] = 0;
    while (!line.empty()) {
        int vertex = line.front();
        line.pop();
        for (int i = 0; i < mat[vertex].size(); i++) {
            if (!visited[i] && mat[vertex][i] && (mat[vertex][i] + result[vertex] < result[i])) {
                result[i] = mat[vertex][i] + result[vertex];
                line.push(i);
            }
        }
    }
    for (int i = 0; i < 6; i++) {
        cout << i + 1 << ": " << result[i] << endl;
    }
}
