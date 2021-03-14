void __thiscall IdexCdRomFinishSpeedReduction(void *this)
{
  IdexChannelSetTimerPeriod(this, 100);
  unk_8005134C = IdexChannelRetryCurrentPacket;
  unk_8005135C = 3;
}