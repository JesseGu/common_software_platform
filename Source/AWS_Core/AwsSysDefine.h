/******************************************************************************
* FileName		       : AwsSysDefine.h
* Description          : interface for the AwsSysDefine file
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng(@NJUST)
* weibo http://weibo.com/gujicheng197
*------------------------------------------------------------------------------
******************************************************************************/

#ifndef _AWSSYSDEFINE_H_2011_03_12_
#define _AWSSYSDEFINE_H_2011_03_12_

#include "EspSysDefine.h"

// 按键类型定义
enum AWS_KeyType
{
	AWS_Key_Null,

	AWS_Key_Down,
	AWS_Key,
	AWS_Key_Up
};

// 按键代码
enum AWS_KeyCode
{
	AWS_KeyCode_Null = 100,

	AWS_KeyCode_1,
	AWS_KeyCode_2,
	AWS_KeyCode_3,
	AWS_KeyCode_4,
	AWS_KeyCode_5,
	AWS_KeyCode_6,
	AWS_KeyCode_7,
	AWS_KeyCode_8,
	AWS_KeyCode_9,
	AWS_KeyCode_Star,	// *
	AWS_KeyCode_0,
	AWS_KeyCode_Well,	// #

	AWS_KeyCode_UpArrow,
	AWS_KeyCode_DownArrow,
	AWS_KeyCode_LeftArrow,
	AWS_KeyCode_RightArrow,
	AWS_KeyCode_OK,
	AWS_KeyCode_LeftMenu,
	AWS_KeyCode_RightMenu,

	AWS_KeyCode_Delete,

	AWS_KeyCode_End
};

// 文本显示模式
enum AWS_TextShowMode
{
	AWS_TSM_Transparent,
	AWS_TSM_Opaque
};

// 文本对齐模式
enum AWS_TextAlignMode
{
	AWS_TAM_Left,
	AWS_TAM_Mid,
	AWS_TAM_Right
};

// msgbox的类型
enum AWS_MsgBoxType
{
	AWS_MBT_OK_Cancel = 1,
	AWS_MBT_OK
};

// 系统命令
enum AWS_SysCommand
{
	AWS_SysCmd = 100,

	AWS_SysCmd_ExitApp,
	AWS_SysCmd_PopMenu,
	AWS_SysCmd_MenuItemClick,
	AWS_SysCmd_MenuCmd,
	AWS_SysCmd_MenuDestroy,		// 菜单销毁通知消息
	AWS_SysCmd_LeftMenuClick,
	AWS_SysCmd_RightMenuClick,
	AWS_SysCmd_ListBoxCmd,
	AWS_SysCmd_ListViewCmd,
	AWS_SysCmd_ButtonCmd,
	AWS_SysCmd_ComboBoxItemChange,
	AWS_SysCmd_ScrollLabelEndScroll,

	AWS_SysCmd_SelectBoxCmd,
	AWS_SysCmd_SelectBoxFocusItemChange,
	AWS_SysCmd_TabPanelChangePage,
	AWS_SysCmd_TabViewSetPanelFocus,

	AWS_SysCmd_MsgBox_OK,
	AWS_SysCmd_MsgBox_Cancel,

	// 删除指定窗口，nParam1指出窗口的句柄
	AWS_SysCmd_DeleteWnd,

	AWS_SysCmd_End
};

enum AWS_MenuID
{
	AWS_MenuID_Left = 100,
	AWS_MenuID_Right,

	AWS_ComboBox_PopupWnd
};

enum AWS_SysStringID
{
	StringID_Menu,
	StringID_Exit,
	StringID_Select,
	StringID_OK,
	StringID_Cancel,
	StringID_Return,
	StringID_NULL,

	AWS_SysStringCount
};

#endif /* _AWSSYSDEFINE_H_2011_03_12_ */
