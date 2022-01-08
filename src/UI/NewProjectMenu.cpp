#include "UI/NewProjectMenu.h"
#include "Data Structures/Snapshot.h"

#define BUTTON_HEIGHT 25
#define COMPONENT_SIZE 100
#define BORDER_SPACE 10

Helper NewProjectMenu_helper;

NewProjectMenu::NewProjectMenu()
{
}

void NewProjectMenu::drawWiresForComponent(std::string thisComponentCode)
{

    ElectronicComponent **currentComponents = currentSnapshot.getComponents();

    int index = 0;

    while (currentComponents[index]->componentCode != thisComponentCode && index < 100)
        index++;

    ElectronicComponent *currentComponent = currentComponents[index];

    for (int i = 0; i < currentComponent->getNumberOfConnectionPoints(); i++)
    {

        if (currentComponent->getConnectionPoints()[i].connectedIndex != -1)
        {

            std::string connectedComponentCode = currentComponent->getConnectionPoints()[i].connectedComponentCode;
            int connectedIndex = currentComponent->getConnectionPoints()[i].connectedIndex;

            NewProjectMenu_helper.drawWire(
                currentComponent->getConnectionPoints()[i].position,
                currentSnapshot.getComponent(connectedComponentCode)->getConnectionPoints()[connectedIndex].position,
                WHITE);
        }
    }
}

