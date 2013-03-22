# Microsoft Developer Studio Project File - Name="MVCDemo_C" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=MVCDemo_C - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "MVCDemo_C.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "MVCDemo_C.mak" CFG="MVCDemo_C - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "MVCDemo_C - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "MVCDemo_C - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "MVCDemo_C - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\Bin\MVCDemo_C\Release"
# PROP Intermediate_Dir "..\..\Intermediate\MVCDemo_C\Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD BASE RSC /l 0x804 /d "NDEBUG"
# ADD RSC /l 0x804 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ELSEIF  "$(CFG)" == "MVCDemo_C - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\Bin\MVCDemo_C\Debug"
# PROP Intermediate_Dir "..\..\Intermediate\MVCDemo_C\Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ  /c
# ADD CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ  /c
# ADD BASE RSC /l 0x804 /d "_DEBUG"
# ADD RSC /l 0x804 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ENDIF 

# Begin Target

# Name "MVCDemo_C - Win32 Release"
# Name "MVCDemo_C - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\AwsContainer.c
# End Source File
# Begin Source File

SOURCE=.\AwsPubClass.c
# End Source File
# Begin Source File

SOURCE=.\AwsUi.c
# End Source File
# Begin Source File

SOURCE=.\AwsWindow.c
# End Source File
# Begin Source File

SOURCE=.\BButton.c
# End Source File
# Begin Source File

SOURCE=.\BCheckBox.c
# End Source File
# Begin Source File

SOURCE=.\BComboBox.c
# End Source File
# Begin Source File

SOURCE=.\BEdit.c
# End Source File
# Begin Source File

SOURCE=.\BImageButton.c
# End Source File
# Begin Source File

SOURCE=.\BLabel.c
# End Source File
# Begin Source File

SOURCE=.\BListBox.c
# End Source File
# Begin Source File

SOURCE=.\BListView.c
# End Source File
# Begin Source File

SOURCE=.\BMenu.c
# End Source File
# Begin Source File

SOURCE=.\BMenuContainer.c
# End Source File
# Begin Source File

SOURCE=.\BProgressBar.c
# End Source File
# Begin Source File

SOURCE=.\BRadioBox.c
# End Source File
# Begin Source File

SOURCE=.\BScrollBar.c
# End Source File
# Begin Source File

SOURCE=.\BSelectBox.c
# End Source File
# Begin Source File

SOURCE=.\BTabPanel.c
# End Source File
# Begin Source File

SOURCE=.\BTabView.c
# End Source File
# Begin Source File

SOURCE=.\BTitleBar.c
# End Source File
# Begin Source File

SOURCE=.\BTreeView.c
# End Source File
# Begin Source File

SOURCE=.\EspPubClass.c
# End Source File
# Begin Source File

SOURCE=.\EspString.c
# End Source File
# Begin Source File

SOURCE=.\Model1Observer1.c
# End Source File
# Begin Source File

SOURCE=.\Model1Observer2.c
# End Source File
# Begin Source File

SOURCE=.\Model2Observer1.c
# End Source File
# Begin Source File

SOURCE=.\Model2Observer2.c
# End Source File
# Begin Source File

SOURCE=.\MyApp.c
# End Source File
# Begin Source File

SOURCE=.\MyContainer.c
# End Source File
# Begin Source File

SOURCE=.\MyController1.c
# End Source File
# Begin Source File

SOURCE=.\MyController2.c
# End Source File
# Begin Source File

SOURCE=.\MyModel1.c
# End Source File
# Begin Source File

SOURCE=.\MyModel2.c
# End Source File
# Begin Source File

SOURCE=.\Os.c
# End Source File
# Begin Source File

SOURCE=.\SPXApp.c
# End Source File
# Begin Source File

SOURCE=.\SPXController.c
# End Source File
# Begin Source File

SOURCE=.\SPXModel.c
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\AWS.h
# End Source File
# Begin Source File

SOURCE=.\AwsContainer.h
# End Source File
# Begin Source File

SOURCE=.\AwsPubClass.h
# End Source File
# Begin Source File

SOURCE=.\AwsSysDefine.h
# End Source File
# Begin Source File

SOURCE=.\AwsUi.h
# End Source File
# Begin Source File

SOURCE=.\AwsWindow.h
# End Source File
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
# Begin Source File

SOURCE=.\EspPubClass.h
# End Source File
# Begin Source File

SOURCE=.\EspString.h
# End Source File
# Begin Source File

SOURCE=.\EspSysDefine.h
# End Source File
# Begin Source File

SOURCE=.\IAwsContainerBuilder.h
# End Source File
# Begin Source File

SOURCE=.\IAwsGc.h
# End Source File
# Begin Source File

SOURCE=.\ISpxObserver.h
# End Source File
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
# Begin Source File

SOURCE=.\Os.h
# End Source File
# Begin Source File

SOURCE=.\SpxApp.h
# End Source File
# Begin Source File

SOURCE=.\SpxController.h
# End Source File
# Begin Source File

SOURCE=.\SpxModel.h
# End Source File
# Begin Source File

SOURCE=.\SpxSysDefine.h
# End Source File
# End Group
# End Target
# End Project
