#pragma once

#define MsgBosAssert(TEXT) MessageBoxA(nullptr, TEXT, "Error", MB_OK); assert(false);