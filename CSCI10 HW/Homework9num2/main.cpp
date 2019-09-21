#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ofstream out_file;
    out_file.open("hello.cpp");
    out_file << "#include <iostream>" << endl << endl;
    out_file << "using namespace std;" << endl << endl;
    out_file << "int main()" << endl << "{" << endl;
    out_file << "      cout << \"Hello world!\" << endl;" << endl;
    out_file << "      return 0;" << endl;
    out_file << "}";
    out_file.close();
    return 0;
}
