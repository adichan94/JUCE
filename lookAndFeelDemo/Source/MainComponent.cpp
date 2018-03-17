/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"


//==============================================================================
MainContentComponent::MainContentComponent()
{
    setSize (600, 400);
    addAndMakeVisible(dial1);
    addAndMakeVisible(dial2);
    
    dial1.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    dial2.setSliderStyle(Slider::SliderStyle::Rotary);
    
    dial1.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    dial2.setTextBoxStyle(Slider::TextBoxBelow, true, 100, 25);
    
    getLookAndFeel().setColour(Slider::thumbColourId, Colours::purple);
    getLookAndFeel().setColour(Slider::rotarySliderOutlineColourId, Colours::cornflowerblue);
    
    otherLookAndFeel.setColour(Slider::thumbColourId, Colours::chocolate);
    otherLookAndFeel.setColour(Slider::rotarySliderOutlineColourId, Colours::azure);
    
    dial1.setLookAndFeel(&otherLookAndFeel);
}

MainContentComponent::~MainContentComponent()
{
}

void MainContentComponent::paint (Graphics& g)
{
    g.fillAll(Colours::white);
}

void MainContentComponent::resized()
{
    const int border = 20;
    const int dialWidth = getWidth() / 2 - border;
    const int dialHeight = getHeight() - border - 100;
    
    dial1.setBounds(border, border, dialWidth, dialHeight);
    dial2.setBounds(getWidth() / 2 , border, dialWidth, dialHeight);
}
