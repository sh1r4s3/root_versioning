/*
 * vim:et:sw=2:syntax=cpp
 *
 * Copyright (c) 2023 Nikita (sh1r4s3) Ermakov <sh1r4s3@mail.si-head.nl>
 * SPDX-License-Identifier: MIT
 */

#include "dst.h"

R__LOAD_LIBRARY(dst_cpp);

void save() {
  dst d("test.root", dst::IO::write);
  d.generate();
}

void load() {
  dst d("test.root", dst::IO::read);
  d.printDstVersion();
}

void test() {
  save();
  load();
}
