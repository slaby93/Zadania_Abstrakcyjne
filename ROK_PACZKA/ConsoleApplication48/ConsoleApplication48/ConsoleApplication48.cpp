// ConsoleApplication48.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <list>
#include <string>
#include <map>

using namespace std;

template<class VertexLabelType, class EdgeLabelType>
class NeighbourhoodMapGraph {
public:
	class Vertex;

	struct VertexCompare;

	class Edge;

	class EdgeIterator;

	class VertexData {
	public:
		friend class NeighbourhoodMapGraph;

		friend class Vertex;

		VertexData(const VertexLabelType &label) : label(label) {}

	private:
		VertexLabelType label;
		map<Vertex, Edge, VertexCompare> neighbourhood;
	};

	class Vertex {
	public:
		friend class NeighbourhoodMapGraph;
		
		friend struct VertexCompare;

		Vertex() {}

		Vertex(typename list<VertexData>::iterator data, size_t id) : data(data), id(id) {}

		const VertexLabelType& getLabel() const {
			return data->label;
		}

		void setLabel(const VertexLabelType &label) {
			data->label = label;
		}

		void addEdge(const Vertex &to, const Edge &edge) {
			data->neighbourhood[to] = edge;
		}

		bool isConnected(const Vertex &to) const {
			return data->neighbourhood.find(to) != data->neighbourhood.end();
		}

		const Edge& getEdge(const Vertex &to) const {
			return data->neighbourhood.find(to)->second;
		}

		void removeEdge(const Vertex &to) {
			data->neighbourhood.erase(data->neighbourhood.find(to));
		}

		EdgeIterator edgesBegin() const {
			return EdgeIterator(data->neighbourhood.begin());
		}

		EdgeIterator edgesEnd() const {
			return EdgeIterator(data->neighbourhood.end());
		}

	private:
		typename list<VertexData>::iterator data;
		size_t id;
	};

	struct VertexCompare
	{
		bool operator() (const Vertex &lhs, const Vertex &rhs) const {
			return lhs.id < rhs.id;
		}
	};

	class Edge {
	public:
		friend class NeighbourhoodMapGraph;

		Edge() {};

		Edge(const Vertex &from, const Vertex &to, typename list<EdgeLabelType>::iterator label) : from(from), to(to), label(label) {}

		const EdgeLabelType& getLabel() const {
			return *label;
		}

		void setLabel(const EdgeLabelType &label) {
			*this->label = label;
		}

	private:
		Vertex from, to;
		typename list<EdgeLabelType>::iterator label;
	};

	class EdgeIterator {
	public:
		EdgeIterator(typename map<Vertex, Edge, VertexCompare>::iterator newBase) : base(newBase) {}

		bool operator!=(const EdgeIterator &other) {
			return base != other.base;
		}

		bool operator==(const EdgeIterator &other) {
			return base == other.base;
		}

		EdgeIterator& operator++() {
			base++;
			return *this;
		}

		EdgeIterator operator++(int) {
			return EdgeIterator(++base);
		}

		EdgeIterator& operator--() {
			base--;
			return *this;
		}

		EdgeIterator operator--(int) {
			return EdgeIterator(--base);
		}

		Edge& operator*() const {
			return base->second;
		}

		Edge* operator->() {
			return &(base->second);
		}

		typedef bidirectional_iterator_tag iterator_category;

		typedef Edge value_type;

		typedef int difference_type;

		typedef Edge* pointer;

		typedef Edge& reference;

	private:
		typename map<Vertex, Edge, VertexCompare>::iterator base;
	};

	typedef typename list<Vertex>::iterator VertexIterator;

	NeighbourhoodMapGraph() : current(0) {}

	NeighbourhoodMapGraph(const NeighbourhoodMapGraph &other) : current(other.current) {
		copy(other.dataList.begin(), other.dataList.end(), inserter(dataList, dataList.end()));
		copy(other.labels.begin(), other.labels.end(), inserter(labels, labels.end()));
		copy(other.nodes.begin(), other.nodes.end(), inserter(nodes, nodes.end()));
		for (typename list<Vertex>::iterator it1 = nodes.begin(); it1 != nodes.end(); it1++) {
			VertexLabelType label = it1->getLabel();
			typename list<VertexData>::iterator it2 = dataList.begin();
			for (; it2 != dataList.end() && it2->label != label; it2++) {}
			it1->data = it2;
			for (typename map<Vertex, Edge, VertexCompare>::iterator it3 = it2->neighbourhood.begin(); it3 != it2->neighbourhood.end(); it3++) {
				EdgeLabelType label = it3->second.getLabel();
				typename list<EdgeLabelType>::iterator it4 = labels.begin();
				for (; it4 != labels.end() && *it4 != label; it4++) {}
				it3->second.label = it4;
			}
		}
	}

