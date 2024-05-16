#include <iostream>
#include <map>
#include <mutex>


int main()
{
	std::map<int, int> dict;
	auto it = dict.find(10);
	if (it != dict.end())
    {
        // ...
    }

	/*
	If the scope of a value visiable only inside condition statment "if" or "switch" then use:
	if (init; cond) {
		// TODO ...
    }
	*/
	if (auto it = dict.find(10); it != dict.end())
	{
		// std::cout << *it << std::endl;
	}

	return 0;
}