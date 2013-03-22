# Microsoft Developer Studio Project File - Name="Win32Adapter" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=Win32Adapter - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Win32Adapter.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Win32Adapter.mak" CFG="Win32Adapter - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Win32Adapter - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "Win32Adapter - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Win32Adapter - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\Bin\Win32Adapter\Release"
# PROP Intermediate_Dir "..\..\Intermediate\Win32Adapter\Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /I "..\Public" /I "..\AWS_Core" /I "..\AWS_Mobile" /I "..\AWS_BaseCtrl" /I "..\SPX" /I "..\OS_Base" /I "..\MVCDemo" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /FD /c
# SUBTRACT CPP /YX /Yc /Yu
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "Win32Adapter - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\Bin\Win32Adapter\Debug"
# PROP Intermediate_Dir "..\..\Intermediate\Win32Adapter\Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "..\Public" /I "..\AWS_Core" /I "..\AWS_Mobile" /I "..\AWS_BaseCtrl" /I "..\SPX" /I "..\OS_Base" /I "..\MobileDemo" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FD /GZ /c
# SUBTRACT CPP /YX /Yc /Yu
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "Win32Adapter - Win32 Release"
# Name "Win32Adapter - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\EMyui.cpp
# End Source File
# Begin Source File

SOURCE=.\EScreen.cpp
# End Source File
# Begin Source File

SOURCE=.\EWndGc.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\Win32Adapter.cpp
# End Source File
# Begin Source File

SOURCE=.\Win32Adapter.rc
# End Source File
# Begin Source File

SOURCE=.\Win32AdapterDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Win32File.cpp
# End Source File
# Begin Source File

SOURCE=.\Win32Os.cpp
# End Source File
# Begin Source File

SOURCE=.\Win32Thread.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\EMyui.h
# End Source File
# Begin Source File

SOURCE=.\EScreen.h
# End Source File
# Begin Source File

SOURCE=.\EWndGc.h
# End Source File
# Begin Source File

SOURCE=.\EWndString.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\Win32Adapter.h
# End Source File
# Begin Source File

SOURCE=.\Win32AdapterDlg.h
# End Source File
# Begin Source File

SOURCE=.\Win32File.h
# End Source File
# Begin Source File

SOURCE=.\Win32Os.h
# End Source File
# Begin Source File

SOURCE=.\Win32Thread.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\AwsDemo.ico
# End Source File
# Begin Source File

SOURCE=.\res\Big.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Check.bmp
# End Source File
# Begin Source File

SOURCE=.\res\CheckFocus.bmp
# End Source File
# Begin Source File

SOURCE=.\res\CheckMask.bmp
# End Source File
# Begin Source File

SOURCE=.\res\CheckSel.bmp
# End Source File
# Begin Source File

SOURCE=.\res\CheckSelFocus.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Main1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Main10.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Main11.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Main12.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Main2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Main3.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Main4.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Main5.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Main6.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Main7.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Main8.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Main9.bmp
# End Source File
# Begin Source File

SOURCE=.\res\MainMask.bmp
# End Source File
# Begin Source File

SOURCE=.\res\MemuBar.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Radio.bmp
# End Source File
# Begin Source File

SOURCE=.\res\RadioFocus.bmp
# End Source File
# Begin Source File

SOURCE=.\res\RadioMask.bmp
# End Source File
# Begin Source File

SOURCE=.\res\RadioSel.bmp
# End Source File
# Begin Source File

SOURCE=.\res\RadioSelFocus.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Small.bmp
# End Source File
# Begin Source File

SOURCE=.\res\TabItemSelBK.bmp
# End Source File
# Begin Source File

SOURCE=.\res\TabItemSelBKMask.bmp
# End Source File
# Begin Source File

SOURCE=.\res\TabPanelBK.bmp
# End Source File
# Begin Source File

SOURCE=.\res\TitleBar.bmp
# End Source File
# Begin Source File

SOURCE=.\res\TitleIcon.bmp
# End Source File
# Begin Source File

SOURCE=.\res\TitleMask.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Win32Adapter.ico
# End Source File
# Begin Source File

SOURCE=.\res\Win32Adapter.rc2
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
