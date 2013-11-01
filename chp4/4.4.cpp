#include <iostream>
#include <string>
#include <iomanip>

using namespace std; 
int main()
{
	char ch = char(0);
	int i;
	
	for (i = 0;  i <= 127; ch++,i++) {
		std::cout << ch << ":" << int(ch) << std::endl;
	}
	
	for (i = 0, ch = char(0);  i <= 127; ch++,i++) {
                std::cout << ch << ":" << hex << "0x" << int(ch) << std::endl;
        }

}
