void __fastcall ExpDeleteMutant(int a1, int a2, void *Mutant)
{
  KeReleaseMutant(a1, a2, (_KMUTANT *)Mutant, 1, 1, 0);
}