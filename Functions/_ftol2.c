__int64 __cdecl _ftol2()
{
  unsigned __int16 oldcw; // ST08_2
  unsigned __int16 newcw; // ST0C_2
  unsigned int result[2]; // ST00_8

  __asm { fstcw   [ebp+oldcw] }
  newcw = oldcw | 0xC00;
  __asm
  {
    fldcw   [ebp+newcw]
    fistp   qword ptr [ebp+result]
    fldcw   [ebp+oldcw]
  }
  return *(_QWORD *)result;
}