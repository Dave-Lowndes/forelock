#include "stdafx.h"
#include <Windows.h>

int _tmain(int argc, _TCHAR* argv[])
{
	DWORD Value;

	if ( argc >= 2 )
	{
		Value = _ttoi( argv[1] );

		if ( SystemParametersInfo( SPI_SETFOREGROUNDLOCKTIMEOUT, 0, (PVOID) Value, SPIF_UPDATEINIFILE | SPIF_SENDCHANGE ) )
		{
			_tprintf( _T("Changed ") );
		}
	}
	else
	{
		_tprintf( _T("Usage:\n\nForelock [number]\n")
					_T("\tnumber is the desired foreground lock timeout in ms\n")
					_T("Copyright JD Design 2008-2023\n\n") );
	}

	if ( SystemParametersInfo( SPI_GETFOREGROUNDLOCKTIMEOUT, 0, &Value, 0 ) )
	{
		_tprintf( _T("foreground lock timeout: %d ms\n"), Value );
	}

	return 0;
}

