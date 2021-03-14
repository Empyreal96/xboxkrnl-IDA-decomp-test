void __stdcall ExceptionRecord32To64(_EXCEPTION_RECORD32 *Ex32, _EXCEPTION_RECORD64 *Ex64)
{
  unsigned int v2; // ebx
  unsigned int v3; // eax
  unsigned __int64 *v4; // edi
  unsigned int *v5; // esi

  Ex64->ExceptionCode = Ex32->ExceptionCode;
  Ex64->ExceptionFlags = Ex32->ExceptionFlags;
  v2 = 0;
  Ex64->ExceptionRecord = Ex32->ExceptionRecord;
  Ex64->ExceptionAddress = (signed int)Ex32->ExceptionAddress;
  v3 = Ex32->NumberParameters;
  Ex64->NumberParameters = v3;
  if ( v3 )
  {
    v4 = Ex64->ExceptionInformation;
    v5 = Ex32->ExceptionInformation;
    do
    {
      *v4 = (signed int)*v5;
      ++v2;
      ++v5;
      ++v4;
    }
    while ( v2 < Ex64->NumberParameters );
  }
}