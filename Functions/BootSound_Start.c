char __usercall BootSound_Start@<al>(int *a1@<edi>)
{
  int v1; // edx
  int v2; // ecx

  do_sos_init_return(a1);
  KeInitializeTimerEx(&g_BootSoundTimer, 0);
  KeInitializeDpc(&g_BootSoundDpc, BootSoundDpc, 0);
  return KeSetTimerEx(v2, v1, &g_BootSoundTimer, 0i64, 5, &g_BootSoundDpc);
}