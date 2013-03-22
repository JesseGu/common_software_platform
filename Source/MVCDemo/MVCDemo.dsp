# Microsoft Developer Studio Project File - Name="MVCDemo" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=MVCDemo - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "MVCDemo.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "MVCDemo.mak" CFG="MVCDemo - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "MVCDemo - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "MVCDemo - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "MVCDemo - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\Bin\MVCDemo\Release"
# PROP Intermediate_Dir "..\..\Intermediate\MVCDemo\Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /I "..\Public" /I "..\AWS_Mobile" /I "..\AWS_Core" /I "..\AWS_BaseCtrl" /I "..\SPX" /I "..\OS_Base" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /D "_AFXDLL" /YX /FD /c
# ADD BASE RSC /l 0x804 /d "NDEBUG"
# ADD RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ELSEIF  "$(CFG)" == "MVCDemo - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\Bin\MVCDemo\Debug"
# PROP Intermediate_Dir "..\..\Intermediate\MVCDemo\Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "..\Public" /I "..\AWS_Mobile" /I "..\AWS_Core" /I "..\AWS_BaseCtrl" /I "..\SPX" /I "..\OS_Base" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "_AFXDLL" /YX /FD /GZ /c
# ADD BASE RSC /l 0x804 /d "_DEBUG"
# ADD RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ENDIF 

# Begin Target

# Name "MVCDemo - Win32 Release"
# Name "MVCDemo - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\Model1Observer1.cpp
# End Source File
# Begin Source File

SOURCE=.\Model1Observer2.cpp
# End Source File
# Begin Source File

SOURCE=.\Model2Observer1.cpp
# End Source File
# Begin Source File

SOURCE=.\Model2Observer2.cpp
# End Source File
# Begin Source File

SOURCE=.\MyApp.cpp
# End Source File
# Begin Source File

SOURCE=.\MyContainer.cpp
# End Source File
# Begin Source File

SOURCE=.\MyController1.cpp
# End Source File
# Begin Source File

SOURCE=.\MyController2.cpp
# End Source File
# Begin Source File

SOURCE=.\MyModel1.cpp
# End Source File
# Begin Source File

SOURCE=.\MyModel2.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\Model1Observer1.h
# End Source File
# Begin Source File

SOURCE=.\Model1Observer2.h
# End Source File
# Begin Source File

SOURCE=.\Model2Observer1.h
# End Source File
# Begin Source File

SOURCE=.\Model2Observer2.h
# End Source File
# Begin Source File

SOURCE=.\MVCUserDefine.h
# End Source File
# Begin Source File

SOURCE=.\MyApp.h
# End Source File
# Begin Source File

SOURCE=.\MyContainer.h
# End Source File
# Begin Source File

SOURCE=.\MyController1.h
# End Source File
# Begin Source File

SOURCE=.\MyController2.h
# End Source File
# Begin Source File

SOURCE=.\MyModel1.h
# End Source File
# Begin Source File

SOURCE=.\MyModel2.h
# End Source File
# End Group
# End Target
# End Project
