/**
* @file FileReader.cpp
* @description Metin belgesindeki verileri kullanarak agaç oluşturur ve agacın değerini hesaplar
* @course 1. Öğretim A Grubu
* @assignment 2. Ödev
* @date 25.12.2024
* @author İhsan Eren Delibaş eren.delibas@ogr.sakarya.edu.tr
*/
#include "FileReader.h"
#include <fstream>
#include <iostream>

void FileReader::ReadFile(const std::string& fileName, LinkedList& list) {
    std::ifstream file(fileName);
    if (!file) {
        std::cerr << "Error opening file: " << fileName << "\n";
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        BinarySearchTree* tree = new BinarySearchTree();
        for (char ch : line) {
            tree->Insert(ch);
        }
        list.Add(tree);
    }
    file.close();
}
