#include "Electronic Components/Diodes/Diode_Schottky.h"
//Tamas Luca-Stefan
Helper Diode_Schottky_Helper;

Diode_Schottky::Diode_Schottky(): ElectronicComponent(200, 50, "Schottky Diode", 2) {}

//Drawing the component:
void Diode_Schottky::Show()
{
    double up_left_x = getPositionUpLeft().x, up_left_y = getPositionUpLeft().y;
    double center_x = getPositionCenter().x, center_y = getPositionCenter().y;
    double down_right_x = getPositionDownRight().x, down_right_y = getPositionDownRight().y;

    if(flipped)
    {
        up_left_x = getPositionDownRight().x;
        down_right_x = getPositionUpLeft().x;
    }

    double thisHeight = (down_right_x - up_left_x) / width_height_ratio;

    Diode_Schottky_Helper.rotationalCircle(
        up_left_x + thisHeight / 10, center_y, getPositionCenter(), height / 10,
        rotateState);

    Diode_Schottky_Helper.rotationalLine(
        up_left_x + thisHeight / 5, center_y, center_x - thisHeight / 2, center_y, getPositionCenter(),
        rotateState);

    Diode_Schottky_Helper.rotationalLine(
        center_x - thisHeight / 2, up_left_y, center_x - thisHeight / 2, down_right_y, getPositionCenter(),
        rotateState);

    Diode_Schottky_Helper.rotationalLine(
        center_x - thisHeight / 2, up_left_y, center_x + thisHeight / 2, center_y, getPositionCenter(),
        rotateState);

    Diode_Schottky_Helper.rotationalLine(
        center_x - thisHeight / 2, down_right_y, center_x + thisHeight / 2, center_y, getPositionCenter(),
        rotateState);

    Diode_Schottky_Helper.rotationalLine(
        center_x + thisHeight / 2, up_left_y, center_x + thisHeight / 2, down_right_y, getPositionCenter(),
        rotateState);

    Diode_Schottky_Helper.rotationalLine(
        center_x + thisHeight / 2, up_left_y, center_x + thisHeight / 2 + thisHeight / 5, up_left_y, getPositionCenter(),
        rotateState);

    Diode_Schottky_Helper.rotationalLine(
        center_x + thisHeight / 2 + thisHeight / 5, up_left_y, center_x + thisHeight / 2 + thisHeight / 5, up_left_y + height / 5, getPositionCenter(),
        rotateState);

    Diode_Schottky_Helper.rotationalLine(
        center_x + thisHeight / 2, down_right_y, center_x + thisHeight / 2 - thisHeight / 5, down_right_y, getPositionCenter(),
        rotateState);

    Diode_Schottky_Helper.rotationalLine(
        center_x + thisHeight / 2 - thisHeight / 5, down_right_y, center_x + thisHeight / 2 - thisHeight / 5, down_right_y - height / 5, getPositionCenter(),
        rotateState);

    Diode_Schottky_Helper.rotationalLine(
        center_x + thisHeight / 2, center_y, down_right_x - thisHeight / 5, center_y, getPositionCenter(),
        rotateState);

    Diode_Schottky_Helper.rotationalCircle(
        down_right_x - thisHeight / 10, center_y, getPositionCenter(), height / 10,
        rotateState);

    showElements();

}

void Diode_Schottky::updateConnectionPointsPosition()
{

    double up_left_x = getPositionUpLeft().x, up_left_y = getPositionUpLeft().y;
    double center_x = getPositionCenter().x, center_y = getPositionCenter().y;
    double down_right_x = getPositionDownRight().x, down_right_y = getPositionDownRight().y;

    if(flipped)
    {
        up_left_x = getPositionDownRight().x;
        down_right_x = getPositionUpLeft().x;
    }

    double thisHeight = (down_right_x - up_left_x) / width_height_ratio;

    connectionPoints[0].position = Diode_Schottky_Helper.rotatePointToReference(
                                       Diode_Schottky_Helper.makeVector_2D(up_left_x + thisHeight / 10, center_y),
                                       getPositionCenter(),
                                       rotateState);

    connectionPoints[1].position = Diode_Schottky_Helper.rotatePointToReference(
                                       Diode_Schottky_Helper.makeVector_2D(down_right_x - thisHeight / 10, center_y),
                                       getPositionCenter(),
                                       rotateState);
}
