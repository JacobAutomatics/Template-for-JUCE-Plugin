#pragma once


#include "PluginProcessor.h"

// ==============================================================================
//  Basic universal Editor template
// ==============================================================================
class YourPluginAudioProcessorEditor : public juce::AudioProcessorEditor
{
public:
    YourPluginAudioProcessorEditor (YourPluginAudioProcessor&);
    ~YourPluginAudioProcessorEditor() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    YourPluginAudioProcessor& processorRef;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (YourPluginAudioProcessorEditor)
};
