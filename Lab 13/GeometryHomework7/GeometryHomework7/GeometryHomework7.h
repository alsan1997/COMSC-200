
// GeometryHomework7.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CGeometryHomework7App:
// See GeometryHomework7.cpp for the implementation of this class
//

class CGeometryHomework7App : public CWinApp
{
public:
	CGeometryHomework7App();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CGeometryHomework7App theApp;