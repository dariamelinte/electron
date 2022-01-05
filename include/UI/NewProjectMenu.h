#ifndef NEWPROJECTMENU_H
#define NEWPROJECTMENU_H

#include <graphics.h>
#include <winbgim.h>
#include <windows.h>

#include "Electronic Components/Electronics.h"
#include "UI/UI.h"
#include "Data Structures/ColectionOfSnapshots.h"
#include "Data Structures/Snapshot.h"

#include "UI.h"
#include "Helper.h"
#include "Enums.h"

class NewProjectMenu
{
    protected:
        Button save, capacitors, diodes, logicGates, measurements, resistors, sources, switches, transistors, other, exit;
    public:
        NewProjectMenu();

        ColectionOfSnapshots completeSnapshots;
        Snapshot currentSnapshot;

        NameFile nameFileMenu;

        int window_code;
        std::string filepath;

        void Show();
        void WatchClick();
};

#endif // NEWPROJECTMENU_H
