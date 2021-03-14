void __fastcall KiInitializeInterruptUsbHack(int a1, int a2, void *ServiceContext, char ApplyHack)
{
  int v4; // edx
  unsigned int v5; // eax

  if ( ApplyHack == 1 && !(XboxHardwareInfo.Flags & 9) )
  {
    DummyEndpoint[0].PhysicalAddress = MmGetPhysicalAddress(a2, (int *)DummyEndpoint, DummyEndpoint);
    v5 = MmGetPhysicalAddress(v4, (int *)DummyEndpoint, &DummyEndpoint[1]);
    DummyEndpoint[1].HcEndpointDescriptor.Control.ul = DummyEndpoint[1].HcEndpointDescriptor.Control.ul & 0xF808FFFF | 0x80000;
    DummyEndpoint[1].PhysicalAddress = v5;
    DummyEndpoint[0].HcEndpointDescriptor.NextED = v5;
    DummyEndpoint[0].HcEndpointDescriptor.Control.ul = DummyEndpoint[0].HcEndpointDescriptor.Control.ul & 0xF808FFFF | 0x80000;
    DummyEndpoint[0].Next = &DummyEndpoint[1];
    *((_DWORD *)ServiceContext + 259) = DummyEndpoint;
    *(_DWORD *)(*(_DWORD *)ServiceContext + 32) = DummyEndpoint[0].PhysicalAddress;
  }
}