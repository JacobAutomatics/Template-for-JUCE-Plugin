#include "PluginProcessor.h"
#include "PluginEditor.h"

// ==============================================================================
YourPluginAudioProcessor::YourPluginAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                       .withInput  ("Input",  juce::AudioChannelSet::stereo(), true)
                       .withOutput ("Output", juce::AudioChannelSet::stereo(), true))
#endif
{
}

YourPluginAudioProcessor::~YourPluginAudioProcessor() {}

// ==============================================================================
void YourPluginAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Called before playback. Prepare DSP here if needed.
    juce::ignoreUnused(sampleRate, samplesPerBlock);
}

void YourPluginAudioProcessor::releaseResources()
{
    // Called when playback stops. Clean up here.
}

bool YourPluginAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
#if JucePlugin_IsMidiEffect
    juce::ignoreUnused (layouts);
    return true;
#else
    // Only stereo in/out
    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
        return false;

    return true;
#endif
}

void YourPluginAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer,
                                             juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;

    // Clear unused channels (safety)
    for (int ch = getTotalNumInputChannels(); ch < getTotalNumOutputChannels(); ++ch)
        buffer.clear (ch, 0, buffer.getNumSamples());

    // Minimal template = do nothing (passes audio through unchanged)
}

// ==============================================================================
juce::AudioProcessorEditor* YourPluginAudioProcessor::createEditor()
{
    return new YourPluginAudioProcessorEditor (*this);
}

// ==============================================================================
void YourPluginAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    // No state in the basic template. You can add your parameters later.
}

void YourPluginAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // No state in the basic template.
}

juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new YourPluginAudioProcessor();
}