int *__stdcall ObReferenceObjectByName(_STRING *ObjectName, unsigned int Attributes, _OBJECT_TYPE *ObjectType, void *ParseContext, void **ReturnedObject)
{
  return ObpReferenceObjectByName(0, ObjectName, Attributes, ObjectType, ParseContext, ReturnedObject);
}