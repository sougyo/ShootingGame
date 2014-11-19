#include "fileReader.h"

using std::string;
using std::fstream;
using std::istringstream;
using std::ostringstream;
using gameutil::FileReader;

string FileReader::prevFileName = "";
string FileReader::decryptedString = "";

int FileReader::count = 0;

FileReader::FileReader(const char* fileName) {
	fstream fin(fileName, std::ios::in | std::ios::binary);
	assert(fin.good());
	string decryptedStr = decrypt(fin);
	in = new istringstream(decryptedStr);
	fin.close();

	count++;
}

FileReader::FileReader(const char* fileName, const char* virtualFileName) : in(0) {
	if (fileName != prevFileName) {
		fstream fin(fileName, std::ios::in | std::ios::binary);
		assert(fin.good());
		prevFileName = string(fileName);
		decryptedString = decrypt(fin);
		fin.close();
	}
	
	string headString = "###" + static_cast<string>(virtualFileName);

	int startIndex = static_cast<int>(decryptedString.find(headString)) + static_cast<int>(headString.size()) + 1;
	int lastIndex = static_cast<int>(decryptedString.find("%%%", startIndex)) - 1;
	in = new istringstream(decryptedString.substr(startIndex, lastIndex - startIndex));

	count++;
}

FileReader::~FileReader(void) {
	delete in;
	count--;
}

string FileReader::readLine(void) {
	assert(!in->eof());
	const int TEMPSIZE = 2000;
	char temp[TEMPSIZE];
	in->getline(temp, TEMPSIZE);
	return string(temp);
}

string FileReader::readAll(void) {
	string buffer;
	while (!in->eof()) {
		buffer.append(readLine()).append("\n");
	}
	return buffer;
}

string FileReader::decrypt(fstream& in) {
	ostringstream out;
	gameutil::Random random(28);
	char c;
	int count = -1;
	in.get(c);
	while (!in.eof()) {
		if (count % 6 != 0)
			out.put(static_cast<char>(static_cast<unsigned char>(c) ^ random.rand()));
		else
			random.rand();
		in.get(c);
		count++;
	}
	return out.str();
}
