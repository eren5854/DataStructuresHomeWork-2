/**
* @file FileReader.h
* @description Metin belgesindeki verileri kullanarak agaç oluşturur ve agacın değerini hesaplar
* @course 1. Öğretim A Grubu
* @assignment 2. Ödev
* @date 25.12.2024
* @author İhsan Eren Delibaş eren.delibas@ogr.sakarya.edu.tr
*/
#ifndef FILEREADER_H
#define FILEREADER_H

#include "LinkedList.h"
#include <string>

class FileReader {
public:
    static void ReadFile(const std::string& fileName, LinkedList& list);
};

#endif
