# Microsoft Developer Studio Project File - Name="AWS_BaseCtrl" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=AWS_BaseCtrl - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "AWS_BaseCtrl.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "AWS_BaseCtrl.mak" CFG="AWS_BaseCtrl - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "AWS_BaseCtrl - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "AWS_BaseCtrl - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "AWS_BaseCtrl - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\Bin\AWS_BaseCtrl\Release"
# PROP Intermediate_Dir "..\..\Intermediate\AWS_BaseCtrl\Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /I "..\Public" /I "..\AWS_Core" /I "..\OS_Base" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /D "_AFXDLL" /YX /FD /c
# ADD BASE RSC /l 0x804 /d "NDEBUG"
# ADD RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ELSEIF  "$(CFG)" == "AWS_BaseCtrl - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\Bin\AWS_BaseCtrl\Debug"
# PROP Intermediate_Dir "..\..\Intermediate\AWS_BaseCtrl\Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "..\Public" /I "..\AWS_Core" /I "..\OS_Base" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "_AFXDLL" /YX /FD /GZ /c
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

# Name "AWS_BaseCtrl - Win32 Release"
# Name "AWS_BaseCtrl - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\BButton.cpp
# End Source File
# Begin Source File

SOURCE=.\BCheckBox.cpp
# End Source File
# Begin Source File

SOURCE=.\BComboBox.cpp
# End Source File
# Begin Source File

SOURCE=.\BEdit.cpp
# End Source File
# Begin Source File

SOURCE=.\BImageButton.cpp
# End Source File
# Begin Source File

SOURCE=.\BLabel.cpp
# End Source File
# Begin Source File

SOURCE=.\BListBox.cpp
# End Source File
# Begin Source File

SOURCE=.\BListView.cpp
# End Source File
# Begin Source File

SOURCE=.\BMenu.cpp
# End Source File
# Begin Source File

SOURCE=.\BMenuContainer.cpp
# End Source File
# Begin Source File

SOURCE=.\BProgressBar.cpp
# End Source File
# Begin Source File

SOURCE=.\BRadioBox.cpp
# End Source File
# Begin Source File

SOURCE=.\BScrollBar.cpp
# End Source File
# Begin Source File

SOURCE=.\BSelectBox.cpp
# End Source File
# Begin Source File

SOURCE=.\BTabPanel.cpp
# End Source File
# Begin Source File

SOURCE=.\BTabView.cpp
# End Source File
# Begin Source File

SOURCE=.\BTitleBar.cpp
# End Source File
# Begin Source File

SOURCE=.\BTreeView.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\BButton.h
# End Source File
# Begin Source File

SOURCE=.\BCheckBox.h
# End Source File
# Begin Source File

SOURCE=.\BComboBox.h
# End Source File
# Begin Source File

SOURCE=.\BEdit.h
# End Source File
# Begin Source File

SOURCE=.\BImageButton.h
# End Source File
# Begin Source File

SOURCE=.\BLabel.h
# End Source File
# Begin Source File

SOURCE=.\BListBox.h
# End Source File
# Begin Source File

SOURCE=.\BListView.h
# End Source File
# Begin Source File

SOURCE=.\BMenu.h
# End Source File
# Begin Source File

SOURCE=.\BMenuContainer.h
# End Source File
# Begin Source File

SOURCE=.\BProgressBar.h
# End Source File
# Begin Source File

SOURCE=.\BRadioBox.h
# End Source File
# Begin Source File

SOURCE=.\BScrollBar.h
# End Source File
# Begin Source File

SOURCE=.\BSelectBox.h
# End Source File
# Begin Source File

SOURCE=.\BTabPanel.h
# End Source File
# Begin Source File

SOURCE=.\BTabView.h
# End Source File
# Begin Source File

SOURCE=.\BTitleBar.h
# End Source File
# Begin Source File

SOURCE=.\BTreeView.h
# End Source File
# End Group
# End Target
# End Project
