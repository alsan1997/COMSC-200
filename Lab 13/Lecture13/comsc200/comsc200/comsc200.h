
// comsc200.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// Ccomsc200App:
// See comsc200.cpp for the implementation of this class
//

class Ccomsc200App : public CWinApp
{
public:
	Ccomsc200App();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern Ccomsc200App theApp;