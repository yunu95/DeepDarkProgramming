#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>

using namespace std;

void main()
{
	string sentence;

	ifstream inFile;
	inFile.open("overwatch.txt");//open the input file

	stringstream strStream;
	strStream << inFile.rdbuf();//read the file
	sentence = strStream.str();

	std::cout << sentence << std::endl;

	string input;

	auto begin = std::chrono::high_resolution_clock::now();

	std::getline(std::cin, input);

	auto end = std::chrono::high_resolution_clock::now();

//	std::cout << input << std::endl;
	
	std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "ms" << std::endl;

	std::cout << sentence.compare(input) << std::endl;
}