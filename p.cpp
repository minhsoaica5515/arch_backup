#include <iostream>
#include <bits/stdc++.h>

int main()
{
	std::string x[5] = {"aa", "cc", "ff", "rr", "qq"};
	std::string *p1 = x;
	std::cout << sizeof(x) << "---" << sizeof(p1)<< "\n";
	return 0;
}
