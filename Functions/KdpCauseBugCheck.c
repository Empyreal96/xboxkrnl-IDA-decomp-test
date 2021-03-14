void __stdcall __noreturn KdpCauseBugCheck(_DBGKD_MANIPULATE_STATE64 *m)
{
  KeBugCheckEx(0xE2u, 0, 0, 0, 0);
}