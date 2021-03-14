int __thiscall RtlFindFirstSetRightMember(void *this)
{
  int result; // eax

  _BitScanForward((unsigned int *)&result, (unsigned int)this);
  return result;
}