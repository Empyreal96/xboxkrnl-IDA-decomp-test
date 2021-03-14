void __stdcall DumpTraceData(_STRING *MessageData)
{
  TraceDataBuffer[0].LongNumber = TraceDataBufferPosition;
  MessageData->Length = 4 * TraceDataBufferPosition;
  MessageData->Buffer = (char *)TraceDataBuffer;
  TraceDataBufferPosition = 1;
}