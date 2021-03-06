#ifndef BUTTON_H
#define BUTTON_H

#include "string.h"

#include "Helper.h"
#include "Enums.h"

//daria
class Button
{
protected:
    //Reference points:
    struct
    {
        Helper::Vector_2D up_left, center, down_right;
    } position;
    PositionType positionType = up_left;
    //Dimensions of the component:
    std::string title;

public:
    Button(double thisWidth = 100, double thisHeight = 50, std::string thisTitle = "Button");

    double width = 100, height = 50;

    //Setters:
    void setPositionUpLeft(Helper::Vector_2D thisPosition);
    void setPositionCenter(Helper::Vector_2D thisPosition);
    void setPositionDownRight(Helper::Vector_2D thisPosition);
    void setWidth(double thisWidth);
    void setHeight(double thisHeight);
    void setTitle(std::string thisTitle);

    //Getters:
    Helper::Vector_2D getPositionUpLeft();
    Helper::Vector_2D getPositionCenter();
    Helper::Vector_2D getPositionDownRight();
    double getWidth();
    double getHeight();
    std::string getTitle();

    bool isCursorPointInButton();

    //Show the component:
    void Show();
    void ShowCircleMode();
    void ShowBox();

    void Hide();

    //Parsing the component's data to string:
};

#endif // BUTTON_H
