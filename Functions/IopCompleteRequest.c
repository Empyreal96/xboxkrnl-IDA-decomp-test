void __fastcall IopCompleteRequest(int a1, int a2, _KAPC *Apc, void (__stdcall **NormalRoutine)(void *, void *, void *), void **NormalContext, void **SystemArgument1, void **SystemArgument2)
{
  void (__stdcall **v7)(_KAPC *); // esi
  char *v8; // edi
  int v9; // ecx
  int v10; // edx
  char v11; // al
  void (__stdcall *v12)(_KAPC *); // eax
  _KEVENT *v13; // eax
  void (__stdcall *v14)(_KAPC *); // ecx
  int *v15; // edx
  int v16; // ecx
  int v17; // eax
  int v18; // ecx
  _KEVENT *v19; // eax
  int *v20; // edx
  int v21; // ecx
  void (__stdcall *v22)(void *, void *, void *); // eax
  int v23; // edx
  int v24; // ecx
  int v25; // edx
  void (__stdcall *key)(_KAPC *); // [esp+Ch] [ebp-8h]
  _ETHREAD *thread; // [esp+10h] [ebp-4h]
  char createOperation_3; // [esp+1Fh] [ebp+Bh]
  _KQUEUE *port; // [esp+28h] [ebp+14h]

  v7 = &Apc[-2].RundownRoutine;
  thread = (_ETHREAD *)::thread;
  v8 = (char *)*SystemArgument1;
  if ( Apc[-2].SystemArgument2 == (void *)-1 )
    RtlAssert(
      a2,
      a1,
      (int *)v8,
      (int)v7,
      "irp->IoStatus.Status != 0xffffffff",
      "d:\\xbox-apr03\\private\\ntos\\io\\internal.c",
      0x107u,
      0);
  v9 = (int)v7[4];
  v10 = (unsigned int)v7[4] & 0xC0000000;
  if ( v10 == -1073741824 )
  {
    v11 = *((_BYTE *)v7 + 26);
    if ( !v11 )
      goto LABEL_16;
    if ( (_BYTE)v7[1] & 4 || v8 && (v10 = v8[3] & 1) != 0 )
    {
      if ( v11 )
      {
        if ( !v8 )
        {
LABEL_19:
          v14 = v7[8];
          if ( v14 && v8 && !((_BYTE)v7[1] & 4) )
            ObfDereferenceObject(v14, v10);
          v15 = (int *)v7[3];
          v16 = (int)v7[2];
          *v15 = v16;
          *(_DWORD *)(v16 + 4) = v15;
          v7[3] = (void (__stdcall *)(_KAPC *))(v7 + 2);
          v7[2] = (void (__stdcall *)(_KAPC *))(v7 + 2);
          IoFreeIrp(v16, (int)v15, (_IRP *)v7);
          return;
        }
        if ( (_BYTE)v7[1] & 4 )
        {
          v12 = v7[7];
          *(_DWORD *)v12 = v7[4];
          v9 = (int)v7[5];
          *((_DWORD *)v12 + 1) = v9;
          v13 = (_KEVENT *)v7[8];
          if ( v13 )
          {
LABEL_15:
            KeSetEvent(v9, v10, v13, 0, 0);
            goto LABEL_16;
          }
        }
        else
        {
          *((_DWORD *)v8 + 4) = v9;
        }
        v13 = (_KEVENT *)(v8 + 56);
        goto LABEL_15;
      }
LABEL_16:
      if ( v8 && !((_BYTE)v7[1] & 8) )
        ObfDereferenceObject(v8, v10);
      goto LABEL_19;
    }
  }
  port = 0;
  createOperation_3 = 0;
  if ( v8 )
  {
    v17 = *((_DWORD *)v8 + 8);
    if ( v17 )
    {
      port = *(_KQUEUE **)v17;
      key = *(void (__stdcall **)(_KAPC *))(v17 + 4);
    }
  }
  *((_DWORD *)v7[7] + 1) = v7[5];
  v18 = (int)v7[4];
  *(_DWORD *)v7[7] = v18;
  v19 = (_KEVENT *)v7[8];
  if ( v19 )
  {
    KeSetEvent(v18, v10, v19, 0, 0);
    if ( v8 )
    {
      if ( !((_BYTE)v7[1] & 4) )
        ObfDereferenceObject(v7[8], v10);
      if ( !(v8[3] & 1) || *((_BYTE *)v7 + 5) & 1 )
        goto LABEL_36;
      goto LABEL_35;
    }
  }
  else if ( v8 )
  {
LABEL_35:
    KeSetEvent(v18, v10, (_KEVENT *)(v8 + 56), 0, 0);
    *((_DWORD *)v8 + 4) = v7[4];
LABEL_36:
    if ( (_BYTE)v7[1] & 8 )
    {
      createOperation_3 = 1;
      v7[10] = 0;
    }
    goto LABEL_38;
  }
LABEL_38:
  v20 = (int *)v7[3];
  v21 = (int)v7[2];
  *v20 = v21;
  *(_DWORD *)(v21 + 4) = v20;
  v7[3] = (void (__stdcall *)(_KAPC *))(v7 + 2);
  v7[2] = (void (__stdcall *)(_KAPC *))(v7 + 2);
  v22 = (void (__stdcall *)(void *, void *, void *))v7[10];
  if ( v22 )
  {
    KeInitializeApc(
      (_KAPC *)(v7 + 15),
      &thread->Tcb,
      (void (__stdcall *)(_KAPC *, void (__stdcall **)(void *, void *, void *), void **, void **, void **))IopUserCompletion,
      (void (__stdcall *)(_KAPC *))IopUserRundown,
      v22,
      (char *)v22 == (char *)NtUserIoApcDispatcher,
      v7[11]);
    KeInsertQueueApc(v24, v23, (_KAPC *)(v7 + 15), v7[7], 0, 2);
  }
  else if ( port && v7[11] )
  {
    v7[15] = key;
    v7[23] = 0;
    KeInsertQueue(v21, (int)v20, port, (_LIST_ENTRY *)(v7 + 21));
  }
  else
  {
    IoFreeIrp(v21, (int)v20, (_IRP *)v7);
  }
  if ( v8 && !createOperation_3 )
    ObfDereferenceObject(v8, v25);
}