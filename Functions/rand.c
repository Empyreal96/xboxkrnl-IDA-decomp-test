// write access to const memory has been detected, the output may be wrong!
int __cdecl rand()
{
  holdrand = 214013 * holdrand + 2531011;
  return HIWORD(holdrand) & 0x7FFF;
}