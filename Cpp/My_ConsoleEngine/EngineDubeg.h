#pragma once

#define MsgAssert(TEXT) MessageBoxA(nullptr, TEXT, "Error", MB_OK); assert(false);