void __stdcall KeInitializeMutant(_KMUTANT *Mutant, char InitialOwner)
{
  _KTHREAD *v2; // edi
  KIRQL v3; // al
  _LIST_ENTRY *v4; // edx
  _LIST_ENTRY *v5; // ebx

  Mutant->Header.Type = 2;
  Mutant->Header.Size = 8;
  if ( InitialOwner == 1 )
  {
    v2 = thread;
    Mutant->Header.SignalState = 0;
    Mutant->OwnerThread = v2;
    v3 = KeRaiseIrqlToDpcLevel();
    v4 = v2->MutantListHead.Blink;
    v5 = v4->Flink;
    Mutant->MutantListEntry.Flink = v4->Flink;
    Mutant->MutantListEntry.Blink = v4;
    v5->Blink = &Mutant->MutantListEntry;
    v4->Flink = &Mutant->MutantListEntry;
    KiUnlockDispatcherDatabase(v3);
  }
  else
  {
    Mutant->OwnerThread = 0;
    Mutant->Header.SignalState = 1;
  }
  Mutant->Abandoned = 0;
  InitializeListHead(&Mutant->Header.WaitListHead);
}