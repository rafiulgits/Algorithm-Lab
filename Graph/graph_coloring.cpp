#include <vector>
#include <iostream>
#include <stdbool.h>
#include <stdio.h>

#define BLOCKED -1

using namespace std;

/**
    @author Rafiul Islam

    @param MAX_NODES - maximum node of the presented graph
    @param graph 1D - vector for adjacent nodes of the graph
    @param color 2D - array initialize with 0 as global for color picking]
    @param visited - for ignore traversing previous solved nodes
*/

const int MAX_NODES = 20;
vector<int>graph[MAX_NODES];
int color[MAX_NODES][MAX_NODES];
bool visited[MAX_NODES] = {false};

/// function prototypes
void graph_color(int nodes);

/// driver function
int main()
{
    int nodes, edges; // declare nodes and edges
    cin >> nodes >> edges; // define values from user input

    // input adjacent nodes from user
    for(int i=0, n1, n2; i<edges; i++){
        cin >> n1 >> n2;
        graph[n1].push_back(n2);
        graph[n2].push_back(n1);
    }

    graph_color(nodes); // solution function call

    return 0;
}

/**
    As the color matrix (2D array) defined in global area; it will be initialize
    with 0 value as default. For every node of the graph function will find out
    the next available 0 for its current row, the column gonna be its selected color.
    Then make all its adjacent block to pick this selected color letter.

    @param nodes - graph nodes
    @return - no return
*/
void graph_color(int nodes)
{
    int selected = -1;

    for(int i=0; i<nodes; i++){
        visited[i] = true; // make current node visited

        /// find out next available color
        for(int j=0; j<nodes; j++){
            /// for available color value should be 0 not -1
            if(color[i][j] != BLOCKED){
                selected = j; // update selected index
                printf("Node %d Colored with : %d\n", i, selected); // print
                break; // color found, now break
            }
        }

        /// block all its adjacent nodes to pick the selected color
        for(int j=0; j<graph[i].size(); j++){
            int now = graph[i][j];

            // check whether this adjacent already solved or not
            if(!visited[now]){
                // block every adjacent to pick this color
                color[now][selected] = BLOCKED;
                printf("\t Node %d blocked for %d\n", now, selected); // print that block
            }
        }
    }
}
