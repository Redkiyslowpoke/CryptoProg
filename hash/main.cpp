#include <iostream>
#include <vector>
#include <fstream>
#include <cryptopp/hex.h> 
#include <cryptopp/sha.h> 

using namespace std;

int main (int argc, char* argv[])
{
    using namespace CryptoPP;
    
    SHA1 hash;

    ifstream f("TextToHash.txt");
    f.seekg(0,ios::end);
    int bazepsize = f.tellg();
    f.seekg(0,ios::beg);
    char* buf = new char[bazepsize];
    f.read(buf,bazepsize);
    string file = string(buf);
    file.erase(file.size()-1, 1);
    
    string digest;

    StringSource(file, true,             
                 new HashFilter(hash,       
                                new HexEncoder(     
                                    new StringSink(digest))));  
    // cout << file << endl;  демонстрация содержимого файла
    cout << digest << endl;
    f.close();
    return 0;
}