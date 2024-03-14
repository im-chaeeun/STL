//---------------------------------------------------------------------------------------------
// 2024. 1�б� STL ȭ56��56 3�� 14�� �����    (2�� 2)        
// 
// FILE I/O text/binary - high/low level                            
//---------------------------------------------------------------------------------------------
#include "save.h"
#include <iostream>
#include <array>
#include <fstream>
#include <random>
#include <print>
#include <algorithm>

// [����] "����"���� class Dog ��ü 100���� ��ϵǾ� �ִ�.
// ������ binary ����̰� write �Լ��� sizeof(Dog)*100 ����Ʈ�� ����Ͽ���.
// ������ �о� ���� num���� ū Dog ������ ȭ�鿡 ����϶�. 
// class Dog�� ����� ������ ����.

//class Dog {
//    char c;
//    int num;
//};

std::default_random_engine dre;     
std::uniform_int_distribution<int> uidC{ 'a', 'z' };
std::uniform_int_distribution uidNum{ -9999, 9999 };

class Dog {
    char c{ static_cast<char>(uidC(dre)) };
    int num{ uidNum(dre) };
public:
    friend std::ostream& operator<<(std::ostream& os, const Dog& dog) {
        return os << "����: " << dog.c << "����: " << dog.num;
    }
};
//---------------------------------------------------------------------
int main()
//---------------------------------------------------------------------
{   
    std::array<Dog, 100> dogs;
   
    for (const Dog& dog : dogs)
        std::cout << dog << std::endl;

    //
    std::ofstream out{ "����", std::ios::binary };
    out.write((char*)dogs.data(), sizeof(Dog) * dogs.size());

    save("STL.cpp");
}
