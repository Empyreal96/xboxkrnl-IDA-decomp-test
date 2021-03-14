unsigned int __stdcall ElapsedDaysToYears(unsigned int ElapsedDays)
{
  return (100 * ((-36524 * ((100 * (ElapsedDays % 0x23AB1) + 75) / 0x37BB49) + ElapsedDays % 0x23AB1) % 0x5B5) + 75)
       / 0x8EAD
       + 4
       * ((-36524 * ((100 * (ElapsedDays % 0x23AB1) + 75) / 0x37BB49) + ElapsedDays % 0x23AB1) / 0x5B5
        + 25 * ((100 * (ElapsedDays % 0x23AB1) + 75) / 0x37BB49 + 4 * (ElapsedDays / 0x23AB1)));
}