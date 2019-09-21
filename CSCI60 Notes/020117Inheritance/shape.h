#ifndef SHAPE_H
#define SHAPE_H


shape::shape()
{
private:
    double x_;
    double y_;
public:
    shape();
    shape(double x, double y);
    double y() const;
    void setY(double Y);
    double x() const;
    void setX(double x);

};
#endif // SHAPE_H
