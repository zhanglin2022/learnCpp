#include <string>
#include <utility>

// just for 2D shape
class Shape {
public:
    typedef std::pair<double, double> Coordinate;

    Shape() = default;
    Shape(const std::string &n) : 
        name(n) { }
    
    virtual double area() const = 0;
    virtual double perimeter() const = 0;

    virtual ~Shape() = default;

private:
    std::string name;
};

class Retangle : public Shape {
public:
    Retangle() = default;
    Retangle(const std::string &n, 
             const Coordinate &a, 
             const Coordinate &b, 
             const Coordinate &c, 
             const Coordinate &d) :
        Shape(n), a_(a), b_(b), c_(c), d_(d) { }
    
    ~Retangle() = default;

protected:
    Coordinate a_;
    Coordinate b_;
    Coordinate c_;
    Coordinate d_;
};

class Square: public Retangle {
public:
    Square() = default;
    Square(const std::string &n, 
           const Coordinate &a,
           const Coordinate &b,
           const Coordinate &c, 
           const Coordinate &d) :
        Retangle(n, a, b, c, d) { }

    ~Square() = default;
};

int main() {
    return 0;
}
