#include <iostream>
#include <windows.h>
#include <string>

using namespace std;

int main() {
    setlocale(LC_ALL, "RUS");
    string S, C;
    cout << "Ваше слово: ";
    getline(cin, S);
    cout << "Символ для поиска: ";
    getline(cin, C);
    HINSTANCE load = LoadLibrary(L"DinamicLib.dll");
  
    typedef bool (*ContainsAllCharactersFunc)(const char*, const char*);
    ContainsAllCharactersFunc A = (ContainsAllCharactersFunc)GetProcAddress(load, "AllCharacters");
   
    bool result = A(S.c_str(), C.c_str());
    if (result) {
        cout << "ЕСТЬ" << endl;
    }
    else {
        cout << "НЕТУ" << endl;
    }
    FreeLibrary(load);
}