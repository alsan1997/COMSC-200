
// Comsc200.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CComsc200App:
// See Comsc200.cpp for the implementation of this class
//

class CComsc200App : public CWinApp
{
public:
	CComsc200App();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CComsc200App theApp;