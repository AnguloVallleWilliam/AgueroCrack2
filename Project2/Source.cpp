#pragma once
#pragma once
#include<iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

class Grafo {
	int size;
	vector<vector<int>> pesos;

	void printPath(int a, int b, vector<int> path, function<void(int, vector<int>)> print = [=](int b, vector<int> path) {
		cout << b << "<";

		for (int i = b - 1; path[i] != -1; i = path[i]) {
			cout << path[i] + 1;
			if (path[path[i]] != -1) cout << "<";
		}
		cout << endl;
	}) {
		print(b, path);
	}

	void printPeso(int a, int b, vector<int> path) {
		int peso = 0;

		for (int i = b - 1; path[i] != -1; i = path[i]) {
			peso += pesos[i][path[i]];
		}
		cout << peso << endl;
	}

public:
	Grafo(int n) : size(n), pesos(n, vector<int>(n, 0)) {}

	void Add(int a, int b, int peso) {
		if (a != b) {
			pesos[a - 1][b - 1] = peso;
			pesos[b - 1][a - 1] = peso;
		}
	}

	void BFS(int a, int b) {
		queue<int> Q;
		int v;
		vector<bool> visited(size, false);
		vector<int> path(size, -1);

		visited[a - 1] = true;
		Q.push(a);

		while (!Q.empty()) {
			v = Q.front();
			Q.pop();
			cout << v << " ";

			for (int i = 0; i < size; i++) {
				if (pesos[v - 1][i] != 0 && !visited[i]) {
					visited[i] = true;
					Q.push(i + 1);
					path[i] = v - 1;
				}
			}
		}
		cout << endl;

		printPath(a, b, path);
		printPeso(a, b, path);
	}
	void Dijkstra(int a, int b) {
		struct Node {
			int node, peso;

			Node(int node, int peso) : node(node), peso(peso) {}
		};

		vector<int> distance(size, INT_MAX), prev(size, -1), aux;
		vector<bool> set(size, false);
		vector<Node*> nodes;
		int v;

		aux.push_back(a);
		distance[a - 1] = 0;

		while (!aux.empty()) {
			nodes.clear();
			v = aux.front();
			aux.erase(aux.begin());

			for (int i = 0; i < size; i++) {
				if (pesos[v - 1][i] != 0 && !set[i]) {
					if (distance[v - 1] + pesos[v - 1][i] < distance[i]) {
						distance[i] = distance[v - 1] + pesos[v - 1][i];
						prev[i] = v - 1;
						nodes.push_back(new Node(i + 1, distance[i]));
					}
				}
			}
			for (unsigned int i = 0; i < nodes.size(); i++) {
				for (unsigned int j = i; j < nodes.size(); j++) {
					if (nodes[i]->peso > nodes[j]->peso) swap(nodes[i], nodes[j]);
				}
			}
			for (unsigned int i = 0; i < nodes.size(); i++) aux.push_back(nodes[i]->node);

			set[v - 1] = true;
		}

		printPath(a, b, prev);
		printPeso(a, b, prev);
	}

	void printMatrix() {
		int n = pesos.size();

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << pesos[i][j] << " ";
			}
			cout << endl;
		}
	}
};
//////////////////////
#pragma once
#include<iostream>
#include<cstdio>
#include<sstream>
#include<algorithm>
#include<sstream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
typedef vector<vector<int>> Graph;
vector<int> bfs(Graph G, int s)
{
	int n = G.size();
	vector<bool> visited(n, false);
	vector<int> path(n);
	queue<int> q;
	q.push(s);
	visited[s] = true;
	while (!q.empty())
	{
		auto u = q.front();
		for (auto v : G[u])
		{
			if (!visited[v])
			{
				path[u] = v;
				visited[v] = true;
				q.push(v);
				q.pop();
			}

		}

	}

	return path;
}
void recorre_gra(vector<int> pat)
{
	for (vector<int>::iterator it = pat.begin(); it != pat.end(); it++)
	{
		cout << *it << endl;
	}
}

class Grafito
{
	int NumVertc;

	vector<vector<int>> vectr;
public:
	Grafito(int NumVe) : NumVertc(NumVe), vectr(NumVertc) {}
	void agregaesquinas(int v, int w)
	{
		vectr[v].push_back(w);
	}
	void BFS(int vs)
	{
		vector<bool> visited(NumVertc, false);
		queue<int> q;

		visited[vs] = true;
		q.push(vs);
		//mete a la cola

		while (!q.empty())
		{
			vs = q.front();
			cout << vs << " ";
			q.pop();

			for (vector<int>::iterator i = vectr[vs].begin(); i != vectr[vs].end(); i++)
			{
				if (!visited[*i])
				{
					visited[*i] = true;
					q.push(*i);
				}
			}

		}

	}
	void DFS(int vs)
	{
		vector<bool> visited1(NumVertc, false);
		stack<int> st;
		cout << vs << " ";
		visited1[vs] = true;
		st.push(vs);
		while (!visited1[vs])
		{
			for (vector<int>::iterator i = vectr[vs].begin(); i != vectr[vs].end(); i++)
			{

			}

		}



	}
};
///////////////////////////////////////
#ifndef __BST_H__
#define __BST_H__

