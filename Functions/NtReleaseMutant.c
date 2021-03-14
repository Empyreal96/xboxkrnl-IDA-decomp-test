int __userpurge NtReleaseMutant@<eax>(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, int a4@<esi>, void *MutantHandle, int *PreviousCount)
{
  int v6; // edx
  int v7; // ecx
  int v8; // ebx
  int v9; // esi
  int v10; // edx
  void *Mutant; // [esp+14h] [ebp-1Ch]
  CPPEH_RECORD ms_exc; // [esp+18h] [ebp-18h]

  v8 = ObReferenceObjectByHandle(a1, a2, a3, a4, MutantHandle, &ExMutantObjectType, &Mutant);
  if ( v8 >= 0 )
  {
    ms_exc.registration.TryLevel = 0;
    v9 = KeReleaseMutant(v7, v6, (_KMUTANT *)Mutant, 1, 0, 0);
    ObfDereferenceObject(Mutant, v10);
    if ( PreviousCount )
      *PreviousCount = v9;
    ms_exc.registration.TryLevel = -1;
  }
  return v8;
}