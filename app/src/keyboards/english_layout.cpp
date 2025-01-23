//
//  english_layout.cpp
//  Moonlight
//
//  Created by Даниил Виноградов on 22.06.2021.
//

#include "keyboard_view.hpp"

using namespace brls;

KeyboardKeys ENG_BUTTONS[] = {
    VK_KEY_Q, VK_KEY_W, VK_KEY_E, VK_KEY_R, VK_KEY_T, VK_KEY_Y, VK_KEY_U,
    VK_KEY_I, VK_KEY_O, VK_KEY_P, VK_KEY_A, VK_KEY_S, VK_KEY_D, VK_KEY_F,
    VK_KEY_G, VK_KEY_H, VK_KEY_J, VK_KEY_K, VK_KEY_L, VK_KEY_Z, VK_KEY_X,
    VK_KEY_C, VK_KEY_V, VK_KEY_B, VK_KEY_N, VK_KEY_M, VK_KP_7,   VK_KP_8,
    VK_KP_9,  VK_KP_4,  VK_KP_5,  VK_KP_6,  VK_KP_1,  VK_KP_2,   VK_KP_3,
};

void KeyboardView::createEnglishLayout() {
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
    
    for (int i = 0; i < 10; i++)
    {
        ButtonView* button = new ButtonView(this);
        button->setKey(ENG_BUTTONS[i]);
        button->setMargins(4, 4, 4, 4);
        button->setWidth(80);
        firstRow->addView(button);
    }

    Box* secondRow = new Box(Axis::ROW);
    leftCol->addView(secondRow);
    
    for (int i = 10; i < 19; i++)
    {
        ButtonView* button = new ButtonView(this);
        button->setKey(ENG_BUTTONS[i]);
        button->setMargins(4, 4, 4, 4);
        button->setWidth(80);
        secondRow->addView(button);
    }

    Box* thirdRow = new Box(Axis::ROW);
    leftCol->addView(thirdRow);
    
    ButtonView* lshiftButton = new ButtonView(this);
    lshiftButton->setKey(VK_RSHIFT);
    lshiftButton->triggerType = true;
    lshiftButton->charLabel->setFontSize(21);
    lshiftButton->setMargins(4, 24, 4, 4);
    lshiftButton->setWidth(100);
    lshiftButton->event = [] { KeyboardView::shiftUpdated.fire(); };
    thirdRow->addView(lshiftButton);

    for (int i = 19; i < 26; i++) {
        ButtonView* button = new ButtonView(this);
        button->setKey(ENG_BUTTONS[i]);
        button->setMargins(4, 4, 4, 4);
        button->setWidth(80);
        thirdRow->addView(button);
    }

    ButtonView* deleteButton = new ButtonView(this);
    deleteButton->setKey(VK_BACK);
    deleteButton->charLabel->setFontSize(21);
    deleteButton->setMargins(4, 4, 4, 24);
    deleteButton->setWidth(100);
    thirdRow->addView(deleteButton);

    Box* fourthRow = new Box(Axis::ROW);
    leftCol->addView(fourthRow);
    
    ButtonView* altButton = new ButtonView(this);
    altButton->charLabel->setText("123");
    altButton->charLabel->setFontSize(21);
    altButton->setMargins(4, 4, 4, 4);
    altButton->setWidth(120);
    altButton->event = [this] {
        sync([this] {
            createNumpadLayout();
            if (needFocus)
                Application::giveFocus(this);
        });
    };
    fourthRow->addView(altButton);

    ButtonView* winButton = new ButtonView(this);
    winButton->setKey(VK_LWIN);
    winButton->charLabel->setFontSize(21);
    winButton->setMargins(4, 4, 4, 4);
    winButton->setWidth(120);
    fourthRow->addView(winButton);

    ButtonView* spaceButton = new ButtonView(this);
    spaceButton->setKey(VK_SPACE);
    spaceButton->charLabel->setFontSize(21);
    spaceButton->setMargins(4, 4, 4, 4);
    spaceButton->setWidth(290);
    fourthRow->addView(spaceButton);

    ButtonView* ctrlButton = new ButtonView(this);
    ctrlButton->setKey(VK_RCONTROL);
    ctrlButton->triggerType = true;
    ctrlButton->charLabel->setFontSize(21);
    ctrlButton->setMargins(4, 4, 4, 4);
    ctrlButton->setWidth(120);
    fourthRow->addView(ctrlButton);

    ButtonView* returnButton = new ButtonView(this);
    returnButton->setKey(VK_RETURN);
    returnButton->charLabel->setFontSize(21);
    returnButton->setMargins(4, 4, 4, 4);
    returnButton->setWidth(120);
    fourthRow->addView(returnButton);

    for (int i = 26; i < 35; i += 3)
    {
        Box* row = new Box(Axis::ROW);
        rightCol->addView(row);
        for (int j = i; j < i + 3; j++)
        {
            ButtonView* button = new ButtonView(this);
            button->setKey(ENG_BUTTONS[j]);
            button->setMargins(4, 4, 4, 4);
            button->setWidth(80);
            row->addView(button);
        }
    }

    Box* rightFourthRow = new Box(Axis::ROW);
    rightCol->addView(rightFourthRow);

    ButtonView* dashButton = new ButtonView(this);
    dashButton->setKey(VK_OEM_8);
    dashButton->setMargins(4, 4, 4, 4);
    dashButton->setWidth(80);
    rightFourthRow->addView(dashButton);

    ButtonView* button0 = new ButtonView(this);
    button0->setKey(VK_KP_0);
    button0->setMargins(4, 4, 4, 4);
    button0->setWidth(80);
    rightFourthRow->addView(button0);

    ButtonView* equalsButton = new ButtonView(this);
    equalsButton->setKey(VK_OEM_9);
    equalsButton->setMargins(4, 4, 4, 4);
    equalsButton->setWidth(80);
    rightFourthRow->addView(equalsButton);
    
}
