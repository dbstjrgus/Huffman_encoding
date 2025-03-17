// huffman_encoding.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include <fstream> 
#include <unordered_map>
#include "Encoder.h"
#include <utility> 


int main()
{
    
    Huffman_encoder hfe; 

    hfe.readFile("sample3.txt");
    //hfe.printMap(); 
    
    hfe.populateNodes(); 
    hfe.buildTree(); 
    //std::cout << hfe.rack.size() << std::endl; 
    

    // debugging 
    auto it = hfe.rack.begin(); 
    //Huffman_encoder::Node n = **it; 
    std::shared_ptr<Huffman_encoder::Node> n1 = *it; 

    //the key
    hfe.buildKey(n1, ""); 
    for (const auto& pair : hfe.key) {
        std::cout << "" << pair.first << " : " << pair.second << std::endl;
    }
    int a = hfe.key.size(); 
    int b = hfe.nodes.size(); 

    std::cout << (a < b) << std::endl; 
    
}