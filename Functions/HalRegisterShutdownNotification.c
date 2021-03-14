void __stdcall HalRegisterShutdownNotification(_HAL_SHUTDOWN_REGISTRATION *ShutdownRegistration, char Register)
{
  KIRQL v2; // al
  _LIST_ENTRY *v3; // edx
  KIRQL v4; // cl
  _LIST_ENTRY *v5; // ebx
  _LIST_ENTRY *v6; // ebx

  v2 = KeRaiseIrqlToDpcLevel();
  v3 = HalpShutdownRegistrationList.Flink;
  v4 = v2;
  if ( Register )
  {
    if ( IsListEmpty(&HalpShutdownRegistrationList) )
      goto LABEL_17;
    while ( ShutdownRegistration->Priority <= (_DWORD)v3[-1].Blink )
    {
      v3 = v3->Flink;
      if ( v3 == &HalpShutdownRegistrationList )
        goto LABEL_7;
    }
    v5 = v3->Blink;
    ShutdownRegistration->ListEntry.Flink = v3;
    ShutdownRegistration->ListEntry.Blink = v5;
    v5->Flink = &ShutdownRegistration->ListEntry;
    v3->Blink = &ShutdownRegistration->ListEntry;
LABEL_7:
    if ( v3 == &HalpShutdownRegistrationList )
    {
LABEL_17:
      v6 = v3->Blink;
      ShutdownRegistration->ListEntry.Flink = v3;
      ShutdownRegistration->ListEntry.Blink = v6;
      v6->Flink = &ShutdownRegistration->ListEntry;
      v3->Blink = &ShutdownRegistration->ListEntry;
    }
  }
  else if ( !IsListEmpty(&HalpShutdownRegistrationList) )
  {
    while ( ShutdownRegistration != (_HAL_SHUTDOWN_REGISTRATION *)&v3[-1] )
    {
      v3 = v3->Flink;
      if ( v3 == &HalpShutdownRegistrationList )
        goto LABEL_14;
    }
    RemoveEntryList(&ShutdownRegistration->ListEntry);
  }
LABEL_14:
  KfLowerIrql(v4);
}