#include <functional>
#include<vector>
#include<sstream>
#include<string>
using namespace std;
template<typename T, typename Comparable = T, T NONE = 0>
class AVLTree {
	struct Node {
		T     elem;
		int   h;
		int   n;
		Node* left;
		Node* right;

		Node(T elem)
			: elem(elem), left(nullptr), right(nullptr), h(0), n(1) {}
	};
	int len;
	Node* root;
	vector<T>  vec;
	std::function<Comparable(T)>  key;
	void Clean_Tree(Nodo* node)
	{
		if (node != nullptr)
		{


			Clean_Tree(node->left);
			Clean_Tree(node->right);

			len = len - 1;
			node = nullptr;
			if (len != 0)
			{
				delete node;
			}

			if (len == 0)
			{
				root->left = nullptr;
				root->right = nullptr;
				root = nullptr;
				//Lista_Enlazada->Clean_List();
			}
		}
	}

	void destroy(Node* node) {
		if (node != nullptr) {
			destroy(node->left);
			destroy(node->right);
			delete node;
		}
	}
	Node* add(Node* node, T elem) {
		if (node == nullptr) {
			node = new Node(elem);
		}
		else {
			if (key(elem) > key(node->elem)) {
				node->right = add(node->right, elem);
			}
			else {
				node->left = add(node->left, elem);
			}
			node = balance(node);
		}
		return node;
	}
	void inorder(Node* node, std::function<void(T)> proc) {
		if (node != nullptr) {
			inorder(node->left, proc);
			proc(node->elem);
			inorder(node->right, proc);
		}
	}
	T find(Node* node, Comparable val) {
		if (node == nullptr) {
			return NONE;
		}
		if (val == key(node->elem)) {
			return node->elem;
		}
		else if (val < key(node->elem)) {
			return find(node->left, val);
		}
		else {
			return find(node->right, val);
		}
	}

	/* BALANCEO */
	int height(Node* node) {
		return node == nullptr ? -1 : node->h;
	}
	int length(Node* node) {
		return node == nullptr ? 0 : node->n;
	}
	void updateHeight(Node* node) {
		int hl = height(node->left);
		int hr = height(node->right);
		node->h = 1 + (hl > hr ? hl : hr);
	}
	Node* rotRight(Node* node) {
		Node* aux = node->left;
		node->left = aux->right;
		aux->right = node;
		updateHeight(aux->right);
		updateHeight(aux);
		return aux;
	}
	Node* rotLeft(Node* node) {
		Node* aux = node->right;
		node->right = aux->left;
		aux->left = node;
		updateHeight(aux->left);
		updateHeight(aux);
		return aux;
	}
	Node* balance(Node* node) {
		int hl = height(node->left);
		int hr = height(node->right);
		if (hl - hr < -1) {
			if (height(node->right->left) > height(node->right->right)) {
				node->right = rotRight(node->right);
			}
			node = rotLeft(node);
		}
		else if (hl - hr > 1) {
			if (height(node->left->right) > height(node->left->left)) {
				node->left = rotLeft(node->left);
			}
			node = rotRight(node);
		}
		else {
			updateHeight(node);
		}
		return node;
	}
	void mostrar_datos_vector(Node * node)
	{
		if (node = !nullptr && len > 0)
		{
			mostrar_datos_vector(node->left);
			vec.push_back(node->elem);
			mostrar_datos_vector(node->right);
		}
	}

public:
	AVLTree(std::function<Comparable(T)>  key = [](T a) {return a; })
		: key(key), root(nullptr), len(0) {}
	~AVLTree() {
		destroy(root);
	}
	int height() {
		return height(root);
	}
	int length() {
		return length(root);
	}
	void add(T elem) {
		root = add(root, elem);
	}
	bool remove(Comparable val) {
		Node* aux = root;
		Node* parent;
		bool left;
		while (aux != nullptr) {
			if (val == key(aux->elem)) {
				break;
			}
			else {
				parent = aux;
				if (val < key(aux->elem)) {
					left = true;
					aux = aux->left;
				}
				else {
					left = false;
					aux = aux->right;
				}
			}
		}
		if (aux == nullptr) return false;
		if (aux->left == nullptr) {
			if (aux == root)  root = aux->right;
			else if (left)    parent->left = aux->right;
			else              parent->right = aux->right;
			delete aux;
		}
		else {
			Node* aux2 = aux->left;
			while (aux2->right != nullptr) {
				parent = aux2;
				aux2 = aux2->right;
			}
			if (aux2 == aux->left) {
				aux->left = aux2->left;
			}
			else {
				parent->right = aux2->left;
			}
			aux->elem = aux2->elem;
			delete aux2;
		}
		return true;
	}
	T find(Comparable val) {
		return find(root, val);
	}
	/*list<T>* findAll(Comparable val) {
	return nullptr; // TODO!!
	}*/

