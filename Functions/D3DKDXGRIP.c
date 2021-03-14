void __usercall D3DK::DXGRIP(int *a1@<edi>, char *Format, ...)
{
  char string[260]; // [esp+0h] [ebp-104h]
  va_list ap; // [esp+110h] [ebp+Ch]

  va_start(ap, Format);
  _vsnprintf(a1, string, 0x104u, Format, ap);
  DbgPrint(a1, string);
  __debugbreak();
}