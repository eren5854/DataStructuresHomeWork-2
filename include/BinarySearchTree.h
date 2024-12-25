/**
* @file BinarySearchTree.h
* @description Metin belgesindeki verileri kullanarak agaç oluşturur ve agacın değerini hesaplar
* @course 1. Öğretim A Grubu
* @assignment 2. Ödev
* @date 25.12.2024
* @author İhsan Eren Delibaş eren.delibas@ogr.sakarya.edu.tr
*/

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "TreeNode.h"

class BinarySearchTree {
private:
    TreeNode* root;

    void InsertNode(TreeNode*& node, char value);
    void PrintTree(TreeNode* node,  int space);
    int CalculateNodeSum(TreeNode* node, int isLeft);
    void MirrorTree(TreeNode* node);

public:
    BinarySearchTree();
    void Insert(char value);
    void DisplayTree();
    int CalculateSum();
    void Mirror();
    TreeNode* GetRoot();
};

#endif