	void inorder(std::function<void(T)> proc) {
		inorder(root, proc);
	}

};

#endif
///////////////////////////////////////
#include <functional>

template <typename T>
class AVLTree {
	struct Node {
		T       e;
		Node*   l;
		Node*   r;
		int     h;

		Node(T e) : e(e), l(nullptr), r(nullptr), h(0) {}
	};

	Node*   root;
	int     nElems;

	std::function<int(T, T)> comp;

	int nodeHeight(Node* n) {
		return n == nullptr ? -1 : n->h;
	}
	void updateHeight(Node* n) {
		int hl = nodeHeight(n->l);
		int hr = nodeHeight(n->r);
		int max = hl > hr ? hl : hr;
		n->h = max + 1;
	}
	void rotR(Node*& n) {
		Node* aux = n->l;
		n->l = aux->r;
		aux->r = n;
		updateHeight(n);
		n = aux;
		updateHeight(n);
	}
	void rotL(Node*& n) {
		Node* aux = n->r;
		n->r = aux->l;
		aux->l = n;
		updateHeight(n);
		n = aux;
		updateHeight(n);
	}
	void balance(Node*& n) {
		int hl = nodeHeight(n->l);
		int hr = nodeHeight(n->r);
		if (hl - hr < -1) {
			int hrl = nodeHeight(n->r->l);
			int hrr = nodeHeight(n->r->r);
			if (hrl > hrr) {
				rotR(n->r);
			}
			rotL(n);
		}
		else if (hl - hr > 1) {
			int hll = nodeHeight(n->l->l);
			int hlr = nodeHeight(n->l->r);
			if (hlr > hll) {
				rotL(n->l);
			}
			rotR(n);
		}
		else {
			updateHeight(n);
		}
	}
	void add(Node*& n, T e) {
		if (n == nullptr) {
			n = new Node(e);
			++nElems;
		}
		else {
			if (comp(e, n->e) < 0) {
				add(n->l, e);
			}
			else {
				add(n->r, e);
			}
			balance(n);
		}
	}

public:
	AVLTree(std::function<int(T, T)> comp)
		: comp(comp), root(nullptr), nElems(0) {}
	int lenght() {
		return nElems;
	}
	int height() {
		return nodeHeight(root);
	}
	void add(T e) {
		add(root, e);
	}
};

#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

struct Registro {
	int a, b, c, d, e, f;
};

void createData(vector<Registro*>& data) {
	for (int i = 0; i < data.size(); i++) {
		data[i] = new Registro();
		data[i]->a = rand() % 9000 + 1000;
		data[i]->b = rand() % 9000 + 1000;
		data[i]->c = rand() % 9000 + 1000;
		data[i]->d = rand() % 9000 + 1000;
		data[i]->e = rand() % 9000 + 1000;
		data[i]->f = rand() % 9000 + 1000;
	}
}

void destroyData(vector<Registro*> data) {
	for (Registro* datum : data) {
		delete datum;
	}
}

int main() {
	int n = 1000000;
	vector<Registro*> data(n);
	createData(data);
	auto compB = [](Registro* a, Registro* b) { return a->b - b->b; };
	auto compC = [](Registro* a, Registro* b) { return a->c - b->c; };
	auto compE = [](Registro* a, Registro* b) { return a->e - b->e; };

	AVLTree<Registro*>* idxB = new AVLTree<Registro*>(compB);
	AVLTree<Registro*>* idxC = new AVLTree<Registro*>(compC);
	AVLTree<Registro*>* idxE = new AVLTree<Registro*>(compE);

	for (Registro* datum : data) {
		idxB->add(datum);
		idxC->add(datum);
		idxE->add(datum);
	}

	cout << idxB->height() << endl;
	cout << idxC->height() << endl;
	cout << idxE->height() << endl;

	destroyData(data);
	delete idxB;
	delete idxC;
	delete idxE;

	return 0;
}
///////////////////////////////////////
#ifndef __BST_H__
#define __BST_H__

