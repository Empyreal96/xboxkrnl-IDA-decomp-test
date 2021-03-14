char __stdcall KeConnectInterrupt(_KINTERRUPT *Interrupt)
{
  char v1; // bl
  unsigned int v2; // ecx
  unsigned int v3; // eax
  char OldIrql; // [esp+Bh] [ebp-1h]

  v1 = 0;
  OldIrql = KeRaiseIrqlToDpcLevel();
  if ( !Interrupt->Connected )
  {
    v2 = Interrupt->BusInterruptLevel;
    v3 = 4 * Interrupt->BusInterruptLevel;
    if ( (int (__usercall *)@<eax>(int@<eax>, int@<edx>, int@<ecx>, int *))((unsigned __int16)word_8004BD88[v3] | ((unsigned __int16)word_8004BD8E[v3] << 16)) == (int (__usercall *)@<eax>(int@<eax>, int@<edx>, int@<ecx>, int *))((char *)KiStartUnexpectedRange + v2 * *(_DWORD *)&KiIDTEnd[0].Offset) )
    {
      word_8004BD8E[v3] = (unsigned int)Interrupt->DispatchCode >> 16;
      word_8004BD88[v3] = (_WORD)Interrupt + 24;
      HalEnableSystemInterrupt(v2, Interrupt->Mode);
      Interrupt->Connected = 1;
      v1 = 1;
    }
  }
  KiUnlockDispatcherDatabase(OldIrql);
  return v1;
}