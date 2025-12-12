cmake_minimum_required(VERSION 3.22)

project(YourPlugin)

set(CMAKE_CXX_STANDARD 17)

# ------------------------------------------------------------
#  JUCE PATH — CHANGE THIS TO JUCE LOCATION ON YOUR COMPUTER
# ------------------------------------------------------------
set(JUCE_DIR "A:/JUCE")   # <- change "here"
add_subdirectory(${JUCE_DIR} ${CMAKE_BINARY_DIR}/JUCE)

# ------------------------------------------------------------
#  SOURCES
# ------------------------------------------------------------
set(SOURCES
    Source/PluginEditor.cpp
    Source/PluginEditor.h
    Source/PluginProcessor.cpp
    Source/PluginProcessor.h
)

# ------------------------------------------------------------
#  PREFERENCES - up to you
# ------------------------------------------------------------
juce_add_plugin(${PROJECT_NAME}
    PRODUCT_NAME "YourPlugin"           # <- main name (Standalone, .AU or .vst3 name, also visible in DAW)
    PLUGIN_NAME "Standalone name of YourPlugin"      # <- visible on the top of standalone project window
# plugin builds path: plugin folder/out/build/Debug/{PLUGIN_NAME}_artefacts/Debug/...
    VERSION "1.0.0"              # <- your plugin version
    COMPANY_NAME "YourCompany"   # <- visible in .vst3 metadata or in DAW 
    NEEDS_MIDI_INPUT FALSE       # <- change to TRUE if you need MIDI input
    NEEDS_MIDI_OUTPUT FALSE      # <- change to TRUE if you need MIDI output
    IS_SYNTH FALSE               # <- change to TRUE if you build synthesizer
    IS_MIDI_EFFECT FALSE         # <- change to TRUE if you build MIDI
    EDITOR_WANTS_KEYBOARD_FOCUS FALSE   # <- change to TRUE if your plugin have to get inputs from keyboard (for example shortcuts)
    JUCE_VST3_CAN_REPLACE_VST2 FALSE     # <- have to be always FALSE
    COPY_PLUGIN_AFTER_BUILD TRUE
    PLUGIN_COPY_DESTINATION "${CMAKE_BINARY_DIR}/Pluginy"
    PLUGIN_MANUFACTURER_CODE Alvs
    PLUGIN_CODE Plg1
    FORMATS VST3 Standalone
)

# ------------------------------------------------------------
#  BUILD OPTIONS
# ------------------------------------------------------------
target_sources(${PROJECT_NAME} PRIVATE ${SOURCES})

# ------------------------------------------------------------
#  LINKING AND SETTINGS
# ------------------------------------------------------------
target_compile_features(YourPlugin PRIVATE cxx_std_17)

# These are some toggleable options from the JUCE CMake API
target_compile_definitions(${PROJECT_NAME}
    PUBLIC
        JUCE_WEB_BROWSER=0
        JUCE_USE_CURL=0
        JUCE_VST3_CAN_REPLACE_VST2=0  # <- have to be always 0
)


target_link_libraries(${PROJECT_NAME}
    PUBLIC
    juce::juce_analytics
    juce::juce_audio_utils
    juce::juce_audio_processors
    juce::juce_core
    juce::juce_audio_devices
    juce::juce_audio_basics
    juce::juce_gui_extra
    juce::juce_gui_basics
    juce::juce_dsp
)