#include <functional>

template<typename T, typename Comparable = T, T NONE = 0>
class AVLTree {
	struct Node {
		T     elem;
		int   h;
		int   n;
		Node* left;
		Node* right;

		Node(T elem)
			: elem(elem), left(nullptr), right(nullptr), h(0), n(1) {}
	};

	Node* root;

	std::function<Comparable(T)>  key;

	void destroy(Node* node) {
		if (node != nullptr) {
			destroy(node->left);
			destroy(node->right);
			delete node;
		}
	}
	Node* add(Node* node, T elem) {
		if (node == nullptr) {
			node = new Node(elem);
		}
		else {
			if (key(elem) > key(node->elem)) {
				node->right = add(node->right, elem);
			}
			else {
				node->left = add(node->left, elem);
			}
			node = balance(node);
		}
		return node;
	}
	void inorder(Node* node, std::function<void(T)> proc) {
		if (node != nullptr) {
			inorder(node->left, proc);
			proc(node->elem);
			inorder(node->right, proc);
		}
	}
	T find(Node* node, Comparable val) {
		if (node == nullptr) {
			return NONE;
		}
		if (val == key(node->elem)) {
			return node->elem;
		}
		else if (val < key(node->elem)) {
			return find(node->left, val);
		}
		else {
			return find(node->right, val);
		}
	}

	/* BALANCEO */
	int height(Node* node) {
		return node == nullptr ? -1 : node->h;
	}
	int length(Node* node) {
		return node == nullptr ? 0 : node->n;
	}
	void updateHeight(Node* node) {
		int hl = height(node->left);
		int hr = height(node->right);
		node->h = 1 + (hl > hr ? hl : hr);
	}
	Node* rotRight(Node* node) {
		Node* aux = node->left;
		node->left = aux->right;
		aux->right = node;
		updateHeight(aux->right);
		updateHeight(aux);
		return aux;
	}
	Node* rotLeft(Node* node) {
		Node* aux = node->right;
		node->right = aux->left;
		aux->left = node;
		updateHeight(aux->left);
		updateHeight(aux);
		return aux;
	}
	Node* balance(Node* node) {
		int hl = height(node->left);
		int hr = height(node->right);
		if (hl - hr < -1) {
			if (height(node->right->left) > height(node->right->right)) {
				node->right = rotRight(node->right);
			}
			node = rotLeft(node);
		}
		else if (hl - hr > 1) {
			if (height(node->left->right) > height(node->left->left)) {
				node->left = rotLeft(node->left);
			}
			node = rotRight(node);
		}
		else {
			updateHeight(node);
		}
		return node;
	}

public:
	AVLTree(std::function<Comparable(T)>  key = [](T a) {return a; })
		: key(key), root(nullptr) {}
	~AVLTree() {
		destroy(root);
	}
	int height() {
		return height(root);
	}
	int length() {
		return length(root);
	}
	void add(T elem) {
		root = add(root, elem);
	}
	bool remove(Comparable val) {
		Node* aux = root;
		Node* parent;
		bool left;
		while (aux != nullptr) {
			if (val == key(aux->elem)) {
				break;
			}
			else {
				parent = aux;
				if (val < key(aux->elem)) {
					left = true;
					aux = aux->left;
				}
				else {
					left = false;
					aux = aux->right;
				}
			}
		}
		if (aux == nullptr) return false;
		if (aux->left == nullptr) {
			if (aux == root)  root = aux->right;
			else if (left)    parent->left = aux->right;
			else              parent->right = aux->right;
			delete aux;
		}
		else {
			Node* aux2 = aux->left;
			while (aux2->right != nullptr) {
				parent = aux2;
				aux2 = aux2->right;
			}
			if (aux2 == aux->left) {
				aux->left = aux2->left;
			}
			else {
				parent->right = aux2->left;
			}
			aux->elem = aux2->elem;
			delete aux2;
		}
		return true;
	}
	T find(Comparable val) {
		return find(root, val);
	}
	/*list<T>* findAll(Comparable val) {
	return nullptr; // TODO!!
	}*/

	void inorder(std::function<void(T)> proc) {
		inorder(root, proc);
	}
};
////////////////////////////////////////////////
#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>

#include "avl.h"

using namespace std;

enum Tipo { teoria, labcomp, labarq, cimlab, fablab, cubi };
class Salon {
	string nombre;
	Tipo tipo;
	int capacidad;

public:
	Salon(string nombre, Tipo tipo, int capacidad)
		: nombre(nombre), tipo(tipo), capacidad(capacidad) {}


