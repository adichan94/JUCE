/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"


//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
   your controls and content.
*/

class OtherLookAndFeel : public LookAndFeel_V4
{
public:
    void drawRotarySlider(Graphics &g, int x, int y, int width, int height, float sliderPos, float rotaryStartAngle, float rotaryEndAngle, Slider &slider) override
    {
        float diameter = jmin(width, height);
        float radius = diameter / 2;
        float centreX = x + width / 2;
        float centreY = y + width / 2;
        float rx = centreX - radius;
        float ry = centreY - radius;
        float angle = rotaryStartAngle + sliderPos * (rotaryEndAngle - rotaryStartAngle);
                                                    
        Rectangle<float> dialArea(rx,ry,diameter,diameter);
        g.setColour(Colours::red);
        g.fillEllipse(dialArea);
        g.setColour(Colours::black);
        Path dialTick;
        dialTick.addRectangle(0, -radius, 5.0f, radius);
        g.fillPath(dialTick, AffineTransform::rotation(angle).translated(centreX, centreY));
    }
};


class MainContentComponent   : public Component
{
public:
    //==============================================================================
    MainContentComponent();
    ~MainContentComponent();

    void paint (Graphics&) override;
    void resized() override;

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
    Slider dial1;
    Slider dial2;
    
    OtherLookAndFeel otherLookAndFeel;
};
