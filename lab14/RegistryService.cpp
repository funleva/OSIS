#include "stdafx.h"
#include "RegistryService.h"
#include <iostream>
#include <algorithm>

using namespace std;

void RegistryService::searchInKey(HKEY hRootKey, wstring path) {
	TCHAR keyName[4096];
	DWORD subkeysCount = 0;
	HKEY hKey;
	FILETIME ftLastWriteTime;
	int retCode;

	if (RegOpenKeyEx(hRootKey, path.c_str(), 0, KEY_READ, &hKey) != ERROR_SUCCESS) {
		return;
	};

	retCode = RegQueryInfoKey(hKey, NULL, NULL, NULL, &subkeysCount, NULL, NULL, NULL, NULL, NULL, NULL, NULL);

	for (int i = 0; i < subkeysCount; i++) {
		DWORD keySize = sizeof(keyName);
		retCode = RegEnumKeyEx(hKey, i, keyName, &keySize, NULL, NULL, NULL, &ftLastWriteTime);
		if (retCode == ERROR_SUCCESS) {
			wstring relativePath = path + keyName + L"\\";
			wstring keyFullPath = this->getKeyPath(hRootKey) + relativePath;
			if (isMatch(keyFullPath)) {
				this->addToList(this->resultList, keyFullPath);
			}
			deep += 1;
			this->searchInKey(hRootKey, relativePath);
			deep -= 1;
		}
	}
}

wstring RegistryService::getKeyPath(HKEY hRootKey) {
	if (hRootKey == HKEY_CLASSES_ROOT) {
		return L"HKCR\\";
	} else if (hRootKey == HKEY_CURRENT_USER) {
		return L"HKCU\\";
	} else if (hRootKey == HKEY_LOCAL_MACHINE) {
		return L"HKLM\\";
	} else if (hRootKey == HKEY_USERS) {
		return L"HKU\\";
	} else if (hRootKey == HKEY_CURRENT_CONFIG) {
		return L"HKCC\\";
	} else {
		return L"";
	}
}

bool RegistryService::isMatch(wstring str) {
	return this->toLower(str).find(this->toLower(query)) != -1;
}

wstring RegistryService::toLower(wstring str) {
	wstring result;
	result.reserve(str.length());
	for (size_t i = 0; i < str.length(); i++) {
		result.push_back(tolower(str[i]));
	}
	return result;
}

void RegistryService::search(wstring query, vector<HKEY> searchKeys) {
	this->query = query;
	for (auto it = searchKeys.begin(); it != searchKeys.end(); it++) {
		searchInKey((*it), L"");
	}
}

void RegistryService::addToList(HWND hList, wstring str) {
	SendMessage(hList, LB_ADDSTRING, 0, (LPARAM)(str.c_str()));
}

RegistryService::RegistryService(HWND hList) {
	this->resultList = hList;
}