	string getNombre() { return nombre; }
	Tipo getTipo() { return tipo; }
	int getCapacidad() { return capacidad; }
	void setnombre(string nombre) {
		this->nombre = nombre;
	}
	void settipo(Tipo tipo) {
		this->tipo = tipo;
	}
	void setcapacidad(int capacidad) {
		this->capacidad = capacidad;
	}
};
// https://repl.it/repls/UncomfortableSandyMozbot
int main() {
	typedef AVLTree<Salon*, string, nullptr> TNom;
	typedef AVLTree<Salon*, int, nullptr> TCap;

	auto knom = [](Salon* s) { return s->getNombre(); };
	auto kcap = [](Salon* s) { return s->getCapacidad(); };

	TNom* tnom = new TNom(knom);
	TCap* tcap = new TCap(kcap);

	auto px = [](Salon* s) {
		cout << "{"
			<< s->getNombre() << " "
			<< s->getTipo() << " "
			<< s->getCapacidad() << "}\n";
	};
	for (int i = 0; i < 1e6; ++i) {
		stringstream nom;
		nom << "U" << (char)('A' + rand() % 8)
			<< (1 + rand() % 8);
		Tipo tipo = (Tipo)(rand() % 6);
		int cap = 5 + rand() % 36;

		Salon* salon = new Salon(nom.str(), tipo, cap);
		//px(salon);
		tnom->add(salon);
		tcap->add(salon);
	}
	cout << tnom->height() << endl;
	//tnom->inorder(px);
	cout << tcap->height() << endl;
	//tcap->inorder(px);

	//px(t->find(labarq));

	delete tnom;
	delete tcap;
	return 0;
}
/////////////////////////////////////
#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <vector>
#include <map>
#include <string>
#include <iostream>

using namespace std;

class GraphNW {
	int n;
	vector<vector<char>> G;
	map<string, int> names;
	vector<string> revNames;

public:
	GraphNW(int n) : n(n), G(n, vector<char>(n, 0)) {}
	void addNode(string node) {
		if (names.size() < n) {
			names[node] = names.size();
			revNames.push_back(node);
		}
	}
	void addEdge(string nodeU, string nodeV) {
		int u = names[nodeU];
		int v = names[nodeV];
		G[u][v] = 1;
		G[v][u] = 1;
	}
	// búsqueda en profundidad
	void dfs(string strs, string strt) {
		int s = names[strs];
		vector<bool> visited(n, false);
		vector<int> path(n, -1);
		visited[s] = true;
		dfs(s, visited, path);
		int fin = names[strt];
		while (fin >= 0) {
			cout << revNames[fin] << " <- ";
			fin = path[fin];
		}
		cout << "\n";
	}

private:
	void dfs(int s, vector<bool>& visited, vector<int>& path) {
		for (int v = 0; v < n; ++v) {
			if (G[s][v] != 0 && !visited[v]) {
				visited[v] = true;
				path[v] = s;
				dfs(v, visited, path);
			}
		}
	}
};

#endif
///////////////////////////////////////
#include <iostream>
#include "graph.h"

int main() {
	GraphNW* g = new GraphNW(20);
	g->addNode("Oradea");
	g->addNode("Zerind");
	g->addNode("Arad");
	g->addNode("Timisoara");
	g->addNode("Lugoj");
	g->addNode("Mehadia");
	g->addNode("Dobreta");
	g->addNode("Craiova");
	g->addNode("Rimnicu Vilcea");
	g->addNode("Sibiu");
	g->addNode("Fagaras");
	g->addNode("Pitesti");
	g->addNode("Bucharest");
	g->addNode("Giurgiu");
	g->addNode("Urziceni");
	g->addNode("Hirsova");
	g->addNode("Vaslui");
	g->addNode("Neamt");
	g->addNode("Iasi");
	g->addNode("Eforie");
	g->addEdge("Oradea", "Zerind");
	g->addEdge("Oradea", "Sibiu");
	g->addEdge("Zerind", "Arad");
	g->addEdge("Arad", "Sibiu");
	g->addEdge("Arad", "Timisoara");
	g->addEdge("Timisoara", "Lugoj");
	g->addEdge("Lugoj", "Mehadia");
	g->addEdge("Mehadia", "Dobreta");
	g->addEdge("Dobreta", "Craiova");
	g->addEdge("Craiova", "Rimnicu Vilcea");
	g->addEdge("Rimnicu Vilcea", "Sibiu");
	g->addEdge("Craiova", "Pitesti");
	g->addEdge("Rimnicu Vilcea", "Pitesti");
	g->addEdge("Sibiu", "Fagaras");
	g->addEdge("Fagaras", "Bucharest");
	g->addEdge("Pitesti", "Bucharest");
	g->addEdge("Bucharest", "Giurgiu");
	g->addEdge("Bucharest", "Urziceni");
	g->addEdge("Urziceni", "Hirsova");
	g->addEdge("Urziceni", "Vaslui");
	g->addEdge("Hirsova", "Eforie");
	g->addEdge("Vaslui", "Iasi");
	g->addEdge("Iasi", "Neamt");

	g->dfs("Arad", "Timisoara");

	return 0;
}
/////////////////////////////
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector<vector<char>> Graph;

