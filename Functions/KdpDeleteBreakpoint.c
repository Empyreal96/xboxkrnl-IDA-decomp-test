char __userpurge KdpDeleteBreakpoint@<al>(int *a1@<edi>, unsigned int Handle)
{
  char *v2; // esi
  char v3; // cl

  if ( !Handle || Handle > 0x20 )
  {
    KdpDprintf(a1, "KD: Breakpoint %d invalid.\n", Handle - 1);
    return 0;
  }
  v2 = (char *)(8 * (Handle - 1) - 2147105872);
  v3 = *v2;
  if ( !*v2 )
    return 0;
  if ( v3 & 4 && !(v3 & 8) || KdpLowWriteContent(Handle - 1) )
    *v2 = 0;
  return 1;
}