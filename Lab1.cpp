#include <iostream>
#include <iomanip>

using namespace std;

double GetNumber();
template<typename T> void PrintBigEndian(T number);
template<typename T> void PrintLittleEndian(T number);

int main()
{
    cout << "Input your number: ";
    double number = GetNumber();

    cout << "int:\n";
    cout << "Big-Endian:";
    PrintBigEndian((int)number);
    cout << "\n";
    cout << "Little-Endian:";
    PrintLittleEndian((int)number);
    cout << "\n";

    cout << "float:\n";
    cout << "Big-Endian:";
    PrintBigEndian((float)number);
    cout << "\n";
    cout << "Little-Endian:";
    PrintLittleEndian((float)number);
    cout << "\n";

    cout << "double:\n";
    cout << "Big-Endian:";
    PrintBigEndian(number);
    cout << "\n";
    cout << "Little-Endian:";
    PrintLittleEndian(number);
    cout << "\n";

}

double GetNumber() 
{
    double number;
    cin >> number;
    return number;
}

template<typename T> void PrintBigEndian(T number)
{
    int sizebyte = sizeof(number);
    unsigned char* pt = (unsigned char*)&number;

    for (int i = sizebyte - 1; i >= 0; --i)
    {
        for (int j = (1 << 3) - 1; j >= 0; --j)
        {
            cout << !!(pt[i] & (1 << j));
        }
    }
}

template<typename T> void PrintLittleEndian(T number)
{
    int sizebyte = sizeof(number);
    unsigned char* pt = (unsigned char*)&number;

    for (int i = 0; i < sizebyte; ++i)
    {
        for (int j = (1 << 3) - 1; j >= 0; --j)
        {
            cout << !!(pt[i] & (1 << j));
        }
    }
}