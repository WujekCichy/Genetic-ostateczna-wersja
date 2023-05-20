#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <algorithm>

using namespace std;

// funkcja generująca losowy graf o V wierzchołkach i E krawędziach
void generateGraph(int V, int E, string filename) {
    vector<pair<int, int>> edges;
    // generator liczb losowych
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, V - 1);
    // generowanie E krawędzi
    for (int i = 0; i < E; i++) {
        int u = dis(gen);
        int v = dis(gen);
        if (u != v) {
            edges.emplace_back(min(u, v), max(u, v));
        }
        else {
            i--;
        }
    }
    // sortowanie krawędzi
    sort(edges.begin(), edges.end());
    edges.erase(unique(edges.begin(), edges.end()), edges.end());
    //string filename = "dane.txt";
    ofstream out(filename);
    out << V << endl;
    for (const auto& edge : edges) {
        out << edge.first << " " << edge.second << endl;
    }
}

int main() {
    int V, E;
    string filename;
    //cout << "Podaj liczbę wierzchołków i krawędzi: ";
    //cin >> V >> E;
    for (int i = 1; i <= 3; i++)
    {
        V = i * 100;
        for (int j = 1; j <=5; j++)
        {
            E = V * j;
            filename = "dane_";
            filename += char(i + 48);
            filename += "_";
            filename += char(j + 48);
            filename += ".txt";
            generateGraph(V, E, filename);
        }
    }
    //generateGraph(V, E,filename);
    return 0;
}
