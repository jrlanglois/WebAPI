#include "MainWindow.h"

#include <ctime>

class WebAPIDemoApplication : public JUCEApplication
{
public:
    WebAPIDemoApplication() { }

    const String getApplicationVersion() override           { return ProjectInfo::versionString; }
    bool moreThanOneInstanceAllowed() override              { return false; }
    void shutdown() override                                { mainWindow = nullptr; }
    void anotherInstanceStarted (const String&) override    { }

    const String getApplicationName() override
    {
       #if JUCE_DEBUG
        return createWindowTitle (TRANS ("Debug Mode"));
       #else
        return ProjectInfo::projectName;
       #endif
    }

    void initialise(const String&) override
    {
        initSystemRandom();
        initOSDependantSystems();

        mainWindow = new MainWindow (getApplicationName());
    }

    void systemRequestedQuit() override
    {
        if (mainWindow != nullptr)
            mainWindow->closeButtonPressed();
        else
            quit();
    }
    
private:
    ScopedPointer<MainWindow> mainWindow;

    //==============================================================================
    void initSystemRandom()
    {
       #if JUCE_WINDOWS
        std::srand ((uint32) std::time (nullptr));
       #else
        std::srand ((uint32) std::time (0));
       #endif
    }

    void initOSDependantSystems()
    {
       #if JUCE_LINUX
        /** Linux is simply bugged for process naming, and JUCE is doing it right.
            This is a fix only necessary in this broken OS, AFAICT.
        */
        Thread::setCurrentThreadName (String (ProjectInfo::projectName));
       #endif
    }

    static String createWindowTitle (const String& title)
    {
        jassert (title.isNotEmpty());

        return String (ProjectInfo::projectName)
               + " (" + String (ProjectInfo::versionString) + ") --- "
               + "[" + title.toUpperCase() + "]";
    }

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (WebAPIDemoApplication)
};

START_JUCE_APPLICATION (WebAPIDemoApplication)
