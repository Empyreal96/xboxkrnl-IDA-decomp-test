// write access to const memory has been detected, the output may be wrong!
int __stdcall pan_dsp(char chan, char pan, char *patch)
{
  dsp_data = 0;
  return 1;
}