#include <iostream>

class BaseClass
{
  public:
	std::string name;
	int myInt;
	int *myIntPtr;

	// Default Constructor
	BaseClass() : myInt(0), myIntPtr(new int(0)), name("BaseClass")
	{
		std::cout << "BaseClass default constructor called.\n";
	}

	// Parameterized Constructor
	BaseClass(int value, std::string name) : myInt(value), myIntPtr(new int(value)), name(name)
	{
		std::cout << "BaseClass parameterized constructor called." << std::endl;
	}

	// Copy Constructor
	BaseClass(const BaseClass &other) : myInt(other.myInt), myIntPtr(new int(*other.myIntPtr)), name(other.name)
	{
		std::cout << "BaseClass copy constructor called." << std::endl;
	}

	// Destructor
	virtual ~BaseClass()
	{
		std::cout << "BaseClass destructor called." << std::endl;
		std::cout << "myIntPtr before: " << myIntPtr << std::endl;
		delete myIntPtr;
		myIntPtr = NULL;
		std::cout << "myIntPtr after: " << myIntPtr << std::endl;
	}

	// Assignment Operator
	BaseClass &operator=(const BaseClass &other)
	{
		if (this != &other)
		{
			name = other.name;
			myInt = other.myInt;
			*myIntPtr = *other.myIntPtr;
		}
		return *this;
	}
};

class DerivedDeepCopy : public BaseClass
{
  public:
	std::string name;
	// Default Constructor
	DerivedDeepCopy() : name("DerivedDeepCopoy"), BaseClass()
	{
		std::cout << "DerivedDeepCopy default constructor called." << std::endl;
	}
	// Parameterized Constructor§
	DerivedDeepCopy(int value, std::string name) : name(name), BaseClass()
	{
		myIntPtr = new int(value);
		// We could also call the BaseClass constructor with a value, then we wouldn't need the line below
		myInt = value;

		std::cout << "DerivedDeepCopy parameter constructor called.\n";
	}

	// Copy Constructor that explicitly calls BaseClass's copy constructor

	DerivedDeepCopy(const DerivedDeepCopy &other) : BaseClass(other)
	{
		name = other.name;
		// myIntPtr = new int(*other.myIntPtr);
		std::cout << "DerivedDeepCopy copy constructor called.\n";
	}
	// The other way to do this is to call the default construcotr and manually copy the values, creating a new int
	// pointer DerivedDeepCopy(const DerivedDeepCopy &other) : BaseClass(other)
	// {
	// 	myIntPtr = new int(*other.myIntPtr);
	// 	std::cout << "DerivedDeepCopy copy constructor called.\n";
	// }
};

class DerivedShallowCopy : public BaseClass
{
  public:
	std::string name;
	// Default Constructor
	DerivedShallowCopy() : BaseClass()
	{
		name = "DerivedShallowCopy";
		std::cout << "DerivedShallowCopy default constructor called.\n";
	}
	// Constructor
	DerivedShallowCopy(int value, std::string name) : name(name), BaseClass(value, name)
	{
		std::cout << "DerivedShallowCopy parameter constructor called.\n";
	}

	// Shallow Copy Constructor (not calling BaseClass's copy constructor)
	DerivedShallowCopy(const DerivedShallowCopy &other) : BaseClass(other.myInt, other.name)
	{
		myIntPtr = other.myIntPtr;
		std::cout << "DerivedShallowCopy copy constructor called.\n";
	}

	// Destructor
	~DerivedShallowCopy()
	{
		std::cout << "DerivedShallowCopy destructor called." << std::endl;
		std::cout << "myIntPtr before: " << myIntPtr << std::endl;
		if (myIntPtr != NULL)
		{
			delete myIntPtr;
			myIntPtr = NULL;
		}
		std::cout << "myIntPtr after: " << myIntPtr << std::endl;
	}
	// Copy assignment operator
	DerivedShallowCopy &operator=(const DerivedShallowCopy &other)
	{
		if (this != &other)
		{
			name = other.name;
			myInt = other.myInt;
			myIntPtr = other.myIntPtr;
		}
		return *this;
	}
};

int main()
{
	// Initializing and setting values
	DerivedDeepCopy deep(10);
	DerivedShallowCopy shallow(20);

	// Making copies
	DerivedDeepCopy deepCopy = deep;
	DerivedShallowCopy shallowCopy = shallow;

	// Changing the value pointed by myIntPtr
	*deepCopy.myIntPtr = 100;
	*shallowCopy.myIntPtr = 200;

	std::cout << "Original deep value: " << *deep.myIntPtr << std::endl;
	std::cout << "Original shallow value: " << *shallow.myIntPtr << std::endl;

	return 0;
}
