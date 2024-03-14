// --------------------------------------------------------------------------
// 2024.03.07
// --------------------------------------------------------------------------

#include <string_view>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <chrono>
#include "save.h"

void save(std::string_view); // const ���� �ʿ䰡 ����, string_view�� ���� ���� �����ϱ�!!! ���͸� ��α� �� �����ϱ�


void save(std::string_view fileName)
{
    // file�� �б������ ���� 
    std::ifstream in{ fileName.data() }; // ���� �ڷ���, �ڿ��� ������ �ϱ� ���� �̸� // RALL
    if (!in) { // ��ǲ ������ �߸� �Ǿ�����
        std::cout << fileName << "���� ����" << std::endl;
        exit(0);
    }

    // ������ ������ ���ٿ� ���� ���� ����.
    std::ofstream out{ "2024 1�б� STL ȭ56��56 �������� 0314.txt", std::ios::app }; // app�� append

    //std::cout << sizeof out << std::endl;

    // ���� ������ ������ �о� �� ���Ͽ� �� ���δ�.
    // STL �ڷ� ������ �˰����� �̿��Ͽ� ����Ѵ�(���� �� �ƴϴ�).
    std::vector<char> v{ std::istreambuf_iterator<char>{ in}, {} };

    auto now = std::chrono::system_clock::now();
    auto utc = std::chrono::system_clock::to_time_t(now);
    auto It = localtime(&utc);     // localtime�� C�Լ�

    // �ѱ� �������� ����Ѵ�(��� ��Ʈ���� ������ ��ȯ)
    auto old = out.imbue(std::locale("ko_KR"));

    out << std::endl << std::endl;
    out << "==========================================================================" << std::endl;
    out << "fileName :" << std::put_time(It, ":, %x %A %X") << std::endl;
    out << "==========================================================================" << std::endl;
    out << std::endl << std::endl;

    out.imbue(old);

    std::copy(v.begin(), v.end(), std::ostreambuf_iterator<char>{ out });

}