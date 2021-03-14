void __userpurge MiInsertVad(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, _MMVAD *Vad)
{
  if ( Vad->EndingVpn < Vad->StartingVpn )
    RtlAssert(
      a1,
      a2,
      a3,
      (int)Vad,
      "Vad->EndingVpn >= Vad->StartingVpn",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\vadtree.c",
      0x2Au,
      0);
  MmVadHint = (_MMADDRESS_NODE *)Vad;
  if ( MmVadFreeHint && MmVadFreeHint->EndingVpn + 16 >= Vad->StartingVpn )
    MmVadFreeHint = (_MMADDRESS_NODE *)Vad;
  MiInsertNode((_MMADDRESS_NODE *)Vad, &MmVadRoot);
}