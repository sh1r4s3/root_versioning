/*
 * vim:et:sw=2:syntax=cpp
 *
 * Copyright (c) 2023 Nikita (sh1r4s3) Ermakov <sh1r4s3@mail.si-head.nl>
 * SPDX-License-Identifier: MIT
 */
#include "dst.h"

ClassImp(teletubbies);

#define STR(x) #x

dst::dst(const std::string path, IO io)
  : mFile(new TFile(path.c_str(), io == IO::write ? "RECREATE" : "READ"))
  , mIO(io) {

  if (io == IO::write) {
    mTree.reset(new TTree("dst", "dst"));
    mEvents = new TClonesArray("teletubbies", 1 << 10);
    mTree->Branch("teletubbies", mEvents, 1 << 20);
  }
}

dst::~dst() {
  if (mIO == IO::write) {
    mTree->Write();
    delete mEvents;
  }
}

void dst::generate() {
  if (mIO != IO::write) return;

  new(mEvents->operator[](mN++)) teletubbies();
  mTree->Fill();
}
