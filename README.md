**Template for JUCE Plugin (CMake)**  <br>

Simple CMake template for the JUCE framework.  <br>
It can be useed to create audio (DSP) plugins, synthesizers, and MIDI controllers.  <br>
Project can be built on Windows (VS) or macOS (Xcode).  <vr>
Plugins can be built in AU, VST3 and Standalone formats.  <br>

**How to use:**  <br>
1. Download JUCE from https://juce.com/get-juce/ (you can also go to github from this site and clone JUCE repository) to local folder on your computer  
2. Clone or download this repository to local folder on your computer  
3. Open CMakeLists.txt file and change parameters correctly to your needs and software (remember change the JUCE path in CMakeLists.txt)  
4. Open your code editor (for example Visual Studio on windows) -> choose "open local folder" (or similar) -> choose path to folder with CMakeLists.txt file and "Source" folder  
5. CMake will build the project itself  
6. Choose your target version (for example Standalone "YourPlugin name".exe) and run it  