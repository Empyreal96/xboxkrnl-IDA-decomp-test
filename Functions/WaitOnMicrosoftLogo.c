void __usercall WaitOnMicrosoftLogo(int *a1@<edi>, int a2@<edx>, int a3@<ecx>)
{
  int v3; // edx
  int v4; // ecx
  int v5; // ecx

  KeSetEvent(a3, a2, &g_EventLogoWaiting, 1, 1);
  KeWaitForSingleObject(v4, v3, &g_EventLogo, 0, 0, 0, 0);
  RenderMicrosoftLogo(a1, v5);
}