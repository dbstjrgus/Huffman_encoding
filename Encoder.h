#pragma once
#ifndef ENCODER_H
#define ENCODER_H
#include <utility>
#include <unordered_map>
#include <vector>
#include <set> 
class Huffman_encoder {
public:
	std::unordered_map<char, int> map;
	Huffman_encoder(); 
	struct Node {
		std::shared_ptr<Node> left;
		std::shared_ptr<Node> right; 
		char character; 
		int freq; 
		bool isleaf; 

		
		Node(std::shared_ptr<Node> r, std::shared_ptr<Node> l, char c, int f, bool b) : right(r), left(l), character(c), freq(f), isleaf(b) {}
	};

	struct NodeComparator {
		bool operator()(const std::shared_ptr<Node>& a, const std::shared_ptr<Node>& b) const {
			if (a->freq == b->freq)
				return a->isleaf < b->isleaf;
			return a->freq < b->freq; 
		}
	};
	 
	std::vector<std::shared_ptr<Node>> nodes; 
	std::set<std::shared_ptr<Node>, NodeComparator> rack;
	
	void readFile(const std::string& fileName);  
	void printMap(); 
	static bool compareNodes(const std::shared_ptr<Node> &n1, const std::shared_ptr<Node> &n2);  
	void populateNodes(); // makes and sorts array
	void buildTree();   
  



};
#endif //ENCODER_H

