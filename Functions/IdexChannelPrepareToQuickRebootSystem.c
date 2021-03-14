void __usercall IdexChannelPrepareToQuickRebootSystem(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, int a4@<esi>)
{
  if ( Irp )
    RtlAssert(
      a1,
      a2,
      a3,
      a4,
      "(IdexChannelObject.CurrentIrp == NULL)",
      "d:\\xbox-apr03\\private\\ntos\\idex\\channel.c",
      0x7ABu,
      "I/O still in progress when reboot was requested\n");
  IdexChannelQuickRebooting = 1;
}