void _dfs(Graph G, int u, vector<bool>& visited, vector<int>& parent) {
	int n = G.size();
	if (!visited[u]) {
		visited[u] = true;
		for (int v = 0; v < n; ++v) {
			if (G[u][v] != 0 && !visited[v]) {
				parent[v] = u;
				_dfs(G, v, visited, parent);
			}
		}
	}
}
vector<int> dfs(Graph G, int s) {
	int n = G.size();
	vector<bool> visited(n, false);
	vector<int>  parent(n, -1);
	_dfs(G, s, visited, parent);
	return parent;
}

int main() {
	Graph G = { { 0,1,1,1,1,0,0,0 },
	{ 1,0,1,1,0,0,0,0 },
	{ 0,1,0,0,0,0,1,0 },
	{ 0,1,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,1 },
	{ 0,0,0,1,0,0,0,1 },
	{ 0,0,0,0,1,1,0,1 },
	{ 0,0,0,0,0,0,0,0 } };
	vector<int> parent = dfs(G, 0);
	for (auto e : parent) {
		cout << e << endl;
	}
	return 0;
}
//////////////////////////////
#pragma once
#pragma once

#include <functional>
#include <algorithm>
using namespace std;

template <typename T, typename R = T>
class AVL {
	struct Node {
		T e;
		Node* L;
		Node* R;
		int h;
		Node(T e) : e(e), L(nullptr), R(nullptr), h(0) {}
		static int height(Node* a) {
			if (a == nullptr) return -1;
			else return a->h;
		}
		void updateH() {
			h = max(height(L), height(R)) + 1;
		}
	};
	Node* root;
	int l;
	function<R(T)> key;
	void RotAB(Node*& a) {
		Node* aux = a->L;
		a->L = aux->R;
		a->updateH();
		aux->R = a;
		a = aux;
		a->updateH();
	}
	void RotBA(Node*& a) {
		Node* aux = a->R;
		a->R = aux->L;
		a->updateH();
		aux->L = a;
		a = aux;
		a->updateH();
	}
	Node* Buscar(R e, Node* f) {
		if (f == nullptr) return f;
		else if (e == key(f->e)) {
			return f;
		}
		else if (e < key(f->e)) {
			return Buscar(e, f->L);
		}
		else if (e > key(f->e)) {
			return Buscar(e, f->L);
		}
	}
	void balance(Node*& a) {
		int delta = Node::height(a->L) - Node::height(a->R);
		if (delta < -1) {
			if (Node::height(a->R->L) > Node::height(a->R->R)) {
				RotAB(a->R);
			}
			RotBA(a);
		}
		else if (delta > 1) {
			if (Node::height(a->L->R) > Node::height(a->L->L)) {
				RotBA(a->L);
			}
			RotAB(a);
		}
	}
	void add(Node*& r, T e) {
		if (r == nullptr) {
			r = new Node(e);
			return;
		}
		else if (key(e) < key(r->e)) {
			add(r->L, e);
		}
		else if (key(e) > key(r->e)) {
			add(r->R, e);
		}
		balance(r);
		r->updateH();
	}
	void inOrder(function<void(T)> doSomething, Node* a) {
		if (a != nullptr) {
			inOrder(doSomething, a->L);
			doSomething(a->e);
			inOrder(doSomething, a->R);
		}
	}
	void tabu(int a) {
		for (int i = 0; i < a; i++) cout << " ";
	}
	int c = 0;
	void deleteNode(R e, Node*& a) {
		//tabu(c);
		//cout << key(a->e) << endl;
		//c++;
		if (a == nullptr) {
			return;
		}
		else if (e > key(a->e)) {
			deleteNode(e, a->R);
		}
		else if (e < key(a->e)) {
			deleteNode(e, a->L);
		}
		else {
			//no tiene hijos
			if (a->R == nullptr && a->L == nullptr) {
				delete a;
				a = nullptr;
				return;
			}
			// tiene hijo izquierdo
			else if (a->R != nullptr && a->L == nullptr) {
				Node* aux = a;
				a = a->R;
				delete aux;
				return;
			}
			//tiene hijo derecho
			else if (a->L != nullptr && a->R == nullptr) {
				Node* aux = a;
				a = a->L;
				delete aux;
				return;
			}
			//Dos hijos
			else {
				Node* mx = buscarMax(a->L);
				a->e = mx->e;
				deleteNode(key(mx->e), a->L);

			}
		}
		balance(a);
		a->updateH();
	}
	Node* buscarMax(Node* a) {
		if (a->R != nullptr) {
			return buscarMax(a->R);
		}
		else return a;
	}

public:
	AVL(function<R(T)> key = [](T a) { return a; }) : key(key), root(nullptr), l(0) {}
	void Add(T e) {
		add(root, e);
		l++;
	}
	int Height() {
		return Node::height(root);
	}
	void borrar(R e) {
		deleteNode(e, root);
	}
	void orden(function<void(T)> doSomething) {
		inOrder(doSomething, root);
	}
	bool buscar(R e, function<void(T)> doSomething) {
		Node* a = Buscar(e, root);
		if (a == nullptr) {
			return false;
		}
		else {
			doSomething(a->e);
			return true;
		}
	}
};
//////////////////////////
#include <iostream>
#include <vector>
#include "avl.h"
#include <bits/stdc++.h>
#include <string>
using namespace std;
struct Personita {
	int edad;
	double tamaño;
	string nombre;
	Personita(int edad, double tamaño, string nombre) : edad(edad), tamaño(tamaño), nombre(nombre) {}
};
void escribir(AVL<Personita*, int>* arbolito) {
	ofstream wi("archivito.txt");
	arbolito->orden([&](Personita* a) {
		wi << "El nombre de esta persona es: " << a->nombre << endl;
		wi << "La edad de esta persona es: " << a->edad << endl;
		wi << "El tamaño de esta persona es: " << a->tamaño << endl;
		wi << endl;
	});
}
int main() {
	AVL<Personita*, int>* arbolito = new AVL<Personita*, int>([](Personita* a) {return a->edad; });
	vector<Personita*> personas;
	ifstream we("bizagi.txt");
	string line;
	while (getline(we, line)) {
		istringstream f(line);
		int a; f >> a;
		double w; f >> w;
		string n; f >> n;
		personas.push_back(new Personita(a, w, n));
	}


	for (auto a : personas) arbolito->Add(a);
	arbolito->orden([](Personita* a) {cout << a->edad << endl; });

	arbolito->borrar(44); // arbol de edades se envia la edad que quieres borrar
	cout << "se borro :)" << endl;
	arbolito->orden([](Personita* a) {cout << a->edad << endl; });

	escribir(arbolito);
	int f; cin >> f;
}

