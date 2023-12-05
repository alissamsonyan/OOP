#ifndef SLIDE_H
#define SLIDE_H


class ISlideCollection
{
    ISlideCollection() = default;
private:
    virtual void CreatSlide();
    virtual void RemoveSlide();
    virtual void AddSlide();

};



#endif // SLIDE_H
