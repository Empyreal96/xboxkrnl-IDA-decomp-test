void __stdcall RtlFreeAnsiString(_STRING *AnsiString)
{
  if ( AnsiString->Buffer )
  {
    ExFreePool(AnsiString->Buffer);
    *(_DWORD *)&AnsiString->Length = 0;
    AnsiString->Buffer = 0;
  }
}