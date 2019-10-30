# cpp_vs_payload_template
 Visual Studio (C++) Solution Template for Payloads

 This is a Visual Studio (C++) Solution Template intended to save some time when developing custom payloads/shellcode. This solution creates 3 projects:

 1. A static library project (Core)

    All of your payload code goes in this project in the runme() function. Add as many headers/cpp files/references as you like, but runme() will be your entry point.

 2. A dynamic library project (DLL)

    This project simply wraps the functionality of the static library project into a DLL skeleton. Once built, this project can be run directly using rundll32 or it can be converted to PIC shellcode using something like ConvertTo-Shellcode.ps1 from Nick Landers avaialble here: https://github.com/monoxgas/sRDI/tree/master/PowerShell

 3. An application project (EXE)
 
    This project simply wraps the static library in an executable. This project can be used to debug your payload from the Visual Studio debugger and allows you to set breakpoints in the static library code.

## Use Cases

 I created this project for two reasons. First, it can be used to generate both an .exe and .dll payload simultaneously, saving time. Second, I grew tired of developing payloads as DLLs only to realize there would be a bug in there somewhere and dealing with the pain in the ass that is debugging a DLL file without being able to step through code line by line in VS. Rather than creating a new project w/ the buggy code as an application instead of a DLL to debug it directly from the IDE, now I have both at once.

## Instructions

 1. Copy the contents of this repository to C:\Users\<YOURUSERNAME>\Documents\Visual Studio 2017\Templates\ProjectTemplates\Visual C++ Project (adjust for differences in your environment/version)

 2. Open Visual Studio

 3. Click on File/New/Project/VisualC++ and select "CPP Core/EXE/DLL Solution Template"

 4. Name the solution, click OK

 5. Select the executable project (solutionnameEXE), right-click and select "Set as startup project"

 6. Select the solution at the top, right-click and select "Properties"

 7. Go to Common Properties/Project Dependencies. Select the DLL project and set the Core project as a dependency. Repeat this for the EXE project. Hit Apply/OK.

 8. Build your code from the runme() function in the Core project as the entry point. Select your arch/build-type and build the solution.

## Inspiration

 The inspiration for this template came from the way I saw Silent Break Securuity lay out one of their projects. I wanted a relatively painless way to replicate this layout without having to do all the manual work for each payload I write.
