# Microsoft Developer Studio Project File - Name="MobileDemo" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=MobileDemo - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "MobileDemo.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "MobileDemo.mak" CFG="MobileDemo - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "MobileDemo - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "MobileDemo - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "MobileDemo - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\Bin\MobileDemo\Release"
# PROP Intermediate_Dir "..\..\Intermediate\MobileDemo\Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /I "..\Public" /I "..\AWS_Mobile" /I "..\AWS_Core" /I "..\AWS_Base" /I "..\SPX" /I "..\AWS_BaseCtrl" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /D "_AFXDLL" /YX /FD /c
# ADD BASE RSC /l 0x804 /d "NDEBUG"
# ADD RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ELSEIF  "$(CFG)" == "MobileDemo - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\Bin\MobileDemo\Debug"
# PROP Intermediate_Dir "..\..\Intermediate\MobileDemo\Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "..\Public" /I "..\AWS_Mobile" /I "..\AWS_Core" /I "..\AWS_Base" /I "..\SPX" /I "..\AWS_BaseCtrl" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "_AFXDLL" /YX /FD /GZ /c
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

# Name "MobileDemo - Win32 Release"
# Name "MobileDemo - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\MyApp.cpp
# End Source File
# Begin Source File

SOURCE=.\MyMainContainer.cpp
# End Source File
# Begin Source File

SOURCE=.\MyUi.cpp
# End Source File
# Begin Source File

SOURCE=.\TabMainContainer.cpp
# End Source File
# Begin Source File

SOURCE=.\TabPage1.cpp
# End Source File
# Begin Source File

SOURCE=.\TabPage2.cpp
# End Source File
# Begin Source File

SOURCE=.\TabPage3.cpp
# End Source File
# Begin Source File

SOURCE=.\TabPage4.cpp
# End Source File
# Begin Source File

SOURCE=.\TabPage5.cpp
# End Source File
# Begin Source File

SOURCE=.\TabPage6.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\AwsUserDefine.h
# End Source File
# Begin Source File

SOURCE=.\MyApp.h
# End Source File
# Begin Source File

SOURCE=.\MyMainContainer.h
# End Source File
# Begin Source File

SOURCE=.\MyUi.h
# End Source File
# Begin Source File

SOURCE=.\TabMainContainer.h
# End Source File
# Begin Source File

SOURCE=.\TabPage1.h
# End Source File
# Begin Source File

SOURCE=.\TabPage2.h
# End Source File
# Begin Source File

SOURCE=.\TabPage3.h
# End Source File
# Begin Source File

SOURCE=.\TabPage4.h
# End Source File
# Begin Source File

SOURCE=.\TabPage5.h
# End Source File
# Begin Source File

SOURCE=.\TabPage6.h
# End Source File
# End Group
# End Target
# End Project
