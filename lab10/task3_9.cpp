#include <iostream>

using namespace std;

class Shapes
{
protected:
    float length;
    float width;
    float area;

public:
    Shapes() {}
    ~Shapes() {}

    virtual float getLen() = 0;
    virtual float getWid() = 0;
    virtual float getArea() = 0;
    virtual void set() = 0;
};

class Shape2D : protected Shapes
{
public:
    Shape2D() {}
    virtual void set() = 0;
};

class Shape3D : protected Shapes
{
protected:
    float height;
    float volume;

public:
    Shape3D() {}
    virtual float getVol() = 0;
    virtual float getHgt() = 0;
};

class Circle : protected Shape2D
{
public:
    Circle()
    {
        length = 0;
    }
    ~Circle() {}
    void set()
    {
        cout << "Enter radius: ";
        cin >> length;

        width = length;
        area = 3.14 * length * length;
    }

    float getLen()
    {
        return length;
    }

    float getArea()
    {
        return area;
    }
};

class Square : protected Shape2D
{
public:
    Square()
    {
        length = 0;
    }
    ~Square() {}
    void set()
    {
        cout << "Enter radius: ";
        cin >> length;

        width = length;
        area = length * width;
    }

    float getLen()
    {
        return length;
    }

    float getArea()
    {
        return area;
    }
};

class Cube : protected Shape3D
{
public:
    Cube()
    {
        length = width = height = 0;
    }
    ~Cube() {}

    void set()
    {
        cout << "Enter length";
        cin >> length;

        height = width = length;
        area = length * length;
        volume = length * length * length;
    }

    float getLen()
    {
        return length;
    }

    float getArea()
    {
        return area;
    }

    float getVol()
    {
        return volume;
    }
};

class Pyramid : protected Shape3D
{
public:
    Pyramid()
    {
        length = width = height = 0;
    }
    ~Pyramid() {}

    void set()
    {
        cout << "Enter length";
        cin >> length;
        cout << "Enter width";
        cin >> width;
        cout << "Enter height";
        cin >> height;

        area = length * width;
        volume = (length * width * height) / 3;
    }

    float getLen()
    {
        return length;
    }

    float getArea()
    {
        return area;
    }

    float getVol()
    {
        return volume;
    }
};

int main()
{
}