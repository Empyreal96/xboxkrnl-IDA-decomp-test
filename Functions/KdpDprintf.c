void __usercall KdpDprintf(int *a1@<edi>, char *f, ...)
{
  char buf[100]; // [esp+0h] [ebp-6Ch]
  _STRING Output; // [esp+64h] [ebp-8h]
  va_list ap; // [esp+78h] [ebp+Ch]

  va_start(ap, f);
  _vsnprintf(a1, buf, 0x64u, f, ap);
  Output.Buffer = buf;
  Output.Length = strlen(buf);
  KdpPrintString(&Output);
}