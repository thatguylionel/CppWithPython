# CppWithPython
C++ project that communicates with a Python Script

The idea was to take existing examples, such as this wonderful post by Jonathan Kauffman back on 8 December 2012, https://www.coveros.com/calling-python-code-from-c/, and run it within a C++ application, making small modifications to work in conjunction with Python 3. 

To be honest, not a lot of changes were made, however a few key configurations had to be made to accommodate the Version 3 format of python, as well as copying a couple of DLL files for Visual Studio purposes:

# My Personal Setup for this project
- Python Installation: python-3.7.4 with debug install files included (this option is available when installing Python)
- C++ 11
- Visual Studio 2015


# Configs
I compiled this project as a x86 build

Within Visual Studios Properties Setup, I pointed the Include Directory and Linker "Link Library Dependencies" to my installed path for python, which you need to configure should you have installed this to a different directory: 

C/C++-->General-->Additional Include Libraries (Select All Configurations)
$(MSBuildProgramFiles32)\Python37-32\include\internal;$(MSBuildProgramFiles32)\Python37-32\include;%(AdditionalIncludeDirectories)

Linker-->General-->Link Library Dependencies (Select All Configurations)
$(MSBuildProgramFiles32)\Python37-32\libs;%(AdditionalLibraryDirectories)

Linker-->Input-->Additional Dependenceis (Select Debug)
python37_d.lib;%(AdditionalDependencies)

Linker-->Input-->Additional Dependenceis (Select Release)
python37.lib;%(AdditionalDependencies)

Build Events --> Post-Build Event (Select Debug)
xcopy /y /d "$(ProjectDir)Sample.py" "$(OutDir)"
xcopy /y /d "$(MSBuildProgramFiles32)\Python37-32\python37_d.dll" "$(OutDir)"

Build Events --> Post-Build Event (Select Release)
xcopy /y /d "$(ProjectDir)Sample.py" "$(OutDir)"
xcopy /y /d "$(MSBuildProgramFiles32)\Python37-32\python37.dll" "$(OutDir)"
