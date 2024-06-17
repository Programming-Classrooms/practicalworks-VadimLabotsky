#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <exception>
void checkFile(std::ifstream& fin)
{
    if (!fin.good())
    {
        throw std::ios_base::failure("File does not exist.\n");
    }
    if (!fin)
    {
        throw std::ios_base::failure("File is not opened.\n");
    }
    if (fin.peek() == EOF)
    {
        throw std::ios_base::failure("File is empty.\n");
    }
}
void print(std::vector <std::string> tekst)
{
    for (const auto& word : tekst) {
        std::cout << word << '\t';
    }
        std::cout << '\n';
}
int main()
{
    try
    {
        std::ifstream fin("src/files/list.txt");
        checkFile(fin);
        std::vector <std::string> tekst;
        std::string word = "";
        while (fin >> word)
        {
            tekst.push_back(word);
        }
        std::cout << "Not sorted list of words:" << '\n';
        print(tekst);
        std::sort(tekst.begin(), tekst.end());
        std::cout << "Sorted list of words:" << '\n';
        print(tekst);
        std::cout << "Enter letter with what you that start word!\n";
        char letter ;
        bool flag = false;
        std::cin >> letter;
        std::cout << "Words starting with the letter '" << letter << "':" << '\n';
        for (const auto& word : tekst ) {
            if (word[0] == letter) {
                std::cout << word << "\t";
                flag = true;
            }
        }
        if (!flag)
        {
            std::cout << "There aren't word start with the letter ' " << letter << "'!";
        }
        
        std::cout << '\n';
        std::cout << "Enter letter with what you erase word!\n";
        std::cin >> letter;
        tekst.erase(std::remove_if(tekst.begin(), tekst.end(), [letter](const std::string& word) { return word[0] == letter; }), tekst.end());

        std::cout << "List after removing words starting with the letter '" << letter << "':\n";
        print(tekst);

    }
    catch (const std::exception& ex)
    {
        std::cout << ex.what();
    }
   
	return 0;
}
