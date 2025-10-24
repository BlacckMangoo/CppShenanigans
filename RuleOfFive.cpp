#include  <iostream>


class Vector {

public :

Vector() : x(0), y(0), z(0) {

    std::cout << "Constructor" << std::endl;
};
    ~Vector() {
        std::cout << "Destructor" << std::endl;
    };



    // copy constructor

    Vector(const Vector& other) : x(other.x), y(other.y), z(other.z) {

        std::cout << "Copy Constructor" << std::endl;
    };


    // copy assignment operator

    Vector& operator=(const Vector& rhs) {
        if (this != &rhs) {
            x = rhs.x;
            y = rhs.y;
            z = rhs.z;
        }
        std::cout << "Copy Assignment Operator" << std::endl;
        return *this;
    }

    // move constructor
    Vector(Vector&& other) {
        x = other.x;
        y = other.y;
        z = other.z;
        other.x = 10;
        other.y = 10;
        other.z = 10;
        std::cout << "Move Constructor" << std::endl;
    };

    Vector& operator=(Vector&& rhs) {
        if (this != &rhs) {
            x = rhs.x;
            y = rhs.y;
            z = rhs.z;
            rhs.x = 0;
            rhs.y = 0;
            rhs.z = 0;

            std::cout << "Move Assignment Operator" << std::endl;

        }
        return *this;
    }


    float x,y,z;

};

int main() {
    Vector a ;
    Vector b ;
    b.x = 10 ;
    b.y = 20 ;
    b.z = 30 ;

    a = std::move(b);
    std::cout << "a: " << a.x << ", " << a.y << ", " << a.z << std::endl;
    std::cout << "b: " << b.x << ", " << b.y << ", " << b.z << std::endl;


    Vector c = std::move(a);
    std::cout << "c: " << c.x << ", " << c.y << ", " << c.z << std::endl;
    std::cout << "a: " << a.x << ", " << a.y << ", " << a.z << std::endl;
}