/*
При написании программ использовать нуль–терминированные строки и работать только с типом char* .Длина каждой строки не превосходит 300
символов.Словом, входящим в состав строки, назовём непрерывную последовательность символов, ограниченную символами–разделителями,
началом и концом строки.Символы, относящиеся к разделителям, определяет пользователь, если иное не сказано в условии задачи.Если решить задачу
невозможно, программа должна выдать соответствующее сообщение. Строка состоит из слов.За один просмотр символов строки найти все
самые длинные слова, символы в которых идут в строгом возрастании кодов, и занести их в новую строку. Слова в новой строке должны разделяться
ровно одним пробелом.
*/


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>


void inputStringAndDelimeters(char* str, char* delimiters)
{
	std::cout << "Please enter delimiters!\n";
	std::cin.getline(delimiters, 300);
	while (strlen(delimiters) == 0)
	{
		std::cout << "YOU did not enter delimiter(s)!\n";
		std::cout << "Please enter delimiters!\n";
		std::cin.getline(delimiters, 300);
	}
	std::cout << "Thank you!\n";
	std::cout << "Please enter a string!\n";
	std::cin.getline(str, 300);
	while (strlen(str) == 0)
	{
		std::cout << "YOU have not entered character(s)!\n";
		std::cout << "Please enter a string!\n";
		std::cin.getline(str, 300);
	}
	std::cout << "Thank you!\n";
}

bool lexgraphOrder(char* word, bool indicator)
{
	std::size_t len = strlen(word);
	for (size_t i = 0; i < len-1; i++)
	{ 
		if (static_cast<int32_t>(word[i]) <= static_cast<int32_t>(word[i + 1]))
		{
			indicator = true;
		}
		else
		{
			indicator = false;
			break;
		}
	}
	return indicator;
}

void searchMaxLengthWord(char* str, char*& word, size_t& maxLengthWord)
{
	if (strlen(word) >= maxLengthWord)
	{
		maxLengthWord = strlen(word);
	}
}

void dividesStrAndCheck(char* str, char* delimiters, char* word, bool& indicator, char* timeStr, size_t& maxLengthWord)
{
	for (word = strtok(str, delimiters); word != NULL; word = strtok(NULL, delimiters)){
			strcat(timeStr, delimiters);
			if (lexgraphOrder(word, indicator)){
			strcat(timeStr, word);
			searchMaxLengthWord(str, word, maxLengthWord);
		}
	}
}

void CheckTimeAndWriteResult(char* str, char* timeStr, char* delimiters, char* word, bool indicator, char* result, size_t& maxLengthWord)
{
	dividesStrAndCheck(str, delimiters, word, indicator, timeStr, maxLengthWord);
	const char* space = " ";
	for (word = strtok(timeStr, delimiters); word != NULL; word = strtok(NULL, delimiters))
	{
		
		if (maxLengthWord == strlen(word) && lexgraphOrder(word, indicator))
		{
			strcat(result,word );
			strcat(result, space);
			continue;
		}
	}
	
	std::cout << "Your result!\n";
	std::cout << result;
}

int main()
{
	char str[300] = "";
	char delimiters[300] = "";
	char word[300] = "";
	bool indicator = true;
	size_t maxLengthWord = 0;
	char timeStr[300] = "";
	char result[300] = "";
	inputStringAndDelimeters(str, delimiters);
	CheckTimeAndWriteResult(str,timeStr, delimiters, word, indicator, result, maxLengthWord);
	return 0;
}