/*
arbolito->buscar(36, [](Personita* a) {
cout << "El nombre de esta persona es: " << a->nombre << endl;
cout << "La edad de esta persona es: " << a->edad << endl;
cout << "El tamaño de esta persona es: " << a->tamaño << endl;
});
arbolito->buscar(18, [](Personita* a) {
cout << "El nombre de esta persona es: " << a->nombre << endl;
cout << "La edad de esta persona es: " << a->edad << endl;
cout << "El tamaño de esta persona es: " << a->tamaño << endl;
});
*/
#endif
///////////////////////////////////////////////////
/*
* C++ program to Implement AVL Tree
*/
#include<iostream>
#include<cstdio>
#include<sstream>
#include<algorithm>
#define pow2(n) (1 << (n))
using namespace std;

/*
* Node Declaration
*/
struct avl_node
{
	int data;
	struct avl_node *left;
	struct avl_node *right;
}*root;

/*
* Class Declaration
*/
class avlTree
{
public:
	int height(avl_node *);
	int diff(avl_node *);
	avl_node *rr_rotation(avl_node *);
	avl_node *ll_rotation(avl_node *);
	avl_node *lr_rotation(avl_node *);
	avl_node *rl_rotation(avl_node *);
	avl_node* balance(avl_node *);
	avl_node* insert(avl_node *, int);
	void display(avl_node *, int);
	void inorder(avl_node *);
	void preorder(avl_node *);
	void postorder(avl_node *);
	avlTree()
	{
		root = NULL;
	}
};

