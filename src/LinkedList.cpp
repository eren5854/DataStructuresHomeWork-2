/**
* @file LinkedList.cpp
* @description Metin belgesindeki verileri kullanarak agaç oluşturur ve agacın değerini hesaplar
* @course 1. Öğretim A Grubu
* @assignment 2. Ödev
* @date 25.12.2024
* @author İhsan Eren Delibaş eren.delibas@ogr.sakarya.edu.tr
*/
#include <iostream>
#include "LinkedList.h"

LinkedListNode::LinkedListNode(BinarySearchTree *tree)
{
    this->tree = tree;
    next = nullptr;
    prev = nullptr;
}

LinkedList::LinkedList()
{
    head = nullptr;
}

void LinkedList::Add(BinarySearchTree *tree)
{
    LinkedListNode *newNode = new LinkedListNode(tree);
    if (!head)
    {
        head = newNode;
    }
    else
    {
        LinkedListNode *temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }
}

// void LinkedList::Display()
// {
//     LinkedListNode *temp = head;
//     std::cout << "Tree Address | Tree Sum | Next Address | Previous Address\n";
//     std::cout << "------------------------------------------------------------\n";

//     while (temp)
//     {
//         std::cout << temp << " | ";

//         std::cout << temp->tree->CalculateSum() << " | ";

//         if (temp->next)
//         {
//             std::cout << temp->next << " | ";
//         }
//         else
//         {
//             std::cout << 0 << " | ";
//         }

//         if (temp->prev)
//         {
//             std::cout << temp->prev;
//         }
//         else
//         {
//             std::cout << 0;
//         }
//         std::cout << "\n";

//         temp = temp->next;
//     }
// }

