int __userpurge IoSetIoCompletion@<eax>(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, int a4@<esi>, void *IoCompletion, void *KeyContext, void *ApcContext, int IoStatus, unsigned int IoStatusInformation)
{
  int v9; // edx
  int v10; // ST0C_4
  _LIST_ENTRY *v11; // eax
  int v12; // edx

  if ( (unsigned __int8)dword_8004C5D0 > 1u )
  {
    DbgPrint(a3, "EX: Pageable code called at IRQL %d\n", (unsigned __int8)dword_8004C5D0);
    RtlAssert(v9, v10, a3, a4, "FALSE", "d:\\xbox-apr03\\private\\ntos\\io\\complete.c", 0x1B0u, 0);
  }
  v11 = (_LIST_ENTRY *)ExAllocatePoolWithTag(a1, a2, a4, 0x1Cu, 0x20706349u);
  if ( !v11 )
    return -1073741670;
  v11[1].Blink = (_LIST_ENTRY *)KeyContext;
  v11[2].Flink = (_LIST_ENTRY *)ApcContext;
  v11[2].Blink = (_LIST_ENTRY *)IoStatus;
  v11[1].Flink = (_LIST_ENTRY *)1;
  v11[3].Flink = (_LIST_ENTRY *)IoStatusInformation;
  KeInsertQueue(IoStatusInformation, v12, (_KQUEUE *)IoCompletion, v11);
  return 0;
}