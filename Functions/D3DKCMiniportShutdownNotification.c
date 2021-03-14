void __stdcall D3DK::CMiniport::ShutdownNotification(_HAL_SHUTDOWN_REGISTRATION *ShutdownRegistration)
{
  ShutdownRegistration[-27].ListEntry.Blink[40].Flink = 0;
  D3DK::CMiniport::ShutdownEngines((D3DK::CMiniport *)&ShutdownRegistration[-27].ListEntry.Blink);
}