	NeighbourhoodMapGraph& operator=(const NeighbourhoodMapGraph &other) {
		current = other.current;
		dataList.clear();
		labels.clear();
		nodes.clear();
		copy(other.dataList.begin(), other.dataList.end(), inserter(dataList, dataList.end()));
		copy(other.labels.begin(), other.labels.end(), inserter(labels, labels.end()));
		copy(other.nodes.begin(), other.nodes.end(), inserter(nodes, nodes.end()));
		for (typename list<Vertex>::iterator it1 = nodes.begin(); it1 != nodes.end(); it1++) {
			VertexLabelType label = it1->getLabel();
			typename list<VertexData>::iterator it2 = dataList.begin();
			for (; it2 != dataList.end() && it2->label != label; it2++) {}
			it1->data = it2;
			for (typename map<Vertex, Edge, VertexCompare>::iterator it3 = it2->neighbourhood.begin(); it3 != it2->neighbourhood.end(); it3++) {
				EdgeLabelType label = it3->second.getLabel();
				typename list<EdgeLabelType>::iterator it4 = labels.begin();
				for (; it4 != labels.end() && *it4 != label; it4++) {}
				it3->second.label = it4;
			}
		}
		return *this;
	}

	Vertex& addVertex(const VertexLabelType &label) {
		return *nodes.insert(nodes.end(), Vertex(dataList.insert(dataList.end(), VertexData(label)), current++));
	}

	VertexIterator verticesBegin() {
		return nodes.begin();
	}

	VertexIterator verticesEnd() {
		return nodes.end();
	}

	void addEdge(Vertex &from, const Vertex &to, const EdgeLabelType &label) {
		from.addEdge(to, Edge(from, to, labels.insert(labels.end(), label)));
	}

	bool isConnected(const Vertex &from, const Vertex &to) const {
		return from.isConnected(to);
	}

	void removeEdge(Vertex &from, const Vertex &to) {
		labels.erase(from.getEdge(to).label);
		from.removeEdge(to);
	}

	EdgeIterator edgesBegin(const Vertex &v) const {
		return v.edgesBegin();
	}

	EdgeIterator edgesEnd(const Vertex &v) const {
		return v.edgesEnd();
	}

public:
	list<VertexData> dataList;
	list<EdgeLabelType> labels;
	list<Vertex> nodes;
	size_t current;
};

int _tmain(int argc, _TCHAR* argv[])
{
	NeighbourhoodMapGraph<string, string> graph;
	NeighbourhoodMapGraph<string, string>::Vertex &n1 = graph.addVertex("abb");
	NeighbourhoodMapGraph<string, string>::Vertex &n2 = graph.addVertex("acc");
	NeighbourhoodMapGraph<string, string>::Vertex &n3 = graph.addVertex("add");
	graph.addEdge(n1, n2, "x6d");
	graph.addEdge(n1, n3, "x7d");
	for (auto it = graph.edgesBegin(n1); it != graph.edgesEnd(n1); it++) {
		cout << it->getLabel() << endl;
	}
	graph.removeEdge(n1, n3);
	for (auto it = graph.edgesBegin(n1); it != graph.edgesEnd(n1); it++) {
		cout << it->getLabel() << endl;
	}
	cout << graph.isConnected(n2, n3) << endl;
	for (auto it = graph.verticesBegin(); it != graph.verticesEnd(); it++) {
		cout << it->getLabel() << endl;
	}
	NeighbourhoodMapGraph<string, string> graph1(graph);
	for (auto it = graph1.verticesBegin(); it != graph1.verticesEnd(); it++) {
		it->setLabel("aaa");
		cout << it->getLabel() << endl;
	}
	for (auto it = graph.verticesBegin(); it != graph.verticesEnd(); it++) {
		cout << it->getLabel() << endl;
	}
	for (auto it1 = graph1.verticesBegin(); it1 != graph1.verticesEnd(); it1++) {
		for (auto it2 = graph1.edgesBegin(*it1); it2 != graph1.edgesEnd(*it1); it2++) {
			it2->setLabel("aaa");
			cout << it2->getLabel() << endl;
		}
	}
	for (auto it = graph.edgesBegin(n1); it != graph.edgesEnd(n1); it++) {
		cout << it->getLabel() << endl;
	}
	graph1 = graph;
	for (auto it = graph1.verticesBegin(); it != graph1.verticesEnd(); it++) {
		cout << it->getLabel() << endl;
	}
	int a;
	cin >> a;
	return 0;
}

