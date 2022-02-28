#include "Serializer.h"

std::ostream& Serializer::Serialize(BoardLookup* lookup, std::ostream& stream)
{
	return lookup->Serialize(stream);
}

BoardLookup* Serializer::Deserialize(std::istream& stream)
{
	return new BoardLookup(stream);
}