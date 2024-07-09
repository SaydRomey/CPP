
/*

VIRTUAL FUNCTIONS:
Enable polymorphism, allowing derived classes to override base class functions.

A virtual function is a member function in a base class that we expect to override in derived classes.

When we use a virtual function, we enable polymorphism in C++,
allowing a call to a member function to execute different function code
depending on the type of the object that invokes the function.
*/

class Base {
public:
    virtual void show() { // Virtual function
        std::cout << "Base class show function\n";
    }
};

class Derived : public Base {
public:
    void show() override { // Override in derived class
        std::cout << "Derived class show function\n";
    }
};

int main() {
    Base *basePtr;
    Derived derivedObj;
    basePtr = &derivedObj;

    basePtr->show(); // Calls Derived's show() because of virtual function
    return 0;
}

/*
Explanation:
Base class has a show function marked as virtual.
Derived class overrides this function.
When basePtr (a Base*) points to a Derived object and calls show(),
the Derived version of show() is called, demonstrating runtime polymorphism.
*/

////////////////////////////////////////////////////////////////////////////////

/*

NO EXCEPT / OVERRIDE

noexcept: Indicates that a function does not throw exceptions, enabling optimizations and stronger guarantees.

The noexcept specifier indicates that
a function does not throw any exceptions.
This helps the compiler optimize the function better
and also provides stronger exception guarantees to the caller.
*/

void myFunction() noexcept {
    // Function guaranteed not to throw exceptions
}

/*
override: Ensures a function overrides a base class function, catching errors at compile time.

The override specifier ensures that the function is overriding a virtual function from a base class.
If the function does not actually override a base class function,
the compiler will generate an error.
*/

class Base {
public:
    virtual void myFunction() {
        std::cout << "Base function\n";
    }
};

class Derived : public Base {
public:
    void myFunction() override { // Ensures this overrides Base's myFunction
        std::cout << "Derived function\n";
    }
};

/*
noexcept override:
Combining noexcept and override indicates that
the overriding function does not throw exceptions
and ensures it is correctly overriding a base class function.
*/

class Base {
public:
    virtual void myFunction() noexcept {
        std::cout << "Base function\n";
    }
};

class Derived : public Base {
public:
    void myFunction() noexcept override { // Ensures correct override and no exceptions
        std::cout << "Derived function\n";
    }
};

////////////////////////////////////////////////////////////////////////////////

/*

EXPLICIT

explicit: Prevents implicit conversions and copy-initialization, making code safer and more predictable.

The explicit specifier is used with constructors to prevent implicit conversions and copy-initialization.
It helps avoid unintended conversions, making the code more robust and easier to understand.
*/

class MyClass {
public:
    explicit MyClass(int x) {
        // Constructor
    }
};

int main() {
    MyClass obj1(10); // OK: Direct initialization
    // MyClass obj2 = 10; // Error: Copy-initialization not allowed due to explicit
    return 0;
}

/*
Explanation:
MyClass(int x) is marked as explicit.
Direct initialization (MyClass obj1(10)) is allowed.
Copy-initialization (MyClass obj2 = 10) is not allowed, preventing unintended implicit conversions.
*/
