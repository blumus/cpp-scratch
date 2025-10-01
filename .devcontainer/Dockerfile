FROM mcr.microsoft.com/devcontainers/base:ubuntu-22.04

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y --no-install-recommends \
    build-essential \
    cmake \
    ninja-build \
    gdb \
    clang \
    clangd \
    lldb \
    git \
    pkg-config \
    ccache \
  && rm -rf /var/lib/apt/lists/*

# Default to GCC for builds; Ninja improves CMake performance
ENV CC=gcc CXX=g++ \
    CMAKE_GENERATOR=Ninja


