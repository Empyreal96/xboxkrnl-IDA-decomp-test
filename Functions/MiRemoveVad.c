void __stdcall MiRemoveVad(_MMVAD *Vad)
{
  if ( Vad == (_MMVAD *)MmVadFreeHint )
    MmVadFreeHint = MiGetPreviousNode((_MMADDRESS_NODE *)Vad);
  MiRemoveNode((_MMADDRESS_NODE *)Vad, &MmVadRoot);
  if ( MmVadHint == (_MMADDRESS_NODE *)Vad )
    MmVadHint = MmVadRoot;
}