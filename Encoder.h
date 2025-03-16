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
		Node* left;
		Node* right; 
		char character; 
		int freq; 

		bool operator== (const Node& other) const {
			return (freq == other.freq); 
		}
		bool operator< (const Node& other) const {
			return (freq < other.freq); 
		}
		Node(Node* r, Node* l, char c, int f) : right(r), left(l), character(c), freq(f) {}
	};
	 
	std::vector<std::shared_ptr<Node>> nodes; 
	std::set<std::shared_ptr<Node>> rack;
	
	void readFile(const std::string& fileName);  
	void printMap(); 
	static bool compareNodes(const std::shared_ptr<Node> &n1, const std::shared_ptr<Node> &n2);  
	void populateNodes(); // makes and sorts array
	void buildTree();   
  



};
#endif //ENCODER_H

