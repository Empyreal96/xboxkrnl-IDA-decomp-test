signed int __stdcall BenalohEstimateQuotient(unsigned int a1, unsigned int a2, unsigned int a3)
{
  signed int result; // eax

  if ( a1 >= a3 )
    result = -1;
  else
    result = __PAIR__(a1, a2) / a3;
  return result;
}