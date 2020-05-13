#pragma once
#include <string>
#include <vector>

#define MAX_KEY_LENGTH 2048
#define MAX_VALUE_NAME 16383

using namespace std;

class RegistryService {
private:
	vector<wstring> searchResults;
	wstring query;
	HWND resultList;
	int deep = 0;
	void searchInKey(HKEY hKey, wstring path);
	wstring getKeyPath(HKEY key);
	bool isMatch(wstring str);
	wstring toLower(wstring str);
	void addToList(HWND hList, wstring str);
public:
	void search(wstring query, vector<HKEY> searchKeys);
	RegistryService(HWND hList);
};

