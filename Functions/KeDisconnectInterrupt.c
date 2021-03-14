char __stdcall KeDisconnectInterrupt(_KINTERRUPT *Interrupt)
{
  _KINTERRUPT *v1; // edi
  unsigned int v2; // esi
  int v3; // ecx
  __int16 v4; // ax
  char OldIrql; // [esp+7h] [ebp-1h]
  char Connected_3; // [esp+13h] [ebp+Bh]

  v1 = Interrupt;
  OldIrql = KeRaiseIrqlToDpcLevel();
  Connected_3 = Interrupt->Connected;
  if ( Connected_3 )
  {
    v2 = v1->BusInterruptLevel;
    HalDisableSystemInterrupt(v1->BusInterruptLevel);
    v3 = 4 * v2;
    v4 = (__int16)((char *)KiStartUnexpectedRange + v2 * KiIDTEnd[0].Offset);
    word_8004BD8E[v3] = ((unsigned int)KiStartUnexpectedRange + v2 * *(_DWORD *)&KiIDTEnd[0].Offset) >> 16;
    word_8004BD88[v3] = v4;
    v1->Connected = 0;
  }
  KiUnlockDispatcherDatabase(OldIrql);
  return Connected_3;
}