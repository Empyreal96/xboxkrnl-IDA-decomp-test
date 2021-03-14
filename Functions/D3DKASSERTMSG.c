void __usercall D3DK::ASSERTMSG(int *a1@<edi>, int cond, char *Format, ...)
{
  char string[260]; // [esp+0h] [ebp-104h]
  va_list ap; // [esp+114h] [ebp+10h]

  va_start(ap, Format);
  if ( !cond )
  {
    _vsnprintf(a1, string, 0x104u, Format, ap);
    DbgPrint(a1, string);
    __debugbreak();
  }
}