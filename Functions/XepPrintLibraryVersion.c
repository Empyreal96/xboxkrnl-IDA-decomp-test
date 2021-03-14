void __stdcall XepPrintLibraryVersion(_XBEIMAGE_LIBRARY_VERSION *LibraryVersion)
{
  __int16 v1; // cx
  char *v2; // edi
  const char *v3; // esi
  char *v4; // edx

  v1 = *((_WORD *)LibraryVersion + 7);
  if ( v1 & 0x1000 )
  {
    v2 = "This XBE is %.8s.%s version %d.%02d.%d.%02d%s\n";
    v3 = "XBE";
  }
  else
  {
    v2 = "This XBE was linked with %8.8s%s %d.%02d.%d.%02d%s\n";
    v3 = " (feature)  ";
    if ( !(v1 & 0x800) )
      v3 = ".LIB version";
  }
  v4 = " (Debug)";
  if ( v1 >= 0 )
    v4 = byte_80014442;
  DbgPrint(
    (int *)v2,
    v2,
    LibraryVersion,
    v3,
    LibraryVersion->MajorVersion,
    LibraryVersion->MinorVersion,
    LibraryVersion->BuildVersion,
    (unsigned __int8)v1,
    v4);
}