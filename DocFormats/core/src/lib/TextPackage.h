// This file is part of the Corinthia project (http://corinthia.io).
//
// See the COPYRIGHT.txt file distributed with this work for
// information regarding copyright ownership.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include <DocFormats/DFError.h>
#include "DFHashTable.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                //
//                                           TextPackage                                          //
//                                                                                                //
////////////////////////////////////////////////////////////////////////////////////////////////////

typedef struct TextPackage TextPackage;

struct TextPackage {
    size_t retainCount;
    char **keys;
    size_t nkeys;
    DFHashTable *items;
};

TextPackage *TextPackageNewWithFile(const char *filename, DFError **error);
TextPackage *TextPackageNewWithString(const char *string, const char *path, DFError **error);
TextPackage *TextPackageRetain(TextPackage *package);
void TextPackageRelease(TextPackage *package);
