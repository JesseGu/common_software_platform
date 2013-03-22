# Microsoft Developer Studio Project File - Name="Win32Adapter_C" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=Win32Adapter_C - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Win32Adapter_C.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Win32Adapter_C.mak" CFG="Win32Adapter_C - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Win32Adapter_C - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "Win32Adapter_C - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Win32Adapter_C - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\Bin\Win32Adapter_C\Release"
# PROP Intermediate_Dir "..\..\Intermediate\Win32Adapter_C\Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /W3 /GX /O2 /I "..\MobileDemo_C" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "NDEBUG"
# ADD RSC /l 0x804 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "Win32Adapter_C - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\Bin\Win32Adapter_C\Debug"
# PROP Intermediate_Dir "..\..\Intermediate\Win32Adapter_C\Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /W3 /Gm /GX /ZI /Od /I "..\MobileDemo_C" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "_DEBUG"
# ADD RSC /l 0x804 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "Win32Adapter_C - Win32 Release"
# Name "Win32Adapter_C - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\EMyui.c
# End Source File
# Begin Source File

SOURCE=.\EScreen.c
# End Source File
# Begin Source File

SOURCE=.\EWndGc.c
# End Source File
# Begin Source File

SOURCE=.\StdAfx.c
# ADD CPP /Yc
# End Source File
# Begin Source File

SOURCE=.\Win32Os.c
# End Source File
# Begin Source File

SOURCE=.\Win32Adapter_C.c
# End Source File
# Begin Source File

SOURCE=.\Win32Adapter_C.rc
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

SOURCE=.\resource.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\Win32Os.h
# End Source File
# Begin Source File

SOURCE=.\Win32Adapter_C.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\Check.bmp
# End Source File
# Begin Source File

SOURCE=.\CheckFocus.bmp
# End Source File
# Begin Source File

SOURCE=.\CheckMask.bmp
# End Source File
# Begin Source File

SOURCE=.\CheckSel.bmp
# End Source File
# Begin Source File

SOURCE=.\CheckSelFocus.bmp
# End Source File
# Begin Source File

SOURCE=.\Main1.bmp
# End Source File
# Begin Source File

SOURCE=.\Main10.bmp
# End Source File
# Begin Source File

SOURCE=.\Main11.bmp
# End Source File
# Begin Source File

SOURCE=.\Main12.bmp
# End Source File
# Begin Source File

SOURCE=.\Main2.bmp
# End Source File
# Begin Source File

SOURCE=.\Main3.bmp
# End Source File
# Begin Source File

SOURCE=.\Main4.bmp
# End Source File
# Begin Source File

SOURCE=.\Main5.bmp
# End Source File
# Begin Source File

SOURCE=.\Main6.bmp
# End Source File
# Begin Source File

SOURCE=.\Main7.bmp
# End Source File
# Begin Source File

SOURCE=.\Main8.bmp
# End Source File
# Begin Source File

SOURCE=.\Main9.bmp
# End Source File
# Begin Source File

SOURCE=.\MainMask.bmp
# End Source File
# Begin Source File

SOURCE=.\MemuBar.bmp
# End Source File
# Begin Source File

SOURCE=.\Radio.bmp
# End Source File
# Begin Source File

SOURCE=.\RadioFocus.bmp
# End Source File
# Begin Source File

SOURCE=.\RadioMask.bmp
# End Source File
# Begin Source File

SOURCE=.\RadioSel.bmp
# End Source File
# Begin Source File

SOURCE=.\RadioSelFocus.bmp
# End Source File
# Begin Source File

SOURCE=.\small.ico
# End Source File
# Begin Source File

SOURCE=.\TabItemSelBK.bmp
# End Source File
# Begin Source File

SOURCE=.\TabItemSelBKMask.bmp
# End Source File
# Begin Source File

SOURCE=.\TabPanelBK.bmp
# End Source File
# Begin Source File

SOURCE=.\TitleBar.bmp
# End Source File
# Begin Source File

SOURCE=.\TitleIcon.bmp
# End Source File
# Begin Source File

SOURCE=.\TitleMask.bmp
# End Source File
# Begin Source File

SOURCE=.\Win32Adapter_C.ico
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