/*
* Main Contains Menu
*/
int main()
{
	int choice, item;
	avlTree avl;
	while (1)
	{
		cout << "\n---------------------" << endl;
		cout << "AVL Tree Implementation" << endl;
		cout << "\n---------------------" << endl;
		cout << "1.Insert Element into the tree" << endl;
		cout << "2.Display Balanced AVL Tree" << endl;
		cout << "3.InOrder traversal" << endl;
		cout << "4.PreOrder traversal" << endl;
		cout << "5.PostOrder traversal" << endl;
		cout << "6.Exit" << endl;
		cout << "Enter your Choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Enter value to be inserted: ";
			cin >> item;
			root = avl.insert(root, item);
			break;
		case 2:
			if (root == NULL)
			{
				cout << "Tree is Empty" << endl;
				continue;
			}
			cout << "Balanced AVL Tree:" << endl;
			avl.display(root, 1);
			break;
		case 3:
			cout << "Inorder Traversal:" << endl;
			avl.inorder(root);
			cout << endl;
			break;
		case 4:
			cout << "Preorder Traversal:" << endl;
			avl.preorder(root);
			cout << endl;
			break;
		case 5:
			cout << "Postorder Traversal:" << endl;
			avl.postorder(root);
			cout << endl;
			break;
		case 6:
			exit(1);
			break;
		default:
			cout << "Wrong Choice" << endl;
		}
	}
	return 0;
}

/*
* Height of AVL Tree
*/
int avlTree::height(avl_node *temp)
{
	int h = 0;
	if (temp != NULL)
	{
		int l_height = height(temp->left);
		int r_height = height(temp->right);
		int max_height = max(l_height, r_height);
		h = max_height + 1;
	}
	return h;
}

/*
* Height Difference
*/
int avlTree::diff(avl_node *temp)
{
	int l_height = height(temp->left);
	int r_height = height(temp->right);
	int b_factor = l_height - r_height;
	return b_factor;
}

/*
* Right- Right Rotation
*/
avl_node *avlTree::rr_rotation(avl_node *parent)
{
	avl_node *temp;
	temp = parent->right;
	parent->right = temp->left;
	temp->left = parent;
	return temp;
}
/*
* Left- Left Rotation
*/
avl_node *avlTree::ll_rotation(avl_node *parent)
{
	avl_node *temp;
	temp = parent->left;
	parent->left = temp->right;
	temp->right = parent;
	return temp;
}

/*
* Left - Right Rotation
*/
avl_node *avlTree::lr_rotation(avl_node *parent)
{
	avl_node *temp;
	temp = parent->left;
	parent->left = rr_rotation(temp);
	return ll_rotation(parent);
}

/*
* Right- Left Rotation
*/
avl_node *avlTree::rl_rotation(avl_node *parent)
{
	avl_node *temp;
	temp = parent->right;
	parent->right = ll_rotation(temp);
	return rr_rotation(parent);
}

/*
* Balancing AVL Tree
*/
avl_node *avlTree::balance(avl_node *temp)
{
	int bal_factor = diff(temp);
	if (bal_factor > 1)
	{
		if (diff(temp->left) > 0)
			temp = ll_rotation(temp);
		else
			temp = lr_rotation(temp);
	}
	else if (bal_factor < -1)
	{
		if (diff(temp->right) > 0)
			temp = rl_rotation(temp);
		else
			temp = rr_rotation(temp);
	}
	return temp;
}

/*
* Insert Element into the tree
*/
avl_node *avlTree::insert(avl_node *root, int value)
{
	if (root == NULL)
	{
		root = new avl_node;
		root->data = value;
		root->left = NULL;
		root->right = NULL;
		return root;
	}
	else if (value < root->data)
	{
		root->left = insert(root->left, value);
		root = balance(root);
	}
	else if (value >= root->data)
	{
		root->right = insert(root->right, value);
		root = balance(root);
	}
	return root;
}

/*
* Display AVL Tree
*/
void avlTree::display(avl_node *ptr, int level)
{
	int i;
	if (ptr != NULL)
	{
		display(ptr->right, level + 1);
		printf("\n");
		if (ptr == root)
			cout << "Root -> ";
		for (i = 0; i < level && ptr != root; i++)
			cout << "        ";
		cout << ptr->data;
		display(ptr->left, level + 1);
	}
}

/*
* Inorder Traversal of AVL Tree
*/
void avlTree::inorder(avl_node *tree)
{
	if (tree == NULL)
		return;
	inorder(tree->left);
	cout << tree->data << "  ";
	inorder(tree->right);
}
/*
* Preorder Traversal of AVL Tree
*/
void avlTree::preorder(avl_node *tree)
{
	if (tree == NULL)
		return;
	cout << tree->data << "  ";
	preorder(tree->left);
	preorder(tree->right);

}

/*
* Postorder Traversal of AVL Tree
*/
void avlTree::postorder(avl_node *tree)
{
	if (tree == NULL)
		return;
	postorder(tree->left);
	postorder(tree->right);
	cout << tree->data << "  ";
}
