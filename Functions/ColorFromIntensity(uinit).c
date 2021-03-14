unsigned int __stdcall ColorFromIntensity(unsigned int intensity4bits)
{
  return (unsigned __int8)(unsigned __int64)((double)(204 * intensity4bits) * 0.06666667 + 0.5) | (((unsigned __int8)(unsigned __int64)((double)(204 * intensity4bits) * 0.06666667 + 0.5) | (((unsigned int)(unsigned __int64)((double)(204 * intensity4bits) * 0.06666667 + 0.5) | 0xFFFFFF00) << 8)) << 8);
}