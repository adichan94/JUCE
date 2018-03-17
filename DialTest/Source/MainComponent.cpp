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
    dial1.setSliderStyle(Slider::SliderStyle::Rotary);
    dial1.setTextBoxStyle(Slider::TextEntryBoxPosition::TextBoxBelow, false, 50, 20);
    
    addAndMakeVisible(dial2);
    dial2.setSliderStyle(Slider::SliderStyle::Rotary);
    dial2.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    
    addAndMakeVisible(slider1);
    dial2.setSliderStyle(Slider::SliderStyle::LinearHorizontal);
    dial2.setTextBoxStyle(Slider::TextEntryBoxPosition::TextBoxBelow,false, 50, 20);
}

MainContentComponent::~MainContentComponent()
{
}

void MainContentComponent::paint (Graphics& g)
{
    g.fillAll(Colours::aquamarine);
}

void MainContentComponent::resized()
{
    Rectangle<int> area = getLocalBounds();
    Rectangle<int> dialArea = area.removeFromBottom(area.getHeight() / 2);
    
    dial2.setBounds(dialArea.removeFromLeft(area.getWidth() / 2));
    dial1.setBounds(dialArea.removeFromRight(area.getWidth() / 2));
    slider1.setBounds(area);
}
