/**
* @file main.cpp
* @description Metin belgesindeki verileri kullanarak agaç oluşturur ve agacın değerini hesaplar
* @course 1. Öğretim A Grubu
* @assignment 2. Ödev
* @date 25.12.2024
* @author İhsan Eren Delibaş eren.delibas@ogr.sakarya.edu.tr
*/
#include <iostream>
#include "FileReader.h"

int main() {
    LinkedList treeList;

    FileReader::ReadFile("agaclar.txt", treeList);

    // std::cout << "Navigating through the list:\n";
    treeList.NavigateList();
    treeList.DeleteList();
    return 0;
}
