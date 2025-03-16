#include "pch.h"
#include <iostream>
#include <fstream> 
#include <unordered_map>
#include <utility> 
#include <algorithm>
#include <set>
#include "Encoder.h"


Huffman_encoder::Huffman_encoder() : map() {}

void Huffman_encoder::readFile(const std::string& fileName) {
	std::cout << "start"; 
	std::ifstream file(fileName); 

	if (!file) {
		std::cout << "Unable to read file " << std::endl; 
		return; 
	
	}

	char c; 
	while (file.get(c)) {
		if (map.find(c) == map.end()) {
			map.insert({ c,1 }); 
		
		}
		else {
			map[c]++; 
		}
	
	}
	file.close(); 

	nodes.clear(); 
	
	std::cout << "end"; 
	


}

void Huffman_encoder::printMap() {
	for (const auto& pair : this->map) {
		std::cout << "" << pair.first << " : " << pair.second << std::endl; 
	}

}

bool Huffman_encoder::compareNodes(const std::shared_ptr<Node>& n1, const std::shared_ptr<Node>& n2) {
	return n1->freq < n2->freq;
}

void Huffman_encoder::populateNodes() {
	nodes.clear();
	for (const auto& pair : this->map) {
		std::shared_ptr<Node> node = std::make_shared<Node>(nullptr, nullptr, pair.first, pair.second, true);
		nodes.emplace_back(node);

	}

	std::sort(nodes.begin(), nodes.end(), compareNodes);

	this->rack = std::set<std::shared_ptr<Node>, NodeComparator>(nodes.begin(), nodes.end()); 
	

	for (const auto& n : nodes) {
		std::cout << n->character;
	}




}

void Huffman_encoder::buildTree() {
	while (rack.size() > 1) {
		auto it = rack.begin(); 
		std::shared_ptr<Node> first = *it;
		it = rack.erase(it); 
		if (it == rack.end()) break; 

		std::shared_ptr<Node> second= *it; 
		rack.erase(it); 

		std::shared_ptr<Node> internal = std::make_shared<Node>(first, second, '|0', first->freq + second->freq, false);
		rack.insert(internal); 


	}

	

}







