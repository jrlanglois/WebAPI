#include "MainComponent.h"

//https://dev.twitter.com/rest/public
//
class TwitterComponent : public Component
{
public:
    TwitterComponent()
    {
    }

    enum BrandColours
    {
        twitterBlue = 0xff1da1f2
    };

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TwitterComponent)
};

MainComponent::MainComponent() :
    tc (TabbedButtonBar::TabsAtTop)
{
    setSize (1920, 1080);

    tc.addTab (TRANS ("Twitter"), Colour ((uint32) TwitterComponent::twitterBlue), new TwitterComponent(), true);
    addAndMakeVisible (tc);
}

MainComponent::~MainComponent()
{
}

void MainComponent::resized()
{
    tc.setBounds (getLocalBounds());
}