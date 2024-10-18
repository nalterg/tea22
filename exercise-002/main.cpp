#include <fmt/chrono.h>
#include <fmt/format.h>


static int foo = 42;

void doSomething(int value) {
    value += 1;
    fmt::print("doSomething, value {}\n", value);
}

void doSomethingPtr(int* ptr) {
    *ptr += 1;
    fmt::print("doSomething, value {}\n", *ptr);
}

void doSomethingStatic() {
    static int value = 56;// wird nur beim ersten aufführen gestzt, danach wachst die variable
    value += 1;
    fmt::print("doSomething, value {}\n", value);
}

int* doReturnAPtr(){
    static int value = 4711;
    fmt::print("doReturnAPtr, value {}\n", value);
    return &value; // Niemals ein Zeiger innerhalb einer Funktion auf einer lokalen Variabel returnen(static bleibt statisch--> kp)
}


auto main(int argc, char **argv) -> int
{  
    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */
    fmt::print("Hello, {}!\n", argv[0]);
    fmt::print("Value of foo {} address of foo {}\n", foo, fmt::ptr(&foo));

    int bar = 42;
    doSomethingPtr(&bar);
    fmt::print("The value of bar is: {}\n", bar);    

    int* returnedPtr = doReturnAPtr();
    fmt::print("The value of returnedPtr is: {}\n", *returnedPtr);
    doSomething(32);
    fmt::print("The value of returnedPtr is: {}\n", *returnedPtr);

    doSomethingStatic();
    doSomethingStatic();
    doSomethingStatic();
    return 0; /* exit gracefully*/
}
