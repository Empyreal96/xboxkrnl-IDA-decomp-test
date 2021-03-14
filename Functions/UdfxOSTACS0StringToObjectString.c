int __fastcall UdfxOSTACS0StringToObjectString(int a1, int a2, char *OSTACS0String, unsigned int OSTACS0StringLength, _STRING *ObjectString)
{
  unsigned int v5; // ebx
  int *v6; // eax

  ObjectString->Buffer = 0;
  if ( !OSTACS0StringLength || *OSTACS0String != 8 )
    return -1073741811;
  v5 = OSTACS0StringLength - 1;
  v6 = ExAllocatePoolWithTag(a2, a1, (int)ObjectString, OSTACS0StringLength - 1, 0x67537855u);
  if ( !v6 )
    return -1073741670;
  ObjectString->Buffer = (char *)v6;
  ObjectString->Length = v5;
  ObjectString->MaximumLength = v5;
  qmemcpy(v6, OSTACS0String + 1, v5);
  return 0;
}