#include "pch.h"
#include <iostream>
#include <fstream> 
#include <unordered_map>
#include <utility> 
#include <algorithm>
#include "Encoder.h"


Huffman_encoder::Huffman_encoder() : map() {}

void Huffman_encoder::readFile(const std::string& fileName) {
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
	nodes = std::vector<std::shared_ptr<Node>>(map.size()); 
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
		std::shared_ptr<Node> node = std::make_shared<Node>(nullptr, nullptr, pair.first, pair.second);
		nodes.emplace_back(node);

	}

	std::sort(nodes.begin(), nodes.end(), compareNodes);
	// use lambda notation instead
	/**
	std::sort(nodes.begin(), nodes.end(),
		[](const std::shared_ptr<Node>& a, const std::shared_ptr<Node>& b) {
			return a->freq < b->freq;
		});
		**/
	// debugging print statement 

	for (const auto& n : nodes) {
		std::cout << n->character;
	}


}


