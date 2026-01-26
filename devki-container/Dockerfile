FROM ubuntu:22.04

ENV DEBIAN_FRONTEND=noninteractive

# Basic Linux build tools
RUN apt-get update && apt-get install -y \
    build-essential \
    git \
    wget \
    curl \
    ca-certificates \
    sudo \
    && rm -rf /var/lib/apt/lists/*

# Copy the devkitPro pacman installer script from your repo
COPY install-devkitpro-pacman /tmp/install-devkitpro-pacman

# Make it executable and run it
RUN chmod +x /tmp/install-devkitpro-pacman && \
    /tmp/install-devkitpro-pacman

# Update devkitPro pacman and install 3DS toolchain
RUN dkp-pacman -Syu --noconfirm && \
    dkp-pacman -S --noconfirm 3ds-dev

# Environment variables
ENV DEVKITPRO=/opt/devkitpro
ENV DEVKITARM=${DEVKITPRO}/devkitARM
ENV PATH=${DEVKITPRO}/tools/bin:${DEVKITARM}/bin:$PATH

WORKDIR /workspace
