unsigned int __stdcall CMcpxCore::GetVoiceNotifierIndex(unsigned int dwVoiceIndex, unsigned int dwNotifierIndex)
{
  return dwNotifierIndex + 4 * dwVoiceIndex + 2;
}