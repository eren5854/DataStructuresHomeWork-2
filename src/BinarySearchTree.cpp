/**
* @file BinarySearchTree.cpp
* @description Metin belgesindeki verileri kullanarak agaç oluşturur ve agacın değerini hesaplar
* @course 1. Öğretim A Grubu
* @assignment 2. Ödev
* @date 25.12.2024
* @author İhsan Eren Delibaş eren.delibas@ogr.sakarya.edu.tr
*/

#include <iostream>
#include "BinarySearchTree.h"

#define SPACE_COUNT 5

BinarySearchTree::BinarySearchTree() {
    root = nullptr;
}

void BinarySearchTree::InsertNode(TreeNode*& node, char value) {
    if (!node) {
        node = new TreeNode(value);
    } else if (value < node->data) {
        InsertNode(node->left, value);
    } else {
        InsertNode(node->right, value);
    }
}

void BinarySearchTree::Insert(char value) {
    InsertNode(root, value);
}

void BinarySearchTree::PrintTree(TreeNode* node, int space) {
    if (node == nullptr) {
        return;
    }

    space += SPACE_COUNT;

    PrintTree(node->right, space);

    std::cout << std::endl;
    for (int i = SPACE_COUNT; i < space; i++) {
        std::cout << " ";
    }
    std::cout << node->data << std::endl;

    PrintTree(node->left, space);
}


void BinarySearchTree::DisplayTree() {
    PrintTree(root, 0);
}

int BinarySearchTree::CalculateNodeSum(TreeNode* node, int isLeft) {
    if (!node) return 0;
    int sum = node->data * (isLeft ? 2 : 1);
    sum += CalculateNodeSum(node->left, 1);
    sum += CalculateNodeSum(node->right, 0);
    return sum;
}

int BinarySearchTree::CalculateSum() {
    return CalculateNodeSum(root, 0);
}

void BinarySearchTree::Mirror() {
    MirrorTree(root);
}

void BinarySearchTree::MirrorTree(TreeNode* node) {
    if (node == nullptr) {
        return;
    }

    MirrorTree(node->left);
    MirrorTree(node->right);

    TreeNode* temp = node->left;
    node->left = node->right;
    node->right = temp;
}

TreeNode* BinarySearchTree::GetRoot() {
    return root;
}
