void __userpurge KeInitializeInterrupt(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, _KINTERRUPT *Interrupt, char (__stdcall *ServiceRoutine)(_KINTERRUPT *, void *), void *ServiceContext, unsigned int Vector, char Irql, _KINTERRUPT_MODE InterruptMode, char ShareVector)
{
  int v10; // ecx
  int v11; // eax
  int (__usercall *v12)@<eax>(int *@<edi>); // ecx
  int (__usercall *v13)@<eax>(int *@<edi>); // eax

  if ( (unsigned __int8)Irql > 0x1Fu )
    RtlAssert(
      a1,
      a2,
      a3,
      (int)"d:\\xbox-apr03\\private\\ntos\\ke\\i386\\intobj.c",
      "Irql <= HIGH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\ke\\i386\\intobj.c",
      0x58u,
      0);
  if ( Vector < 0x30 || Vector >= 0x40 )
    RtlAssert(
      a1,
      a2,
      (int *)Vector,
      (int)"d:\\xbox-apr03\\private\\ntos\\ke\\i386\\intobj.c",
      "Vector >= PRIMARY_VECTOR_BASE && Vector < PRIMARY_VECTOR_BASE + 16",
      "d:\\xbox-apr03\\private\\ntos\\ke\\i386\\intobj.c",
      0x59u,
      0);
  v10 = (unsigned __int8)Irql;
  Interrupt->ServiceRoutine = ServiceRoutine;
  Interrupt->Irql = (unsigned __int8)Irql;
  LOBYTE(v10) = InterruptMode;
  Interrupt->ServiceContext = ServiceContext;
  Interrupt->BusInterruptLevel = Vector - 48;
  Interrupt->Mode = InterruptMode;
  if ( Vector == 49 )
    KiInitializeInterruptUsbHack(v10, a1, ServiceContext, ShareVector);
  v11 = (char *)Interrupt->DispatchCode - KiInterruptTemplate;
  qmemcpy(Interrupt->DispatchCode, KiInterruptTemplate, sizeof(Interrupt->DispatchCode));
  *(_DWORD *)(v11 - 2147332820) = Interrupt;
  v12 = (int (__usercall *)@<eax>(int *@<edi>))(v11 - 2147332815);
  v13 = KiLevelInterruptDispatch;
  if ( InterruptMode )
    v13 = KiInterruptDispatch;
  *(_DWORD *)v12 = (char *)v13 - (char *)v12 - 4;
  Interrupt->Connected = 0;
}