#include "Graph.h"

#define INFINITY 100000

void Graph::addEl(int v1, int v2, int r) {
	if ((getVertex(v1) != nullptr) && (getVertex(v2) != nullptr)) {
		Vertex* first = getVertex(v1);
		Vertex* second = getVertex(v2);
		first->neighbours.push_back(make_pair(second, r));
		second->neighbours.push_back(make_pair(first, r));
	}
	else {
		if (getVertex(v1) == nullptr) {
			Vertex* v = new Vertex(v1);
			vertices.push_back(v);
		}
		if (getVertex(v2) == nullptr) {
			Vertex* v = new Vertex(v2);
			vertices.push_back(v);
		}
		Vertex* first = getVertex(v1);
		Vertex* second = getVertex(v2);
		first->neighbours.push_back(make_pair(second, r));
		second->neighbours.push_back(make_pair(first, r));
	}
}

void Graph::outGraph() {
	for (int j = 0; j < vertices.size(); j++) {
		cout << vertices[j]->ID << ": ";
		for (int i = 0; i < vertices[j]->neighbours.size(); i++) {
			cout << vertices[j]->neighbours[i].first->ID
				<< "(" << vertices[j]->neighbours[i].second << ") ";
		}
		cout << '\n';
	}
}

Graph::Vertex* Graph::getVertex(int ID) {
	for (int i = 0; i < vertices.size(); i++) {
		if (vertices[i]->ID == ID) {
			return vertices[i];
		}
	}
	return nullptr;
}

void Graph::setBellFord()
{
	int numVertex = vertices.size();
	int indexVertex;

	cin >> indexVertex;

	vector<int> distances;
	vector<int> tempDistances;
	distances.resize(numVertex);

	for (int col = 0; col < numVertex; col++)
	{
		distances[col] = INFINITY;
	}

	distances[indexVertex - 1] = 0;

	for (int k = 0; k < numVertex - 1; k++)
	{
		for (int row = 0; row < numVertex; row++)
		{
			if (row == indexVertex - 1) { break; }
			for (int col = 0; col < numVertex; col++)
			{
				if (distances[row] > distances[row] + matrix[row][col])
				{
					distances[row] = distances[row] + matrix[row][col];
				}
			}
		}
	}

	for (auto& distance : distances)
	{
		cout << " " << distance;
	}
	
}

//void Graph::setBellFord(int v1, int v2)
//{
//	int numVertex = vertices.size();
//
//	vector<int> distances;
//	distances.resize(numVertex);
//	distances[v1-1] = 0;
//	for (int i = 0; i < numVertex; i++) {
//		if (i != v1-1) distances[i] = INFINITY;
//	}
//	
//	for (int i = 0; i < numVertex; i++) {
//		if (matrix[j][i] != INFINITY && distances[i] > distances[i] + matrix[v1][i]) {
//				distances[i] = distances[i] + matrix[v1][i];
//		}
//	}
//
//}

void Graph::buildMatrix()
{
	int numVertex = vertices.size();
	matrix = new int* [numVertex];
	for (int i = 0; i < numVertex; i++) { matrix[i] = new int[numVertex]; }

	for (int row = 0; row < numVertex; row++)
	{
		for (int col = 0; col < numVertex; col++)
		{
			matrix[row][col] = INFINITY;
		}
	}

	for (auto& currentVetrex : vertices)
	{
		for (auto& adjacentVertex : currentVetrex->neighbours)
		{
			matrix[currentVetrex->ID - 1][adjacentVertex.first->ID - 1] = adjacentVertex.second;
		}

	}

	for (int row = 0; row < numVertex; row++)
	{
		for (int col = 0; col < numVertex; col++)
		{
			cout << " " << matrix[row][col];
		}
		cout << endl;
	}
}