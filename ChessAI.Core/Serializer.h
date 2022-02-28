#include "BoardLookup.h"
#include <ostream>
#include <istream>

#pragma once
static class Serializer
{
public:

	/// <summary>
	/// Stores BoardLookup data to the underlying stream in its COMPRESSED format
	/// </summary>
	static std::ostream& Serialize(BoardLookup* lookup, std::ostream& stream);

	/// <summary>
	/// Creates BoardLookup instance on the heap by DECOMPRESSING it
	/// </summary>
	static BoardLookup* Deserialize(std::istream& stream);

};