void LinkedList::NavigateList()
{
    LinkedListNode *current = head;
    LinkedListNode *prev = nullptr;
    char input;

    if (!head)
    {
        std::cout << "The list is empty.\n";
        return;
    }

    int listLength = 0;
    LinkedListNode *temp = head;
    while (temp)
    {
        listLength++;
        temp = temp->next;
    }

    int pageCount = 0;
    int space = 0;
    int page = 0;
    while (true)
    {
#ifdef _WIN32
        std::system("cls");
#else
        std::system("clear");
#endif
        temp = head;
        int count = 0;
        if (space < 0)
        {
            space = 0;
        }

        std::string upPoint = "";
        std::string firstRow = "";
        std::string secondRow = "";
        std::string thirdRow = "";
        std::string arrow = "";
        std::string arrowStick = "";

        int maxAddrLength = 10;
        int maxValLength = 3;

        if (pageCount <= 9)
        {
            page = 1;
            while (temp && count < 10)
            {
                std::string addpoint = std::string(maxAddrLength + 2, '.');
                std::string addrStr = std::to_string(reinterpret_cast<uintptr_t>(temp));
                std::string addrStrSpace = std::string(maxAddrLength - addrStr.length(), ' ');
                std::string valStr = std::to_string(temp->tree->CalculateSum());
                std::string valStrSpace = std::string(maxAddrLength - valStr.length(), ' ');
                std::string nextAddr = "";
                if (temp->next)
                {
                    nextAddr = std::to_string(reinterpret_cast<uintptr_t>(temp->next));
                }
                else
                {
                    nextAddr = "0";
                }

                upPoint += addpoint + "  ";
                firstRow += "." + addrStrSpace + addrStr + ".  ";
                secondRow += "." + valStrSpace + valStr + ".  ";
                thirdRow += "." + addrStrSpace + nextAddr + ".  ";

                if (temp == current)
                {
                    arrow += std::string(space, ' ') + "^^^^^^^^^^^^";
                    arrowStick += std::string(space, ' ') + "||||||||||||";
                }
                else
                {
                    arrow += " ";
                    arrowStick += " ";
                }

                temp = temp->next;
                count++;
            }
        }
        else
        {
            page = 2;
            while (temp)
            {
                if (count > 9)
                {
                    std::string addpoint = std::string(maxAddrLength + 2, '.');
                    std::string addrStr = std::to_string(reinterpret_cast<uintptr_t>(temp));
                    std::string addrStrSpace = std::string(maxAddrLength - addrStr.length(), ' ');
                    std::string valStr = std::to_string(temp->tree->CalculateSum());
                    std::string valStrSpace = std::string(maxAddrLength - valStr.length(), ' ');
                    std::string nextAddr = "";
                    if (temp->next)
                    {
                        nextAddr = std::to_string(reinterpret_cast<uintptr_t>(temp->next));
                    }
                    else
                    {
                        nextAddr = "0";
                    }

                    upPoint += addpoint + "  ";
                    firstRow += "." + addrStrSpace + addrStr + ".  ";
                    secondRow += "." + valStrSpace + valStr + ".  ";
                    thirdRow += "." + addrStrSpace + nextAddr + ".  ";

                    if (temp == current)
                    {
                        arrow += std::string(space, ' ') + "^^^^^^^^^^^^";
                        arrowStick += std::string(space, ' ') + "||||||||||||";
                    }
                    else
                    {
                        arrow += " ";
                        arrowStick += " ";
                    }
                }

                temp = temp->next;
                count++;
            }
        }

        std::cout << upPoint << "\n";

        std::cout << firstRow << "\n";

        std::cout << secondRow << "\n";

        std::cout << thirdRow << "\n";

        std::cout << upPoint << "\n";

        std::cout << arrow << "\n";
        std::cout << arrowStick << "\n";

        // std::cout << "Secilen agacin degeri = " << current->tree->CalculateSum() << std::endl;
        // std::cout << "Dugum numarasi = " << pageCount << std::endl;
        // std::cout << "Sayfa Nuamrasi = " << page << std::endl;
        // std::cout << "Liste uzunlugu = " << listLength << std::endl;
        // std::cout << "Isaretci boslugu = " << space << std::endl;

        // std::cout << "Secilen agac semasi: " << std::endl;
        current->tree->DisplayTree();

        std::cout << "---IKILI AGAC ARAMA---" << std::endl;
        std::cout << "(a) = sola ilerle, (d) = saga ilerle\n";
        std::cout << "(s) = secili dugumu sil, (w) = secili dugumu aynala\n";
        std::cout << "(q) = cikis\n";
        // std::cout << "Not: birden fazla kez sola yada saga gitmek istiyorsaniz, birden fazla kez a yada d harfini yazip enter tusuna basin\n";
        // std::cout << "ornek => (ddd) 3 dugum saga, (aa) 2 dugum sola\n";
        std::cout << "\nsecim...: ";
        std::cin >> input;

        if (input == 'd')
        {
            if (current->next)
            {
                prev = current;
                current = current->next;

                if (pageCount % 10 == 9)
                {
                    space = 0;
                }
                else
                {
                    space += 13;
                }
                pageCount++;
            }
            else
            {
                std::cout << "Already at the last node.\n";
            }
        }
        else if (input == 'a')
        {
            if (current->prev)
            {
                current = current->prev;
                prev = prev ? prev->prev : nullptr;

                if (pageCount % 10 == 0)
                {
                    space = 117;
                }
                else
                {
                    space -= 13;
                }
                pageCount--;
            }
            else
            {
                std::cout << "Already at the first node.\n";
            }
        }
        else if (input == 's')
        {
            if (!current)
            {
                std::cout << "No node to delete.\n";
                continue;
            }

            LinkedListNode *toDelete = current;

            if (current->prev)
            {
                current->prev->next = current->next;
            }
            else
            {
                head = current->next;
            }

            if (current->next)
            {
                current->next->prev = current->prev;
            }

            if (current->next)
            {
                current = current->next;
            }
            else if (current->prev)
            {
                current = current->prev;
                space -= 13;
                pageCount--;
                if (pageCount == 9)
                {
                    space = 117;
                }
            }
            else
            {
                current = nullptr;
            }

            delete toDelete;
            listLength--;

            std::cout << "Dugum silindi.\n";

            if (!head)
            {
                std::cout << "Liste boş. Cikis icin 'q' basiniz.\n";
                while (true)
                {
                    std::system("cls");
                    std::cout << "---IKILI AGAC ARAMA---" << std::endl;
                    std::cout << "(a) = sola ilerle, (d) = saga ilerle\n";
                    std::cout << "(s) = secili dugumu sil, (w) = secili dugumu aynala\n";
                    std::cout << "(q) = cikis\n";
                    std::cout << "\nsecim...: ";
                    std::cin >> input;

                    if (input == 'q')
                    {
                        break;
                    }
                    // else
                    // {
                    //     std::cout << "Liste boş. Cikis icin 'q' basiniz.\n";
                    // }
                }
                break;
            }
        }

        if (input == 'w')
        {
            if (current && current->tree)
            {
                current->tree->Mirror();
                std::cout << "Secili agac aynalandi.\n";
                current->tree->DisplayTree();
            }
            else
            {
                std::cout << "Aynalanmak icin agac secilmedi.\n";
            }
            std::cin.get();
        }

        else if (input == 'q')
        {
            break;
        }
    }
}

void LinkedList::DeleteList() {
    LinkedListNode* current = head;
    while (current != nullptr) {
        LinkedListNode* temp = current;
        current = current->next;
        delete temp->tree;
        delete temp;
    }
    head = nullptr;
    std::cout << "\nListe Temizlendi\n";
}