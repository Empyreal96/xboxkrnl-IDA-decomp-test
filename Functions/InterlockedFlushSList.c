__int64 __thiscall InterlockedFlushSList(_QWORD *this)
{
  __int64 result; // rax

  _EBP = this;
  result = *this;
  do
  {
    if ( !(_DWORD)result )
      break;
    __asm { cmpxchg8b qword ptr [ebp+0] }
  }
  while ( (_DWORD)result );
  return result;
}