unsigned int __usercall DbgPrint@<eax>(int *a1@<edi>, char *Format, ...)
{
  int v2; // eax
  unsigned int result; // eax
  char Buffer[512]; // [esp+0h] [ebp-208h]
  _STRING Output; // [esp+200h] [ebp-8h]
  va_list ap; // [esp+214h] [ebp+Ch]

  va_start(ap, Format);
  v2 = _vsnprintf(a1, Buffer, 0x200u, Format, ap);
  if ( v2 == -1 )
  {
    LOWORD(v2) = 512;
    Buffer[511] = 10;
  }
  Output.Length = v2;
  Output.Buffer = Buffer;
  result = DebugPrint(&Output);
  if ( result == -2147483645 )
  {
    DbgBreakPointWithStatus(1u);
    result = 0;
  }
  return result;
}