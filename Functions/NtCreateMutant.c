int __thiscall NtCreateMutant(void *this, void **MutantHandle, _OBJECT_ATTRIBUTES *ObjectAttributes, char InitialOwner)
{
  int result; // eax
  void *Mutant; // [esp+0h] [ebp-4h]

  Mutant = this;
  result = ObCreateObject(&ExMutantObjectType, ObjectAttributes, 0x20u, &Mutant);
  if ( result >= 0 )
  {
    KeInitializeMutant((_KMUTANT *)Mutant, InitialOwner);
    result = ObInsertObject(Mutant, ObjectAttributes, 0, MutantHandle);
  }
  return result;
}