void __stdcall RemoveEntryList(_LIST_ENTRY *Entry)
{
  if ( !IsListEmpty(Entry) )
  {
    RemoveEntryList(Entry);
    InitializeListHead(Entry);
  }
}