void NewProjectMenu::WatchClick()
{
    int ok = 1;

    Helper helper;
    int windowWidth = getwindowwidth();
    int windowHeight = getwindowheight();

    int cType = _none;
    iscurrentSnapshotelected = false;

    while (ok)
    {
        if (GetAsyncKeyState(VK_LBUTTON) && !GetAsyncKeyState(VK_LCONTROL))
        {
            std ::cout << "click " << std ::endl;
            if (save.isCursorPointInButton())
            {
                //currentSnapshot.saveToFile("text.xml");

                nameFileMenu.Show();
                int code = nameFileMenu.ListenEvents();
                setcurrentwindow(this->window_code);

                bgiout << code << " " << nameFileMenu.filename << std ::endl;
                outstreamxy(windowWidth / 5, windowHeight / 4);

                if (code)
                {
                    currentSnapshot.saveToFile(nameFileMenu.filename + ".xml");
                }
            }
            else if (capacitors.isCursorPointInButton())
            {
                std::cout << "capacitors" << std::endl;
                CapacitorsInfo capacitorsInfo;
                capacitorsInfo.Show((double)(windowWidth / 7), (double)(windowHeight / 3));
                cType = capacitorsInfo.WatchClick();

                std ::cout << "ctype " << cType << std ::endl;
            }
            else if (diodes.isCursorPointInButton())
            {
                std::cout << "diodes" << std::endl;
                DiodesInfo diodesInfo;
                diodesInfo.Show((double)(windowWidth / 7), (double)(windowHeight / 9));
                cType = diodesInfo.WatchClick();

                std ::cout << "ctype " << cType << std ::endl;
            }
            else if (logicGates.isCursorPointInButton())
            {
                std::cout << "logic gates" << std::endl;
                LogicGatesInfo logicGatesInfo;
                logicGatesInfo.Show((double)(windowWidth / 7), (double)(windowHeight / 5));
                cType = logicGatesInfo.WatchClick();

                std ::cout << "ctype " << cType << std ::endl;
            }
            else if (measurements.isCursorPointInButton())
            {
                std::cout << "measurements" << std::endl;
                MeasurementsInfo measurementsInfo;
                measurementsInfo.Show((double)(windowWidth / 7), (double)(windowHeight / 2));
                cType = measurementsInfo.WatchClick();

                std ::cout << "ctype " << cType << std ::endl;
            }
            else if (resistors.isCursorPointInButton())
            {
                std::cout << "resistors" << std::endl;
                ResistorsInfo resistorsInfo;
                resistorsInfo.Show((double)(windowWidth / 7), (double)(windowHeight / 6));
                cType = resistorsInfo.WatchClick();

                std ::cout << "ctype " << cType << std ::endl;
            }
            else if (sources.isCursorPointInButton())
            {
                std::cout << "sources" << std::endl;
                SourcesInfo sourcesInfo;
                sourcesInfo.Show((double)(windowWidth / 7), (double)(windowHeight / 3));
                cType = sourcesInfo.WatchClick();

                std ::cout << "ctype " << cType << std ::endl;
            }
            else if (switches.isCursorPointInButton())
            {
                std::cout << "switches" << std::endl;
                SwitchesInfo switchesInfo;
                switchesInfo.Show((double)(windowWidth / 7), (double)(windowHeight / 5));
                cType = switchesInfo.WatchClick();

                std ::cout << "ctype " << cType << std ::endl;
            }
            else if (transistors.isCursorPointInButton())
            {
                std::cout << "transistors" << std::endl;
                TransistorsInfo transistorsInfo;
                transistorsInfo.Show((double)(windowWidth / 8), (double)(windowHeight / 8));
                cType = transistorsInfo.WatchClick();

                std ::cout << "ctype " << cType << std ::endl;
            }
            else if (other.isCursorPointInButton())
            {
                std::cout << "other" << std::endl;
                OtherInfo otherInfo;
                otherInfo.Show((double)(windowWidth / 7), (double)(windowHeight / 5));
                cType = otherInfo.WatchClick();

                std ::cout << "ctype " << cType << std ::endl;
            }
            else if (exit.isCursorPointInButton())
            {
                currentSnapshot.reset();
                ok = 0;
            }
            else if (cType != _none)
            {
                std ::cout << "i m here " << cType << std ::endl;
                POINT cursorPoint;
                GetCursorPos(&cursorPoint);
                setcurrentwindow(this->window_code);

                bool isNotBounded = (cursorPoint.x - COMPONENT_SIZE / 2) < this->rl ||
                                    (cursorPoint.y - COMPONENT_SIZE / 2) < this->rt ||
                                    (cursorPoint.x + COMPONENT_SIZE / 2) > this->rr ||
                                    (cursorPoint.y + COMPONENT_SIZE / 2) > this->rb;
                if (!isNotBounded)
                {
                    currentSnapshot.addComponent(cType);
                    // std::cout << currentSnapshot.getNumberOfcurrentSnapshot() << " " << currentSnapshot.getSelectedComponent()->toString() << std :: endl;

                    if (currentSnapshot.getSelectedComponent())
                    {
                        currentSnapshot.getSelectedComponent()->setWidth(COMPONENT_SIZE);
                        currentSnapshot.getSelectedComponent()->setPositionCenter(helper.makeVector_2D(cursorPoint.x, cursorPoint.y));
                    }
                }

                cType = _none;
            }
            
            // if (cType == _none && currentSnapshot.getSelectedComponent() && !currentSnapshot.getSelectedComponent() -> isCursorPointInButton())
            // {
            //     currentSnapshot.getSelectedComponent()->setOutterBox(false);
            // }

            if (flip_h.isCursorPointInButton() && currentSnapshot.getSelectedComponent())
            {
                currentSnapshot.getSelectedComponent()->flipComponent();

                drawWiresForComponent(currentSnapshot.getSelectedComponent()->componentCode);

                delay(300);
            }

            if (flip_v.isCursorPointInButton() && currentSnapshot.getSelectedComponent())
            {
                currentSnapshot.getSelectedComponent()->flipComponent();
                currentSnapshot.getSelectedComponent()->rotateComponent(currentSnapshot.getSelectedComponent()->getRotationState() + 180);

                drawWiresForComponent(currentSnapshot.getSelectedComponent()->componentCode);

                delay(300);
            }

            if (rotate_l.isCursorPointInButton() && currentSnapshot.getSelectedComponent())
            {
                currentSnapshot.getSelectedComponent()->rotateComponent(currentSnapshot.getSelectedComponent()->getRotationState() - 15);

                drawWiresForComponent(currentSnapshot.getSelectedComponent()->componentCode);
            }

            if (rotate_r.isCursorPointInButton() && currentSnapshot.getSelectedComponent())
            {
                currentSnapshot.getSelectedComponent()->rotateComponent(currentSnapshot.getSelectedComponent()->getRotationState() + 15);

                drawWiresForComponent(currentSnapshot.getSelectedComponent()->componentCode);
            }

            if (inc.isCursorPointInButton() && currentSnapshot.getSelectedComponent())
            {
                currentSnapshot.getSelectedComponent()->setWidth(currentSnapshot.getSelectedComponent()->getWidth() + 15);

                drawWiresForComponent(currentSnapshot.getSelectedComponent()->componentCode);
            }

            if (dec.isCursorPointInButton() && currentSnapshot.getSelectedComponent())
            {
                currentSnapshot.getSelectedComponent()->setWidth(currentSnapshot.getSelectedComponent()->getWidth() - 15);

                drawWiresForComponent(currentSnapshot.getSelectedComponent()->componentCode);
            }
        }
        else if (GetAsyncKeyState(VK_LBUTTON) && GetAsyncKeyState(VK_LCONTROL))
        {
            std ::cout << "move component" << std ::endl;
            ElectronicComponent **components = currentSnapshot.getComponents();
            for (int i = 0; i < currentSnapshot.getComponentsNumber(); i++)
            {
                setcurrentwindow(this->window_code);

                if (components[i]->isSelected())
                {
                    POINT cursorPoint;
                    GetCursorPos(&cursorPoint);

                    double x_point = cursorPoint.x;
                    double y_point = cursorPoint.y;

                    //keep the component in boundaries
                    if (x_point - components[i]->getWidth() / 2 < this->rl + BORDER_SPACE)
                    {
                        x_point = this->rl + BORDER_SPACE + components[i]->getWidth() / 2;
                    }
                    else if (x_point + components[i]->getWidth() / 2 > this->rr - BORDER_SPACE)
                    {
                        x_point = this->rr - BORDER_SPACE - components[i]->getWidth() / 2;
                    }

                    if (y_point - components[i]->getHeight() / 2 < this->rt + BORDER_SPACE)
                    {
                        y_point = this->rt + BORDER_SPACE + components[i]->getHeight() / 2;
                    }
                    else if (y_point + components[i]->getHeight() / 2 > this->rb - BORDER_SPACE)
                    {
                        y_point = this->rb - BORDER_SPACE - components[i]->getHeight() / 2;
                    }

                    components[i]->setPositionCenter(helper.makeVector_2D(x_point, y_point));
                }
            }
        }
        else if (GetAsyncKeyState(VK_RBUTTON))
        {
            std::cout << "trydelete\n";
            auto components = currentSnapshot.getComponents();
            for (int i = 0; i < currentSnapshot.getComponentsNumber(); i++)
            {

                if (components[i]->isCursorPointInButton())
                {
                    std::cout << "delete\n";
                    currentSnapshot.removeComponent(components[i]->getComponentCode());
                }
            }
        }
        delay(50);
    }

    closegraph(this->window_code);
}

