void __userpurge RtlAssert(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, int a4@<esi>, void *FailedAssertion, void *FileName, unsigned int LineNumber, char *Message)
{
  char *v8; // eax
  char v9; // al
  _CONTEXT Context; // [esp+0h] [ebp-440h]
  char Buffer[512]; // [esp+238h] [ebp-208h]
  _STRING String; // [esp+438h] [ebp-8h]

  RtlCaptureContext((int)&Context, a1, a2, (int)a3, a4, &Context);
  v8 = Message;
  if ( !Message )
    v8 = byte_80014442;
  sprintf(
    a3,
    Buffer,
    "\n*** Assertion failed: %s%s\n***   Source File: %s, line %ld\n\n",
    v8,
    FailedAssertion,
    FileName,
    LineNumber);
  RtlInitAnsiString(&String, Buffer);
  while ( 1 )
  {
    while ( 1 )
    {
      while ( 1 )
      {
        v9 = DebugService(5u, &String, 0);
        if ( v9 == 66 )
          goto LABEL_11;
        if ( v9 == 73 )
          return;
        if ( v9 != 84 )
          break;
LABEL_10:
        PsTerminateSystemThread((unsigned int)a3, a4, -1073741823);
      }
      if ( v9 != 98 )
        break;
LABEL_11:
      DbgPrint(a3, "Execute '!cxr %p' to dump context\n", &Context);
      DbgBreakPoint();
    }
    if ( v9 == 105 )
      break;
    if ( v9 == 116 )
      goto LABEL_10;
  }
}