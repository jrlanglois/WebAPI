#include "MainWindow.h"

MainWindow::MainWindow (const String& applicationName) :
    DocumentWindow (applicationName, Colours::black, DocumentWindow::allButtons),
    mainComponent (new MainComponent())
{
    //NB: On failure, JUCE will backtrack to an earlier version of OpenGL.
    context.setOpenGLVersionRequired (OpenGLContext::openGL3_2);
    context.setMultisamplingEnabled (true);
    context.attachTo (*mainComponent);

    setResizeLimits (1920 / 2, 1080 / 2, 0x7fffffff, 0x7fffffff); //Minimum size is a quarter of an HD area, and max size is max 'int'
    setResizable (true, false);
    setContentOwned (mainComponent, true);
    setUsingNativeTitleBar (true);
    setVisible (true);

    const Rectangle<float> floatArea = Desktop::getInstance().getDisplays().getMainDisplay().totalArea.toFloat() * 0.7f;
    const Rectangle<int> area = floatArea.getSmallestIntegerContainer();
    centreWithSize (area.getWidth(), area.getHeight());
}

void MainWindow::closeButtonPressed()
{
    JUCEApplication::getInstance()->quit();
}
