# include <iostream>
# include <iomanip>

typedef struct Data
{
	std::string str;
} Data;

uintptr_t serialize(Data* ptr)
{
	uintptr_t res = reinterpret_cast<uintptr_t>(ptr);
	return res;
}

Data* deserialize(uintptr_t raw)
{
	Data* hello = reinterpret_cast<Data*>(raw);
	return hello;
}

int main(void)
{
	Data hello;
	hello.str = "Hello world!";
	uintptr_t a = serialize(&hello);
	Data *b = deserialize(a);
	std::cout << b->str << std::endl;
}
