/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainContentComponent   : public AudioAppComponent,
                                public Slider::Listener
{
public:
    //==============================================================================
    
    void sliderValueChanged(Slider* slider)
    {
            if(slider == &frequencySlider)
            {
                frequency = frequencySlider.getValue();
            }
        
            else if(slider == &ampSlider)
            {
                amplitude = ampSlider.getValue();
            }
    }
    
    void updateFrequency()
    {
        increment = frequency * waveTableSize / currentSampleRate;
        phase = fmod((phase + increment), waveTableSize);
    }
    
    MainContentComponent()
    {
        setSize (800, 600);

        // specify the number of input and output channels that we want to open
        setAudioChannels (2, 2);
        
        frequencySlider.addListener(this);
        frequencySlider.setSliderStyle(Slider::SliderStyle::LinearHorizontal);
        frequencySlider.setTextValueSuffix("Hz");
        frequencySlider.setRange(10.0, 5000.0);
        frequencySlider.setValue(200.0);
        frequencyLabel.setText("Frequency", dontSendNotification);
        frequencyLabel.attachToComponent(&frequencySlider, true);
        addAndMakeVisible(frequencySlider);
        
        
        ampSlider.addListener(this);
        ampSlider.setSliderStyle(Slider::SliderStyle::LinearHorizontal);
        ampSlider.setRange(0, 1.0);
        ampSlider.setValue(0.0);
        amplitudeLabel.setText("Amplitude",dontSendNotification);
        amplitudeLabel.attachToComponent(&ampSlider, true);
        addAndMakeVisible(ampSlider);
    }

    ~MainContentComponent()
    {
        shutdownAudio();
    }

    //==============================================================================
    void prepareToPlay (int samplesPerBlockExpected, double sampleRate) override
    {
        // This function will be called when the audio device is started, or when
        // its settings (i.e. sample rate, block size, etc) are changed.

        // You can use this function to initialise any resources you might need,
        // but be careful - it will be called on the audio thread, not the GUI thread.

        // For more details, see the help for AudioProcessor::prepareToPlay()
        
        frequency = frequencySlider.getValue();
        phase = 0;
        waveTableSize = 1024;
        amplitude = ampSlider.getValue();
        increment = frequency * waveTableSize / sampleRate;
        
        currentSampleRate = sampleRate;
        
        for(int i=0; i < waveTableSize; i++)
        {
            waveTable.insert(i, sin(2 * double_Pi * i / waveTableSize));
        }
    }

    void getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill) override
    {
        // Your audio-processing code goes here!

        // For more details, see the help for AudioProcessor::getNextAudioBlock()

        // Right now we are not producing any data, in which case we need to clear the buffer
        // (to prevent the output of random noise)
        
        float* const leftSpeaker = bufferToFill.buffer->getWritePointer(0, bufferToFill.startSample);
        
        float* const rightSpeaker = bufferToFill.buffer->getWritePointer(1, bufferToFill.startSample);
        
        for(int sample = 0; sample < bufferToFill.numSamples; ++sample)
        {
            leftSpeaker[sample] = waveTable[(int)phase] * amplitude;
            rightSpeaker[sample] = waveTable[(int)phase] * amplitude;
            
            updateFrequency();
        }
        
    }

    void releaseResources() override
    {
        // This will be called when the audio device stops, or when it is being
        // restarted due to a setting change.

        // For more details, see the help for AudioProcessor::releaseResources()
    }

    //==============================================================================
    void paint (Graphics& g) override
    {
        // (Our component is opaque, so we must completely fill the background with a solid colour)
        g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

        // You can add your drawing code here!
    }

    void resized() override
    {
        // This is called when the MainContentComponent is resized.
        // If you add any child components, this is where you should
        // update their positions.
        
        const int labelSpace = 100;
        
        frequencySlider.setBounds(labelSpace, 20, getWidth()-100, 20);
        ampSlider.setBounds(labelSpace, 50, getWidth() - 100, 50);
    }


private:
    //==============================================================================

    // Your private member variables go here...
    
    Slider frequencySlider;
    Slider ampSlider;
    
    Label frequencyLabel, amplitudeLabel;
    
    Array<float> waveTable;
    double waveTableSize;
    double frequency;
    double phase;
    double increment;
    double amplitude;
    double currentSampleRate;
    
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};


// (This function is called by the app startup code to create our main component)
Component* createMainContentComponent()     { return new MainContentComponent(); }
