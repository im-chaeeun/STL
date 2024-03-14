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

void save(std::string_view); // const 붙일 필요가 없음, string_view에 대한 내용 공부하기!!! 엉터리 블로그 글 조심하기


void save(std::string_view fileName)
{
    // file을 읽기용으로 연다 
    std::ifstream in{ fileName.data() }; // 앞은 자료형, 뒤에는 엑세스 하기 위한 이름 // RALL
    if (!in) { // 인풋 파일이 잘못 되었으면
        std::cout << fileName << "열기 실패" << std::endl;
        exit(0);
    }

    // 저장할 파일을 덧붙여 쓰기 모드로 연다.
    std::ofstream out{ "2024 1학기 STL 화56목56 강의저장 0314.txt", std::ios::app }; // app는 append

    //std::cout << sizeof out << std::endl;

    // 읽을 파일의 내용을 읽어 쓸 파일에 덧 붙인다.
    // STL 자료 구조와 알고리즘을 이용하여 기록한다(좋은 건 아니다).
    std::vector<char> v{ std::istreambuf_iterator<char>{ in}, {} };

    auto now = std::chrono::system_clock::now();
    auto utc = std::chrono::system_clock::to_time_t(now);
    auto It = localtime(&utc);     // localtime은 C함수

    // 한국 형식으로 출력한다(출력 스트림의 지역을 반환)
    auto old = out.imbue(std::locale("ko_KR"));

    out << std::endl << std::endl;
    out << "==========================================================================" << std::endl;
    out << "fileName :" << std::put_time(It, ":, %x %A %X") << std::endl;
    out << "==========================================================================" << std::endl;
    out << std::endl << std::endl;

    out.imbue(old);

    std::copy(v.begin(), v.end(), std::ostreambuf_iterator<char>{ out });

}