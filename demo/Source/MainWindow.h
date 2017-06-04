#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include "MainComponent.h"

class MainWindow : public DocumentWindow
{
public:
    MainWindow (const String& applicationName);

    void closeButtonPressed() override;

private:
    MainComponent* mainComponent;
    OpenGLContext context;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainWindow)
};

#endif //MAIN_WINDOW_H
