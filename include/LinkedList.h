/**
* @file LinkedList.h
* @description Metin belgesindeki verileri kullanarak agaç oluşturur ve agacın değerini hesaplar
* @course 1. Öğretim A Grubu
* @assignment 2. Ödev
* @date 25.12.2024
* @author İhsan Eren Delibaş eren.delibas@ogr.sakarya.edu.tr
*/
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "BinarySearchTree.h"

class LinkedListNode {
public:
    BinarySearchTree* tree;
    LinkedListNode* next;
    LinkedListNode* prev;
    LinkedListNode(BinarySearchTree* tree);
};

class LinkedList {
private:
    LinkedListNode* head;

public:
    LinkedList();
    void Add(BinarySearchTree* tree);
    void Display();
    void NavigateList();
    void DeleteList();
};

#endif
