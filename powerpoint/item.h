#ifndef ITEM_H
#define ITEM_H

class IItem
    {
        IItem() = default;
    public:
        virtual void AddItem() = 0;
        virtual void moveItem() = 0;
        virtual void removeItem() = 0;

    };
class Line: public IItem
    {
        Line() = default;
    private:
        double startX;
        double startY;
        double endX;
        double endY;
    };

    class Circuit: public IItem
    {
        Circuit() = default;
    private:
        double radius;
        double centerX;
        double cebterY;
    };

    class Squer: public IItem
    {
        Squer() = default;
    private:
        double size;
        double centerX;
        double centerY;
    };

    class Tringel: public IItem
    {

        Tringel() = default;
    private:
        double x_1;
        double y_1;
        double x_2;
        double y_2;
        double x_3;
        double y_3;

    };


#endif // ITEM_H
