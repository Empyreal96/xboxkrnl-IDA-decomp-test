int __userpurge NtMakeTemporaryObject@<eax>(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, int a4@<esi>, void *Handle)
{
  int v5; // esi
  int v6; // edx

  v5 = ObReferenceObjectByHandle(a1, a2, a3, a4, Handle, 0, &Handle);
  if ( v5 >= 0 )
  {
    ObMakeTemporaryObject(a3, v5, Handle);
    ObfDereferenceObject(Handle, v6);
  }
  return v5;
}