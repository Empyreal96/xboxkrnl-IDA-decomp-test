void __stdcall KeInitializeDeviceQueue(_KDEVICE_QUEUE *DeviceQueue)
{
  DeviceQueue->Type = 20;
  DeviceQueue->Size = 12;
  InitializeListHead(&DeviceQueue->DeviceListHead);
  DeviceQueue->Busy = 0;
}