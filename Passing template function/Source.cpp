#include <vector>
#include <numeric>
#include <functional>
#include <iostream>

int main()
{
	std::vector<int> vec(10);

	auto lambda = [&](auto&&... args)
	{
		return std::iota(std::forward<decltype(args)>(args)...);
	};

	//std::invoke(std::iota, std::begin(vec), std::end(vec), 0);
	std::invoke(lambda, std::begin(vec), std::end(vec), 0);

	for (auto value : vec)
	{
		std::cout << value << std::endl;
	}
}