/***************************************************************************

Copyright (c) Microsoft Corporation. All rights reserved.
This code is licensed under the Visual Studio SDK license terms.
THIS CODE IS PROVIDED *AS IS* WITHOUT WARRANTY OF
ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING ANY
IMPLIED WARRANTIES OF FITNESS FOR A PARTICULAR
PURPOSE, MERCHANTABILITY, OR NON-INFRINGEMENT.

This code is a part of the Visual Studio Library.

***************************************************************************/

#ifndef IVSFILECHANGEEVENTS_H_10C49CA1_2F46_11D3_A504_00C04F5E0BA5
#define IVSFILECHANGEEVENTS_H_10C49CA1_2F46_11D3_A504_00C04F5E0BA5

#if _MSC_VER > 1000
#pragma once
#endif

#include "vsshell.h"

#pragma warning(push)
#pragma warning(disable : 4510) // default constructor could not be generated
#pragma warning(disable : 4610) // can never be instantiated - user defined constructor required
#pragma warning(disable : 4512) // assignment operator could not be generated
#pragma warning(disable : 6011) // Dereferencing NULL pointer (a NULL derference is just another kind of failure for a unit test

namespace VSL
{

class IVsFileChangeEventsNotImpl :
	public IVsFileChangeEvents
{

VSL_DECLARE_NONINSTANTIABLE_BASE_CLASS(IVsFileChangeEventsNotImpl)

public:

	typedef IVsFileChangeEvents Interface;

	STDMETHOD(FilesChanged)(
		/*[in]*/ DWORD /*cChanges*/,
		/*[in,size_is(cChanges)]*/ LPCOLESTR[] /*rgpszFile*/,
		/*[in,size_is(cChanges)]*/ VSFILECHANGEFLAGS[] /*rggrfChange*/)VSL_STDMETHOD_NOTIMPL

	STDMETHOD(DirectoryChanged)(
		/*[in]*/ LPCOLESTR /*pszDirectory*/)VSL_STDMETHOD_NOTIMPL
};

class IVsFileChangeEventsMockImpl :
	public IVsFileChangeEvents,
	public MockBase
{

VSL_DECLARE_NONINSTANTIABLE_BASE_CLASS(IVsFileChangeEventsMockImpl)

public:

VSL_DEFINE_MOCK_CLASS_TYPDEFS(IVsFileChangeEventsMockImpl)

	typedef IVsFileChangeEvents Interface;
	struct FilesChangedValidValues
	{
		/*[in]*/ DWORD cChanges;
		/*[in,size_is(cChanges)]*/ LPCOLESTR* rgpszFile;
		/*[in,size_is(cChanges)]*/ VSFILECHANGEFLAGS* rggrfChange;
		HRESULT retValue;
	};

	STDMETHOD(FilesChanged)(
		/*[in]*/ DWORD cChanges,
		/*[in,size_is(cChanges)]*/ LPCOLESTR rgpszFile[],
		/*[in,size_is(cChanges)]*/ VSFILECHANGEFLAGS rggrfChange[])
	{
		VSL_DEFINE_MOCK_METHOD(FilesChanged)

		VSL_CHECK_VALIDVALUE(cChanges);

		VSL_CHECK_VALIDVALUE_MEMCMP(rgpszFile, cChanges*sizeof(rgpszFile[0]), validValues.cChanges*sizeof(validValues.rgpszFile[0]));

		VSL_CHECK_VALIDVALUE_MEMCMP(rggrfChange, cChanges*sizeof(rggrfChange[0]), validValues.cChanges*sizeof(validValues.rggrfChange[0]));

		VSL_RETURN_VALIDVALUES();
	}
	struct DirectoryChangedValidValues
	{
		/*[in]*/ LPCOLESTR pszDirectory;
		HRESULT retValue;
	};

	STDMETHOD(DirectoryChanged)(
		/*[in]*/ LPCOLESTR pszDirectory)
	{
		VSL_DEFINE_MOCK_METHOD(DirectoryChanged)

		VSL_CHECK_VALIDVALUE_STRINGW(pszDirectory);

		VSL_RETURN_VALIDVALUES();
	}
};


} // namespace VSL

#pragma warning(pop)

#endif // IVSFILECHANGEEVENTS_H_10C49CA1_2F46_11D3_A504_00C04F5E0BA5