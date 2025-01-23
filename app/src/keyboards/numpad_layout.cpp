//
//  numpad_layout.cpp
//  Moonlight
//
//  Created by Даниил Виноградов on 22.06.2021.
//

#include "keyboard_view.hpp"

using namespace brls;

KeyboardKeys NUM_BUTTONS[] = {
    VK_ESCAPE, VK_F1,         VK_F2,        VK_F3,       VK_F4,    VK_F5,
    VK_F6,     VK_F7,         VK_F8,        VK_F9,       VK_F10,   VK_F11,
    VK_F12,    VK_OEM_3,      VK_KEY_1,     VK_KEY_2,    VK_KEY_3, VK_KEY_4,
    VK_KEY_5,  VK_KEY_6,      VK_KEY_7,     VK_KEY_8,    VK_KEY_9, VK_KEY_0,
    VK_OEM_5,  VK_OEM_PERIOD, VK_OEM_COMMA, VK_OEM_1,    VK_OEM_2, VK_OEM_7,
    VK_OEM_4,  VK_OEM_6,      VK_OEM_MINUS, VK_OEM_PLUS, VK_KP_7,  VK_KP_8,
    VK_KP_9,   VK_KP_4,       VK_KP_5,      VK_KP_6,     VK_KP_1,  VK_KP_2,
    VK_KP_3,
};

void KeyboardView::createNumpadLayout() {
    clearViews();
    keyboardLangLock = 0;

    Box* container = new Box(Axis::ROW);
    addView(container);

    Box* leftCol = new Box(Axis::COLUMN);
    Box* rightCol = new Box(Axis::COLUMN);
    leftCol->setAlignItems(AlignItems::CENTER);
    leftCol->setJustifyContent(JustifyContent::CENTER);
    leftCol->setMargins(0, 10, 0, 0);
    rightCol->setAlignItems(AlignItems::CENTER);
    rightCol->setJustifyContent(JustifyContent::CENTER);
    container->addView(leftCol);
    container->addView(rightCol);
    
    Box* firstRow = new Box(Axis::ROW);
    leftCol->addView(firstRow);
    
    for (int i = 0; i < 13; i++)
    {
        ButtonView* button = new ButtonView(this);
        button->setKey(NUM_BUTTONS[i]);
        button->setMargins(4, 4, 4, 4);
        button->setWidth(67.3f);
        firstRow->addView(button);
    }

    Box* secondRow = new Box(Axis::ROW);
    leftCol->addView(secondRow);
    
    for (int i = 13; i < 25; i++)
    {
        ButtonView* button = new ButtonView(this);
        button->setKey(NUM_BUTTONS[i]);
        button->setMargins(4, 4, 4, 4);
        button->setWidth(73.7f);
        secondRow->addView(button);
    }

    Box* thirdRow = new Box(Axis::ROW);
    leftCol->addView(thirdRow);
    
    ButtonView* lshiftButton = new ButtonView(this);
    lshiftButton->setKey(VK_RSHIFT);
    lshiftButton->triggerType = true;
    lshiftButton->charLabel->setFontSize(21);
    lshiftButton->setMargins(4, 24, 4, 4);
    lshiftButton->setWidth(120);
    lshiftButton->event = [] { KeyboardView::shiftUpdated.fire(); };
    thirdRow->addView(lshiftButton);

    for (int i = 25; i < 34; i++) {
        ButtonView* button = new ButtonView(this);
        button->setKey(NUM_BUTTONS[i]);
        button->setMargins(4, 4, 4, 4);
        button->setWidth(68.25f);
        thirdRow->addView(button);
    }

    ButtonView* deleteButton = new ButtonView(this);
    deleteButton->setKey(VK_DELETE);
    deleteButton->charLabel->setFontSize(21);
    deleteButton->setMargins(4, 4, 4, 24);
    deleteButton->setWidth(120);
    thirdRow->addView(deleteButton);

    Box* fourthRow = new Box(Axis::ROW);
    leftCol->addView(fourthRow);
    
    ButtonView* altButton = new ButtonView(this);
    altButton->charLabel->setText("ABC");
    altButton->charLabel->setFontSize(21);
    altButton->setMargins(4, 4, 4, 4);
    altButton->setWidth(120);
    altButton->event = [this] {
        sync([this] {
            createEnglishLayout();
            if (needFocus)
                Application::giveFocus(this);
        });
    };
    fourthRow->addView(altButton);

    ButtonView* winButton = new ButtonView(this);
    winButton->setKey(VK_TAB);
    winButton->charLabel->setFontSize(21);
    winButton->setMargins(4, 4, 4, 4);
    winButton->setWidth(120);
    fourthRow->addView(winButton);

    ButtonView* spaceButton = new ButtonView(this);
    spaceButton->setKey(VK_SPACE);
    spaceButton->charLabel->setFontSize(21);
    spaceButton->setMargins(4, 4, 4, 4);
    spaceButton->setWidth(464);
    fourthRow->addView(spaceButton);

    ButtonView* ctrlButton = new ButtonView(this);
    ctrlButton->setKey(VK_RCONTROL);
    ctrlButton->triggerType = true;
    ctrlButton->charLabel->setFontSize(21);
    ctrlButton->setMargins(4, 4, 4, 4);
    ctrlButton->setWidth(120);
    fourthRow->addView(ctrlButton);

    ButtonView* returnButton = new ButtonView(this);
    returnButton->setKey(VK_RMENU);
    returnButton->triggerType = true;
    returnButton->charLabel->setFontSize(21);
    returnButton->setMargins(4, 4, 4, 4);
    returnButton->setWidth(120);
    fourthRow->addView(returnButton);

    for (int i = 34; i < 42; i += 3)
    {
        Box* row = new Box(Axis::ROW);
        rightCol->addView(row);
        for (int j = i; j < i + 3; j++)
        {
            ButtonView* button = new ButtonView(this);
            button->setKey(NUM_BUTTONS[j]);
            button->setMargins(4, 4, 4, 4);
            button->setWidth(73.7f);
            row->addView(button);
        }
    }

    Box* rightFourthRow = new Box(Axis::ROW);
    rightCol->addView(rightFourthRow);

    ButtonView* dashButton = new ButtonView(this);
    dashButton->setKey(VK_OEM_8);
    dashButton->setMargins(4, 4, 4, 4);
    dashButton->setWidth(73.7f);
    rightFourthRow->addView(dashButton);

    ButtonView* button0 = new ButtonView(this);
    button0->setKey(VK_KP_0);
    button0->setMargins(4, 4, 4, 4);
    button0->setWidth(73.7f);
    rightFourthRow->addView(button0);

    ButtonView* equalsButton = new ButtonView(this);
    equalsButton->setKey(VK_OEM_9);
    equalsButton->setMargins(4, 4, 4, 4);
    equalsButton->setWidth(73.7f);
    rightFourthRow->addView(equalsButton);
}
