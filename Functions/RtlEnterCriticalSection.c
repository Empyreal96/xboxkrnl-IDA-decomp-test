int *__stdcall RtlEnterCriticalSection(void *Object)
{
  _KTHREAD *v1; // ecx
  _DWORD *v2; // edx
  bool v3; // zf
  int *result; // eax

  v1 = thread;
  v2 = Object;
  v3 = *((_DWORD *)Object + 4) == -1;
  ++v2[4];
  if ( v3 )
    goto Ent10;
  if ( *((_KTHREAD **)Object + 6) != v1 )
  {
    result = KeWaitForSingleObject((int)v1, (int)Object, Object, 0, 0, 0, 0);
    v1 = thread;
    v2 = Object;
Ent10:
    v2[6] = v1;
    v2[5] = 1;
    return result;
  }
  ++*((_DWORD *)Object + 5);
  return result;
}