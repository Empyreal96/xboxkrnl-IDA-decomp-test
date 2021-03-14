void __usercall BootSound_Stop(int a1@<edx>, int a2@<ecx>, int *a3@<edi>)
{
  int v3; // edx
  int v4; // ecx

  KeCancelTimer(a2, a1, &g_BootSoundTimer);
  dev_cleanup();
  if ( g_dwDirectSoundPoolMemoryUsage )
    RtlAssert(
      v3,
      v4,
      a3,
      (int)"d:\\xbox-apr03\\private\\ntos\\ani2\\bootsound.cpp",
      "g_dwDirectSoundPoolMemoryUsage == 0",
      "d:\\xbox-apr03\\private\\ntos\\ani2\\bootsound.cpp",
      0x6Bu,
      0);
  if ( g_dwDirectSoundPhysicalMemoryUsage )
    RtlAssert(
      v3,
      v4,
      a3,
      (int)"d:\\xbox-apr03\\private\\ntos\\ani2\\bootsound.cpp",
      "g_dwDirectSoundPhysicalMemoryUsage == 0",
      "d:\\xbox-apr03\\private\\ntos\\ani2\\bootsound.cpp",
      0x6Cu,
      0);
}