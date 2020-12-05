#include <iostream>
#include <fstream>
#include <string>
#include <stack>

#include"KAKICH.h"
#include "PUKECH.h"

namespace myNamespace {
    class Algorithm {
    public:
        void alg1() {
            int a, count, lnum = 0;
            std::string line;
            std::ifstream file("1.txt");
            std::ofstream ofile("out.txt");
            
            if (!file || !ofile)
            {
                std::cerr << "Uh oh, SomeText.txt could not be opened for reading!" << std::endl;
                exit(1);
            }
            file.seekg(0, std::ios_base::beg);
            a = file.tellg();
            std::stack<char> stack;
            while (file) {
                ++lnum;
                count = 0;
                std::getline(file, line);
                if (!file) return;
                bool truth = true;
                for (int i = 0; i < line.length(); i++) {
                    std::cout << line[i]<<' ';
                    ofile << line[i] << ' ';
                    if (line[i] == '[' || line[i] == '(' || line[i] == '{' || line[i] == '<') {
                        stack.push(line[i]);
                    }else
                    if (line[i] == ']' && stack.top() == '['){
                        stack.pop();
                    } else if (line[i] == ')' && stack.top() == '(') {
                               stack.pop();
                           } else if (line[i] == '}' && stack.top() == '{') {
                                      stack.pop();
                                  } else if (line[i] == '>' && stack.top() == '<') {
                                             stack.pop();
                                         } else std::cout << " !OBJECTION! ", ofile << " !OBJECTION! ";
                }
            }
            file.close();
            ofile.close();
            std::cout << "\n\n";
        }

        template<typename Iterator>
        bool alg2(const Iterator& s1, const Iterator& e1, const Iterator& s2, const Iterator& e2, Iterator& start) {
            int size1 = 0, count = 0, size2 = 0;

            Iterator tmp1 = s1;
            Iterator tmp2 = s2;
            Iterator find = e2;


            while (tmp1 != e1) {
                ++size1;
                ++tmp1;
            }
            while (tmp2 != e2) {
                ++size2;
                ++tmp2;
            }

            if (size2 > size1)
                return false;
            if (size1 == 1 && size2 == 1) {
                if (*tmp1 == *tmp2) {
                    start = find; return true;
                }
            }

            tmp1 = s1; tmp2 = s2;

            while (tmp1 != e1 && tmp2 != e2) {
                if (*tmp1 == *tmp2) {
                    if (!count)   find = tmp1;
                    ++count;
                    if (count != size2)   ++tmp2;
                    else {
                        if (count == size2) { start = find; return true; }
                    }
                }
                else {
                    if (count) --tmp1;
                    count = 0;
                    tmp2 = s2;
                    find = e2;
                }
                if (tmp1 == e1) {
                    if (count == size2) { start = find; return true; }
                    else return false;
                }
                ++tmp1;

            }


        }

        template<typename Iterator>
        void alg3(const Iterator& head, const Iterator& tail, std::list<myNamespace::Prods>& ring) {
            Iterator it;
            Iterator start = head;

            while (start != tail) {
                it = start;
                ++it;
                while (it != tail) {
                    if (*it == *start) {
                        Iterator tmp = it;
                        ++it;
                        ring.erase(tmp);
                        --it;
                    }
                    ++it;
                }
                ++start;
            }
        }
    };
}


int main()
{
    myNamespace::Algorithm A;
    A.alg1();
    std::cout << "\n\n";
    myNamespace::Prods m1("Stas", 56.5);
    myNamespace::Prods m2("Max", 5.9);
    myNamespace::Prods m3("Dima", 10.1);
    myNamespace::Prods m4("Lera", 55.2);
    myNamespace::Prods m5("Wick", 99999);
    std::list<myNamespace::Prods> ring;
    std::list<myNamespace::Prods> find1, find2;

    std::list<myNamespace::Prods>::iterator start;

    ring.push_back(m1);
    ring.push_back(m1);
    ring.push_back(m1);
    ring.push_back(m2);
    ring.push_back(m5);
    ring.push_back(m3);
    ring.push_back(m4);
    ring.push_back(m5);

    start = ring.begin();
    while (start != ring.end()) {
        std::cout << *start;
        ++start;
    }

    std::cout << std::endl;

    find1.push_back(m3);
    find1.push_back(m4);
    find1.push_back(m5);

    find2.push_back(m5);
    find2.push_back(myNamespace::Prods("temp", 1.1));

    if (A.alg2(ring.begin(), ring.end(), find1.begin(), find1.end(), start)) std::cout << *start << '\n';
    else std::cout << "Didn't find\n\n";

    if (A.alg2(ring.begin(), ring.end(), find2.begin(), find2.end(), start)) std::cout << *start << '\n';
    else std::cout << "Didn't find\n\n";

    A.alg3(ring.begin(), ring.end(), ring);

    start = ring.begin();
    while (start != ring.end()) {
        std::cout << *start;
        ++start;
    }

    return 0;
}