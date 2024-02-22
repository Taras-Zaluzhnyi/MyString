#include <iostream>
#include <string>


/*
	Realize:
	strlen()  diznaetsa dovshuny ryadka
	insert() vstavlae simvol za indexom
	erase()  vidalae simvol za indeksom
	clear()  ochischye ryadok
	swap()
	find()  shukae indeks pershogo simvoly/pidryadka
	find_if()
*/




class MyString
{
public:
	// Default constructor
	MyString() = default;

	//Constructor w param
	explicit MyString(const char* str)
	{
		CreateString(str);
	}

	//Copy constructor
	MyString(const MyString& other)
	{
		CreateString(other.str);
	}

	//Move constructor
	MyString(MyString&& other) noexcept : str(other.str), length{ other.length }
	{
		other.str = nullptr;
	}

	//Overload operator= copy-assingment
	MyString& operator = (const MyString& other)
	{
		if (this->str != nullptr)
		{
			delete[] this->str;
		}

		CreateString(other.str);

		return *this;
	}

	//Overload operator= move-assingment
	MyString& operator = (MyString&& other) noexcept
	{
		if (this->str != nullptr)
		{
			delete[] this->str;
		}

		this->length = other.length;
		this->str = other.str;
		other.str = nullptr;

		return *this;
	}

	//Destructor
	~MyString()
	{
		delete[] this->str;
	}

	const char* c_str() const
	{
		return str;
	}

	//Concatenation
	MyString operator+(const MyString& other) const
	{
		MyString newStr;
		newStr.str = new char[strlen(this->str) + strlen(other.str) + 1];
		newStr.length = strlen(this->str) + strlen(other.str);

		int i = 0;
		for(; i < strlen(this->str); ++i)
		{
			newStr.str[i] = this->str[i];
		}
		for (int j = 0; j < strlen(other.str); ++i, ++j)
		{
			newStr.str[i] = other.str[j];  //???????????????????????????????????????????
		}
		newStr.str[strlen(this->str) + strlen(other.str)] = '\0';

		return newStr;
	}

	bool operator== (const MyString& other) const
	{
		if (this->length != other.length)
		{
			return false;
		}

		for (int i = 0; i < length; ++i)
		{
			if (this->str[i] != other.str[i])
			{
				return false;
			}
		}
		return true;
	}

	bool operator!= (const MyString& other) const
	{
		return !(operator==(other));
	}

	char& operator[] (size_t index) const
	{
		return str[index];
	}

	MyString& operator+= (const char* string)
	{
		return operator=(operator+(MyString(string)));
	}

	// return string.length
	size_t Length() const
	{
		return length;
	}

	//Print string
	void PrintStr() const
	{
		std::cout << str << '\n';
	}


private:
	char* str;

	size_t length;

	void CreateString(const char* string)
	{
		length = strlen(string); //Realize strlen
		this->str = new char[length + 1];
		for (int i = 0; i < length; ++i)
		{
			this->str[i] = string[i];
		}
		this->str[length] = '\0';
	}
};

std::ostream& operator<< (std::ostream& stream, const MyString& str)
{
	return stream << str.c_str();
}


int main()
{
	MyString str("Hello");
	MyString str2("world");
	MyString str3;

	str3 = str + str2;

	str = str2;

	str.PrintStr();

	str2.PrintStr();

	str3.PrintStr();

	std::cout << (str == str2) << '\n';

	str.PrintStr();

	str[0] = 'm';

	std::cout << str << '\n';


	return EXIT_SUCCESS;
}