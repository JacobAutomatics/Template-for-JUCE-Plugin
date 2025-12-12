#include "PluginEditor.h"
#include "PluginProcessor.h"

// ==============================================================================
YourPluginAudioProcessorEditor::YourPluginAudioProcessorEditor (YourPluginAudioProcessor& p)
    : AudioProcessorEditor (&p), processorRef (p)
{
    // Set default window size
    setSize (460, 340);
}

YourPluginAudioProcessorEditor::~YourPluginAudioProcessorEditor() {}

// ==============================================================================
void YourPluginAudioProcessorEditor::paint (juce::Graphics& g)
{

    g.fillAll (juce::Colours::green);  // Set background colour.


    auto allArea = getLocalBounds(); // All area.
    auto upTextLine = allArea.removeFromTop(allArea.getHeight() / 3); // Take upper part of area.
    auto midTextLine = allArea.removeFromTop(allArea.getHeight() / 2); // Take middle part of area.
    auto downTextLine = allArea; // Take the remain of area.

    g.setColour(juce::Colours::white); // Set font colour.
    g.setFont(21.0f); // Set type and size.

    g.drawFittedText ("That is your template!", upTextLine, juce::Justification::centred, 1);
    g.drawFittedText("Link for JUCE modules / classes / toutorials:", midTextLine, juce::Justification::centred, 1);
    g.drawFittedText("https://docs.juce.com/master/index.html", downTextLine, juce::Justification::centred, 1);
    


}

void YourPluginAudioProcessorEditor::resized()
{
    // Layout components here (none for now).
}
