#include "../Deque/Deque.hpp"
#include <cstring>
#include <string>
#include <cstdlib>
#include <cstdio>
int main()
{
    TDeque<int> intDeque;

    intDeque.InsFront(1);
    intDeque.InsFront(2);

    intDeque.InsRear(3);
    intDeque.InsRear(4);
    int item = 0;
    intDeque.DelFront(item);
    std::cout << item << '\n';
    intDeque.DelRear(item);
    std::cout << item << '\n';
    
   std::cout << "First element: " << intDeque.GetByIndex(0) << '\n';

    intDeque.SetByIndex(5, 0);
    std::cout << "First element after change: " << intDeque.GetByIndex(0) << '\n';

   

    intDeque.Browse(std::function<void(int)>([](int element) {std::cout << element << '\t'; }));
    std::cout << '\n';
    intDeque.Browse(std::function<void(int)>([](int element) {std::cout << element << '\t'; }));
    std::cout << '\n';

    int frontItem = 0;
    if (intDeque.DelFront(frontItem)) {
        std::cout << "Removed item from the head of the deck: " << frontItem << '\n';
    }

    int rearItem = 0;
    if (intDeque.DelRear(rearItem)) {
        std::cout << "Removed element from the tail of the deck: " << rearItem << '\n';
    }
    TDeque <int> anotherDeque;
    anotherDeque = intDeque;
    intDeque.~TDeque();


    TDeque<char*> charDeque;

    char* a = new char[5];
    char* b = new char[5];

    char* c = new char[5];
    std::cout << "Please enter element!\n";
    std::cin.getline(a,255);
    std::cin.getline(b,255);
    std::cin.getline(c,255);
    charDeque.InsFront(a);
    char* item1;
    charDeque.InsRear(b);
    charDeque.InsRear(c);
    
    charDeque.DelFront(item1);
    std::cout << item1 << '\n';
    charDeque.DelRear(item1);
    std::cout << item1 << '\n';
    TDeque <char*> anotherDeque1;
    anotherDeque1 = charDeque;

   std::cout << "First element: " << charDeque.GetByIndex(0) << '\n';

    charDeque.SetByIndex(c, 0);
    std::cout << "First element after change: " << charDeque.GetByIndex(0) << '\n';


   charDeque.Browse(std::function<void(char*)>([](char* element) {std::cout << element << " "; }));
    std::cout << '\n';
    charDeque.Browse(std::function<void(char*)>([](char* element) {std::cout << element << " "; }));
    std::cout << '\n';

    char* frontItemChar = 0;
    if (charDeque.DelFront(frontItemChar)) {
        std::cout << "Removed item from the head of the deck: " << frontItem << '\n';
    }

    char* rearItemChar;
    if (charDeque.DelRear(rearItemChar)) {
        std::cout << "Removed element from the tail of the deck: " << rearItem << '\n';
    }

    TDeque <char*> charanotherDeque;
    charanotherDeque = charDeque;
    delete[]a;
    delete[]b;
    delete[]c;
    return 0;
}