#include "Electronic Components/Transistors/Transistor_Single_Connection_Nchannel.h"

Helper Transistor_Single_Connection_Nchannel_Helper;

Transistor_Single_Connection_Nchannel::Transistor_Single_Connection_Nchannel() : ElectronicComponent(150, 200, "Single Connection N-channel Transistor", 3){}

//Drawing the component:
void Transistor_Single_Connection_Nchannel::Show(){
    double up_left_x = getPositionUpLeft().x, up_left_y = getPositionUpLeft().y;
    double center_x = getPositionCenter().x, center_y = getPositionCenter().y;
    double down_right_x = getPositionDownRight().x, down_right_y = getPositionDownRight().y;

    if(flipped){
        up_left_x = getPositionDownRight().x;
        down_right_x = getPositionUpLeft().x;
    }

    double thisHeight = (down_right_x - up_left_x) / width_height_ratio;

    for(int i = 0; i <= height / 65; i++)
        Transistor_Single_Connection_Nchannel_Helper.rotationalCircle(
            center_x + thisHeight / 9, center_y, getPositionCenter(),  2 * height / 9 - i,
            rotateState);

    Transistor_Single_Connection_Nchannel_Helper.rotationalLine(
        down_right_x - thisHeight / 6, up_left_y + height / 15, down_right_x - thisHeight / 6, center_y - height / 15, getPositionCenter(),
        rotateState);

    Transistor_Single_Connection_Nchannel_Helper.rotationalLine(
        down_right_x - thisHeight / 6, down_right_y - height / 15, down_right_x - thisHeight / 6, center_y + height / 15, getPositionCenter(),
        rotateState);

    Transistor_Single_Connection_Nchannel_Helper.rotationalLine(
        down_right_x - thisHeight / 6, center_y - height / 15, center_x + thisHeight / 10, center_y - height / 15, getPositionCenter(),
        rotateState);

    Transistor_Single_Connection_Nchannel_Helper.rotationalLine(
        down_right_x - thisHeight / 6, center_y + height / 15, center_x + thisHeight / 10, center_y + height / 15, getPositionCenter(),
        rotateState);

    int points[] = {
             int(center_x + thisHeight / 20), int(center_y),
             int(center_x - thisHeight / 30), int(center_y + height / 15 - height / 20),
             int(center_x), int(center_y + height / 16)};

    Transistor_Single_Connection_Nchannel_Helper.rotationalFillPoly(
        3, points, getPositionCenter(),
        rotateState);

    settextstyle(8, HORIZ_DIR, 3);
    if(height / 50 > 2){
        Transistor_Single_Connection_Nchannel_Helper.rotationalOuttextxy(
            down_right_x - thisHeight / 6 - thisHeight / 5 - 5, up_left_y + height / 40, getPositionCenter(), "B1",
            rotateState);

        Transistor_Single_Connection_Nchannel_Helper.rotationalOuttextxy(
            up_left_x + thisHeight / 7, center_y - height / 10, getPositionCenter(), "E",
            rotateState);

        Transistor_Single_Connection_Nchannel_Helper.rotationalOuttextxy(
            down_right_x - thisHeight / 6 - thisHeight / 5 - 5, down_right_y - height / 40 - height / 6, getPositionCenter(), "B2",
            rotateState);
    }

    Transistor_Single_Connection_Nchannel_Helper.rotationalLine(
        up_left_x + thisHeight / 15, center_y + height / 15, center_x - thisHeight / 13, center_y + height / 15, getPositionCenter(),
        rotateState);

    Transistor_Single_Connection_Nchannel_Helper.rotationalLine(
        center_x - thisHeight / 13, center_y + height / 15, center_x + thisHeight / 20, center_y, getPositionCenter(),
        rotateState);

    int points1[] = {
        int(center_x + thisHeight / 20), int(center_y - height / 8),
        int(center_x + thisHeight / 10), int(center_y - height / 8),
        int(center_x + thisHeight / 10), int(center_y + height / 8),
        int(center_x + thisHeight / 20), int(center_y + height / 8),
    };

    Transistor_Single_Connection_Nchannel_Helper.rotationalFillPoly(
        4, points1, getPositionCenter(),
        rotateState);

    Transistor_Single_Connection_Nchannel_Helper.rotationalCircle(
            up_left_x + thisHeight / 30, center_y + height / 15, getPositionCenter(),  height / 30,
            rotateState);

    Transistor_Single_Connection_Nchannel_Helper.rotationalCircle(
            down_right_x - thisHeight / 6, up_left_y + height / 30, getPositionCenter(),  height / 30,
            rotateState);

    Transistor_Single_Connection_Nchannel_Helper.rotationalCircle(
            down_right_x - thisHeight / 6, down_right_y - height / 30, getPositionCenter(),  height / 30,
            rotateState);

    showElements();
}

void Transistor_Single_Connection_Nchannel::updateConnectionPointsPosition(){
    double up_left_x = getPositionUpLeft().x, up_left_y = getPositionUpLeft().y;
    double center_x = getPositionCenter().x, center_y = getPositionCenter().y;
    double down_right_x = getPositionDownRight().x, down_right_y = getPositionDownRight().y;

    if(flipped){
        up_left_x = getPositionDownRight().x;
        down_right_x = getPositionUpLeft().x;
    }

    double thisHeight = (down_right_x - up_left_x) / width_height_ratio;

    connectionPoints[0].position = Transistor_Single_Connection_Nchannel_Helper.rotatePointToReference(
        Transistor_Single_Connection_Nchannel_Helper.makeVector_2D(up_left_x + thisHeight / 30, center_y + height / 15),
        getPositionCenter(),
        rotateState);

    connectionPoints[1].position = Transistor_Single_Connection_Nchannel_Helper.rotatePointToReference(
        Transistor_Single_Connection_Nchannel_Helper.makeVector_2D(down_right_x - thisHeight / 6, up_left_y + height / 30),
        getPositionCenter(),
        rotateState);

    connectionPoints[2].position = Transistor_Single_Connection_Nchannel_Helper.rotatePointToReference(
        Transistor_Single_Connection_Nchannel_Helper.makeVector_2D(down_right_x - thisHeight / 6, down_right_y - height / 30),
        getPositionCenter(),
        rotateState);
}