void NewProjectMenu::Show()
{
    Helper helper;

    DWORD screenWidth = GetSystemMetrics(SM_CXSCREEN);
    DWORD screenHeight = GetSystemMetrics(SM_CYSCREEN);

    int wc = initwindow(screenWidth, screenHeight, "", -3, -3);
    this->window_code = wc;

    int windowWidth = getwindowwidth();
    int windowHeight = getwindowheight();
    double BUTTON_WIDTH = (windowWidth - 50) / 10;

    this->rl = BUTTON_WIDTH * 2, this->rt = BUTTON_HEIGHT * 3,
    this->rr = windowWidth - BUTTON_WIDTH * 2, this->rb = windowHeight - 3 * BUTTON_HEIGHT;

    rectangle(this->rl, this->rt, this->rr, this->rb);

    exit.setPositionUpLeft(helper.makeVector_2D(0, 0));
    exit.setWidth(75);
    exit.setHeight(BUTTON_HEIGHT);
    exit.setTitle("Exit");
    exit.Show();

    save.setPositionUpLeft(helper.makeVector_2D(75, 0));
    save.setWidth(BUTTON_WIDTH);
    save.setHeight(BUTTON_HEIGHT);
    save.setTitle("Save");
    save.Show();

    capacitors.setPositionUpLeft(helper.makeVector_2D(BUTTON_WIDTH + 75, 0));
    capacitors.setWidth(BUTTON_WIDTH);
    capacitors.setHeight(BUTTON_HEIGHT);
    capacitors.setTitle("Capacitors");
    capacitors.Show();

    diodes.setPositionUpLeft(helper.makeVector_2D(BUTTON_WIDTH * 2 + 75, 0));
    diodes.setWidth(BUTTON_WIDTH);
    diodes.setHeight(BUTTON_HEIGHT);
    diodes.setTitle("Diodes");
    diodes.Show();

    logicGates.setPositionUpLeft(helper.makeVector_2D(BUTTON_WIDTH * 3 + 75, 0));
    logicGates.setWidth(BUTTON_WIDTH);
    logicGates.setHeight(BUTTON_HEIGHT);
    logicGates.setTitle("Logic Gates");
    logicGates.Show();

    measurements.setPositionUpLeft(helper.makeVector_2D(BUTTON_WIDTH * 4 + 75, 0));
    measurements.setWidth(BUTTON_WIDTH);
    measurements.setHeight(BUTTON_HEIGHT);
    measurements.setTitle("Measurements");
    measurements.Show();

    resistors.setPositionUpLeft(helper.makeVector_2D(BUTTON_WIDTH * 5 + 75, 0));
    resistors.setWidth(BUTTON_WIDTH);
    resistors.setHeight(BUTTON_HEIGHT);
    resistors.setTitle("Resistors");
    resistors.Show();

    sources.setPositionUpLeft(helper.makeVector_2D(BUTTON_WIDTH * 6 + 75, 0));
    sources.setWidth(BUTTON_WIDTH);
    sources.setHeight(BUTTON_HEIGHT);
    sources.setTitle("Sources");
    sources.Show();

    switches.setPositionUpLeft(helper.makeVector_2D(BUTTON_WIDTH * 7 + 75, 0));
    switches.setWidth(BUTTON_WIDTH);
    switches.setHeight(BUTTON_HEIGHT);
    switches.setTitle("Switches");
    switches.Show();

    transistors.setPositionUpLeft(helper.makeVector_2D(BUTTON_WIDTH * 8 + 75, 0));
    transistors.setWidth(BUTTON_WIDTH);
    transistors.setHeight(BUTTON_HEIGHT);
    transistors.setTitle("Transistors");
    transistors.Show();

    other.setPositionUpLeft(helper.makeVector_2D(BUTTON_WIDTH * 9 + 75, 0));
    other.setWidth(BUTTON_WIDTH);
    other.setHeight(BUTTON_HEIGHT);
    other.setTitle("Other");
    other.Show();

    double r = 25;

    rotate_l.setPositionCenter(helper.makeVector_2D(this->rr + 3 * r, this->rb - 5 * r));
    rotate_l.setWidth(r);
    rotate_l.setHeight(r);
    rotate_l.setTitle("R<-");
    rotate_l.ShowCircleMode();

    rotate_r.setPositionCenter(helper.makeVector_2D(this->rr + 6 * r, this->rb - 5 * r));
    rotate_r.setWidth(r);
    rotate_r.setHeight(r);
    rotate_r.setTitle("R->");
    rotate_r.ShowCircleMode();

    flip_h.setPositionCenter(helper.makeVector_2D(this->rr + 3 * r, this->rb - r));
    flip_h.setWidth(r);
    flip_h.setHeight(r);
    flip_h.setTitle("F<|>");
    flip_h.ShowCircleMode();

    flip_v.setPositionCenter(helper.makeVector_2D(this->rr + 6 * r, this->rb - r));
    flip_v.setWidth(r);
    flip_v.setHeight(r);
    flip_v.setTitle("F<->");
    flip_v.ShowCircleMode();

    inc.setPositionCenter(helper.makeVector_2D(this->rl - 3 * r, this->rb - 5 * r));
    inc.setWidth(r);
    inc.setHeight(r);
    inc.setTitle("+");
    inc.ShowCircleMode();

    dec.setPositionCenter(helper.makeVector_2D(this->rl - 6 * r, this->rb - 5 * r));
    dec.setWidth(r);
    dec.setHeight(r);
    dec.setTitle("-");
    dec.ShowCircleMode();
}
