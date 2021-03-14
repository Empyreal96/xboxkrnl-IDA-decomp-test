_KPCR *__stdcall KeGetPcr()
{
  return (_KPCR *)&KiPCR;
}