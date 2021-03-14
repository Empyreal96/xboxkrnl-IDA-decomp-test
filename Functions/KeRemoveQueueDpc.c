char __userpurge KeRemoveQueueDpc@<al>(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, _KDPC *Dpc)
{
  char result; // al

  if ( Dpc->Type != 19 )
    RtlAssert(a1, a2, a3, (int)Dpc, "(Dpc)->Type == DpcObject", "d:\\xbox-apr03\\private\\ntos\\ke\\dpcobj.c", 0xD0u, 0);
  _disable();
  result = Dpc->Inserted;
  if ( result )
  {
    RemoveEntryList(&Dpc->DpcListEntry);
    Dpc->Inserted = 0;
  }
  _enable();
  return result;
}