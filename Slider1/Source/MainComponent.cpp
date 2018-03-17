/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"


//==============================================================================
MainContentComponent::MainContentComponent()
{
    addAndMakeVisible(frequencySlider);
    frequencySlider.addListener(this);
    addAndMakeVisible(frequencyLabel);
    frequencyLabel.setText("Frequency", NotificationType::dontSendNotification);
    frequencyLabel.attachToComponent(& frequencySlider, true);
    
    addAndMakeVisible(durationSlider);
    durationSlider.addListener(this);
    durationSlider.setTextValueSuffix(" s");
    addAndMakeVisible(durationLabel);
    durationLabel.setText("Duration", NotificationType::dontSendNotification);
    durationLabel.attachToComponent(&durationSlider, true);

    frequencySlider.setRange(50, 5000);
    frequencySlider.setTextValueSuffix(" Hz");
    frequencySlider.setValue(500.0);
    frequencySlider.setSkewFactorFromMidPoint(500.0);
    durationSlider.setRange(1.0 / frequencySlider.getMaximum(), 1.0 / frequencySlider.getMinimum());
    durationSlider.setSkewFactorFromMidPoint(1.0 / 500);
    setSize (600, 400);
}

MainContentComponent::~MainContentComponent()
{
}

void MainContentComponent::paint (Graphics& g)
{
    
}

void MainContentComponent::resized()
{
    const int border = 120;
    frequencySlider.setBounds(border, 20, getWidth() - border, 20);
    durationSlider.setBounds(border, 50, getWidth() - border, 50);
}
