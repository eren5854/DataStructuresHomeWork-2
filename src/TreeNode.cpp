/**
* @file TreeNode.cpp
* @description Metin belgesindeki verileri kullanarak agaç oluşturur ve agacın değerini hesaplar
* @course 1. Öğretim A Grubu
* @assignment 2. Ödev
* @date 25.12.2024
* @author İhsan Eren Delibaş eren.delibas@ogr.sakarya.edu.tr
*/
#include "TreeNode.h"

TreeNode::TreeNode(char value) {
    data = value;
    left = nullptr;
    right = nullptr;
}
