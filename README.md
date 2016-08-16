#CPlusPlusCLI-Tutorial

This tutorial has been created in an attempt to help guide someone through accessing and using managed .Net libraries from native unmanaged C/C++ code. It is especially helpful for use cases in which legacy C/C++ code might need to access and take advantage of a library written in C#.

C++/CLI is a .Net tool that allows native libraries to communicate with C#, and vice versa. Given a little time and experience it allows you to create cleaner and better solutions in code for binding your native and .Net libraries together.

#Definitions

[C++/CLI](https://en.wikipedia.org/wiki/C%2B%2B/CLI "C++/CLI") - "a language specification created by Microsoft and intended to supersede Managed Extensions for C++" <br/>
C/C++ - Either C or C++. Just an abbreviation for either/or.

#Design Considerations

1. Code written in C++/CLI is used for wrapping the logic of a .Net library or native C/C++ library.
2. All logical operations should stay in either your C# library, or native C/C++ library.
3. Keep the code in C++/CLI as simple as possible. It is only a bridge between the unmanaged and managed worlds.
