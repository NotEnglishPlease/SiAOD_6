#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Graph {
public:
	struct Vertex
	{
		int ID;
		vector<pair<Vertex*, int>> neighbours;
		Vertex(int ID)
		{
			this->ID = ID;
		}
	};
	vector<Vertex*> vertices;
	int** matrix;
	void addEl(int v1, int v2, int r);
	void outGraph();
	void setBellFord();
	void setBellFord(int v1, int v2);
	void buildMatrix();
	Vertex* getVertex(int ID);
};