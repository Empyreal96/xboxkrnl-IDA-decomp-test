void __fastcall IoFreeIrp(int a1, int a2, _IRP *Irp)
{
  char v3; // al
  bool v4; // sf
  unsigned __int8 v5; // of

  if ( Irp->Type != 6 )
  {
    RtlAssert(
      a2,
      a1,
      (int *)"d:\\xbox-apr03\\private\\ntos\\io\\iosubs.c",
      (int)Irp,
      "Irp->Type == IO_TYPE_IRP",
      "d:\\xbox-apr03\\private\\ntos\\io\\iosubs.c",
      0x7E7u,
      0);
    if ( Irp->Type != 6 )
      KeBugCheckEx(0x44u, (unsigned int)Irp, 0x7EAu, 0, 0);
  }
  if ( !IsListEmpty(&Irp->ThreadListEntry) )
    RtlAssert(
      a2,
      a1,
      (int *)"d:\\xbox-apr03\\private\\ntos\\io\\iosubs.c",
      (int)Irp,
      "IsListEmpty(&(Irp)->ThreadListEntry)",
      "d:\\xbox-apr03\\private\\ntos\\io\\iosubs.c",
      0x7EDu,
      0);
  v3 = Irp->CurrentLocation;
  v5 = __OFSUB__(v3, Irp->StackCount);
  v4 = (char)(v3 - Irp->StackCount) < 0;
  Irp->Type = 0;
  if ( v4 ^ v5 )
    RtlAssert(
      a2,
      a1,
      (int *)"d:\\xbox-apr03\\private\\ntos\\io\\iosubs.c",
      (int)Irp,
      "Irp->CurrentLocation >= Irp->StackCount",
      "d:\\xbox-apr03\\private\\ntos\\io\\iosubs.c",
      0x7F5u,
      0);
  ExFreePool(Irp);
}