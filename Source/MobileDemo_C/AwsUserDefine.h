/******************************************************************************
* FileName		       : AWSUserDefine.h
* Description          : the User Define Information
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng
*------------------------------------------------------------------------------
******************************************************************************/

#ifndef _AWSUSER_DEFINE_H_2009_09_19_
#define _AWSUSER_DEFINE_H_2009_09_19_

typedef enum tagEWndID EWndID;
enum tagEWndID
{
	EWndID_Menu1 = 10,
	EWndID_Menu1_Sub1,
	EWndID_Menu1_Sub2,
	EWndID_MsgBox,
	EWndID_Button1,
	EWndID_Button2,
	EWndID_Msg_ExitApp,
	EWndID_Msg_DeleteItem,
	EWndID_Msg_Selected,
	EWndID_Msg_ChangeMainContainer,
	EWndID_End
};


typedef enum tagEStringID EStringID;
enum tagEStringID
{
	StringID_TitleBar = AWS_SysStringCount,
	StringID_ProgressBar,
	StringID_Button,
	StringID_RadioBox,
	StringID_CheckBox,
	StringID_SelectBox,
	StringID_ComboBox,
	StringID_ListBox,
	StringID_ScrollLabel,
	StringID_Edit,
	StringID_HideTitleBar,
	StringID_ShowTitleBar,
	StringID_HideMenuBar,
	StringID_ShowMenuBar,
	StringID_WelcomeUse,
	StringID_ExitProgramme,
	StringID_RealDelete,
	StringID_Menu_Open,
	StringID_Menu_Delete,
	StringID_Menu_ChangeView,
	StringID_Menu_OtherPage,
	StringID_Menu_Exit,
	StringID_Menu_ListView,
	StringID_Menu_IconView,
	StringID_Menu_ReturnMainPage,
	StringID_Start,
	StringID_End,
	StringID_NJUST,
	StringID_Model1Button,
	StringID_Model2Button
};


typedef enum tagMainContainerID MainContainerID;
enum tagMainContainerID
{
	MyMainContainerID = 1,
	TabMainContainerID
};


#define IDB_MAIN9                       133
#define IDB_MAIN1                       134
#define IDB_MAIN2                       135
#define IDB_MAIN3                       136
#define IDB_MAIN4                       137
#define IDB_MAIN5                       138
#define IDB_MAIN6                       139
#define IDB_MAIN7                       140
#define IDB_MAIN8                       141
#define IDB_MAIN12                      142
#define IDB_MAIN10                      143
#define IDB_MAIN11                      144
#define IDB_MENUBAR                     145
#define IDB_TITLEBAR                    146
#define IDB_MAINMASK                    149
#define IDB_TITLEMASK                   150
#define IDB_TITLEICON                   151
#define IDB_TABITEMSELBK                152
#define IDB_TABITEMSELBKMASK            153
#define IDB_TABPANELBK                  154
#define IDB_RADIOSELFOCUS               155
#define IDB_RADIO                       156
#define IDB_RADIOFOCUS                  157
#define IDB_RADIOMASK                   158
#define IDB_RADIOSEL                    159
#define IDB_CHECKSELFOCUS               160
#define IDB_CHECK                       161
#define IDB_CHECKFOCUS                  162
#define IDB_CHECKMASK                   163
#define IDB_CHECKSEL                    164

#endif /* _AWSUSER_DEFINE_H_2009_09_19_ */
