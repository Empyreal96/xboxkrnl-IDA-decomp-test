int __userpurge NtQueryMutant@<eax>(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, int a4@<esi>, void *MutantHandle, _MUTANT_BASIC_INFORMATION *MutantInformation)
{
  int v6; // edx
  int v7; // edi
  char v8; // bl
  int v9; // esi
  void *Mutant; // [esp+4h] [ebp-4h]
  bool OwnedByCaller_3; // [esp+13h] [ebp+Bh]

  v7 = ObReferenceObjectByHandle(a1, a2, a3, a4, MutantHandle, &ExMutantObjectType, &Mutant);
  if ( v7 >= 0 )
  {
    v8 = *((_BYTE *)Mutant + 28);
    v9 = *((_DWORD *)Mutant + 1);
    OwnedByCaller_3 = *((_DWORD *)Mutant + 6) == (_DWORD)thread;
    ObfDereferenceObject(Mutant, v6);
    MutantInformation->CurrentCount = v9;
    MutantInformation->AbandonedState = v8;
    MutantInformation->OwnedByCaller = OwnedByCaller_3;
  }
  return v7;
}